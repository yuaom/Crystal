#include "kmd.h"

namespace Crystal
{
    namespace KMD
    {
#pragma region kmd_ring.h

        ////////////////////////////////////////////////////////////////////////////////
        TEST_F( RenderRingTest, Create )
        {
            RenderRing* pRing = RenderRing::Create( 32 );

            ASSERT_EQ( pRing->GetSize(), 32 );
            ASSERT_EQ( pRing->GetHead(), pRing->GetTail() );
            ASSERT_EQ( pRing->GetWriteDistance(), pRing->GetSize() );

            RenderRing::Destroy( pRing );
        }

        ////////////////////////////////////////////////////////////////////////////////
        TEST_F( RenderRingTest, Advance )
        {
            RenderRing* pRing = RenderRing::Create( 24 );

            pRing->Advance( 0, 8 );

            ASSERT_EQ( pRing->GetSize(), 24);
            ASSERT_EQ( pRing->GetHead() - 8, pRing->GetTail() );
            ASSERT_EQ( pRing->GetWriteDistance(), pRing->GetSize() - 8 );

            pRing->Advance( 0, 8 );

            ASSERT_EQ( pRing->GetSize(), 24 );
            ASSERT_EQ( pRing->GetHead() - 16, pRing->GetTail() );
            ASSERT_EQ( pRing->GetWriteDistance(), pRing->GetSize() - 16 );

            pRing->Advance( 0, 8 );

            ASSERT_EQ( pRing->GetSize(), 24 );
            ASSERT_EQ( pRing->GetHead(), pRing->GetEnd() );
            ASSERT_EQ( pRing->GetWriteDistance(), 0 );

            RenderRing::Destroy( pRing );
        }

#pragma endregion

    }
}
