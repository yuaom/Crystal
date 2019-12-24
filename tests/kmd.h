#pragma once
#include <gtest/gtest.h>
#include "pch.h"
#include "kmd_handles.h"

#pragma region Fixtures

namespace Crystal
{
    namespace KMD
    {
        class KmdTest : public ::testing::Test {
        protected:
            void SetUp() override
            {
                KmtHandleManager::OnDllProcessAttach();
            }

            void TearDown() override
            {
                KmtHandleManager::OnDllProcessDetach();
            }
        };

        class RenderRingTest : public KmdTest {};
    }
}

#pragma endregion