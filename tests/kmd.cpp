#include "kmd.h"

namespace Crystal
{
    namespace KMD
    {
#pragma region kmd_ring.h

        ////////////////////////////////////////////////////////////////////////////////
        TEST_F( RenderRingTest, Create )
        {
            RenderRing* pRing = RenderRing::Create( 4 * sizeof(uint32_t) );

            ASSERT_EQ( pRing->Capacity(), 4 );
            ASSERT_EQ( pRing->Size(), 4 );
            ASSERT_EQ( pRing->Full(), false );

            RenderRing::Destroy( pRing );
        }

        ////////////////////////////////////////////////////////////////////////////////
        TEST_F( RenderRingTest, Put )
        {
            RenderRing* pRing = RenderRing::Create( 4 * sizeof(uint32_t) );

            pRing->Put( 1 );
            pRing->Put( 2 );
            pRing->Put( 3 );
            pRing->Put( 4 );

            ASSERT_EQ( pRing->Full(), true );

            pRing->Put( 5 );

            ASSERT_EQ( pRing->Full(), true );

            pRing->Put( 6 );

            ASSERT_EQ( pRing->Full(), true );

            RenderRing::Destroy( pRing );
        }

        ////////////////////////////////////////////////////////////////////////////////
        TEST_F( RenderRingTest, Get )
        {
            RenderRing* pRing = RenderRing::Create( 4 * sizeof(uint32_t) );

            ASSERT_EQ( pRing->Get(), 0 );

            pRing->Put( 1 );
            pRing->Put( 2 );
            pRing->Put( 3 );

            ASSERT_EQ( pRing->Get(), 1 );
            ASSERT_EQ( pRing->Get(), 2 );
            ASSERT_EQ( pRing->Get(), 3 );
            ASSERT_EQ( pRing->Empty(), true );

            RenderRing::Destroy( pRing );
        }

        ////////////////////////////////////////////////////////////////////////////////
        TEST_F( RenderRingTest, Size )
        {
            RenderRing* pRing = RenderRing::Create( 4 * sizeof( uint32_t ) );

            ASSERT_EQ( pRing->Size(), 4 );

            pRing->Put( 1 );

            ASSERT_EQ( pRing->Size(), 1 );

            pRing->Put( 2 );
            pRing->Put( 3 );

            ASSERT_EQ( pRing->Size(), 3 );

            pRing->Put( 4 );

            ASSERT_EQ( pRing->Size(), 4 );

            RenderRing::Destroy( pRing );
        }

        ////////////////////////////////////////////////////////////////////////////////
        TEST_F( RenderRingTest, ProducerConsumer )
        {
            RenderRing* pRing = RenderRing::Create( 4 * sizeof( uint32_t ) );

            std::atomic<bool> producer_done = false;

            std::thread producer( [&]() {
                for( uint32_t i = 1; i <= 5000; i++ )
                {
                    while( pRing->Full() ) Sleep( 1 );
                    pRing->Put( i );
                }
                producer_done = true;
            } );

            std::thread consumer( [&]() {
                uint32_t value_prev = 0;

                while( !producer_done )
                {
                    if( !pRing->Empty() )
                    {
                        uint32_t value_curr = pRing->Get();
                        ASSERT_EQ( value_curr, value_prev + 1 );
                        value_prev = value_curr;
                    }
                }
            } );

            producer.join();
            consumer.join();

            RenderRing::Destroy( pRing );
        }

        ////////////////////////////////////////////////////////////////////////////////
        TEST_F( RenderRingTest, Checkout )
        {
            RenderRing* pRing = RenderRing::Create( 4 * sizeof( uint32_t ) );

            uint32_t* pBuffer = nullptr;
            uint32_t bufferSize = 0;

            pBuffer = pRing->Checkout();
            bufferSize = pRing->CheckoutSize();

            ASSERT_EQ( pRing->Capacity(), 4 );
            ASSERT_EQ( pRing->Full(), false );
            ASSERT_EQ( pRing->Empty(), true );
            ASSERT_EQ( pRing->Size(), 4 );
            ASSERT_EQ( bufferSize, 4 );

            pBuffer[0] = 1;
            pBuffer[1] = 2;

            pRing->Commit( 2 );

            ASSERT_EQ( pRing->Empty(), false );
            ASSERT_EQ( pRing->Size(), 2 );
            ASSERT_EQ( pRing->Full(), false );

            pRing->Put( 3 );

            ASSERT_EQ( pRing->Get(), 1 );
            ASSERT_EQ( pRing->Empty(), false );
            ASSERT_EQ( pRing->Size(), 2 );
            ASSERT_EQ( pRing->Full(), false );

            pBuffer = pRing->Checkout();
            bufferSize = pRing->CheckoutSize();
            ASSERT_EQ( bufferSize, 1 );
            
            pBuffer[0] = 4;

            pRing->Commit( 1 );
            pRing->Put( 5 );

            ASSERT_EQ( pRing->Full(), true );

            RenderRing::Destroy( pRing );
        }

        ////////////////////////////////////////////////////////////////////////////////
        TEST_F( RenderRingTest, Checkout_Overflow )
        {
            RenderRing* pRing = RenderRing::Create( 8 * sizeof( uint32_t ) );

            uint32_t* pBuffer = nullptr;
            uint32_t bufferSize = 0;
            uint32_t minRequired = 4;

            pRing->Put( 1 );
            pRing->Put( 2 );
            pRing->Put( 3 );
            pRing->Put( 4 );
            pRing->Put( 5 );

            bufferSize = pRing->CheckoutSize();
            if( bufferSize < minRequired )
            {
                while( pRing->Tail() == 0 ) pRing->Get();
                pRing->ResetHead();
                pBuffer = pRing->Checkout();
                do 
                {
                    bufferSize = pRing->CheckoutSize();
                    pRing->Get();
                } while( bufferSize < minRequired );
            }

            ASSERT_GE( bufferSize, minRequired );

            RenderRing::Destroy( pRing );
        }

#pragma endregion

    }
}
