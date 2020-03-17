#include "tests.h"

namespace Crystal
{
    namespace UMD
    {
        namespace Tests
        {
            ////////////////////////////////////////////////////////////////////////////////
            TEST( Resource, CalculateSize )
            {
                D3D11DDIARG_CREATERESOURCE params = { 0 };

                size_t size = Resource::CalculateSize( &params );

                ASSERT_NE( size, 0 );
            }
        }
    }
}
