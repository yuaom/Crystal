#include "tests.h"

namespace Crystal
{
    namespace KMT
    {
        namespace Tests
        {
            ////////////////////////////////////////////////////////////////////////////////
            TEST( Resource, CalculateSize )
            {
                KmtHandleManager::OnDllProcessAttach();

                D3DKMT_CREATEALLOCATION params = { 0 };

                Resource* pResource = Resource::Create( &params );

                ASSERT_NE( pResource, nullptr );

                KmtHandleManager::OnDllProcessDetach();
            }
        }
    }
}
