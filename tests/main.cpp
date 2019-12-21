#include <gtest/gtest.h>
#include "pch.h"
#include "kmd_handles.h"
#include "kmd_ring.h"

class KmdTest : public ::testing::Test {
protected:
    void SetUp() override
    {
        Crystal::KMD::KmtHandleManager::OnDllProcessAttach();
    }

    void TearDown() override
    {
        Crystal::KMD::KmtHandleManager::OnDllProcessDetach();
    }
};

class RenderRingTest : public KmdTest {};

TEST_F( RenderRingTest, Create ) {
    Crystal::KMD::RenderRing* pRing = Crystal::KMD::RenderRing::Create( 32 );

    ASSERT_EQ( pRing->GetSize(), 32 );
}