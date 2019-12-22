#include "kmd.h"

namespace Crystal
{
    namespace KMD
    {
#pragma region kmd_ring.h

        ////////////////////////////////////////////////////////////////////////////////
        TEST_F( RenderRingTest, Create )
        {
            RenderRing* pRing = RenderRing::Create( 4, 0 );

            ASSERT_EQ( pRing->Capacity(), 4 );
            ASSERT_EQ( pRing->Size(), 4 );
            ASSERT_EQ( pRing->Full(), false );

            RenderRing::Destroy( pRing );
        }

        ////////////////////////////////////////////////////////////////////////////////
        TEST_F( RenderRingTest, Put )
        {
            RenderRing* pRing = RenderRing::Create( 4, 0 );

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
            RenderRing* pRing = RenderRing::Create( 4, 0 );

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
        TEST_F( RenderRingTest, ProducerConsumer )
        {
            RenderRing* pRing = RenderRing::Create( 4, 0 );

            std::atomic<bool> producer_done = false;

            std::thread producer( [&]() {
                for( uint32_t i = 1; i <= 10000; i++ )
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

#pragma endregion

    }
}
