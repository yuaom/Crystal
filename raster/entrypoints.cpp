#include "pch.h"
#include "entrypoints.h"
#include "raster_context.h"

////////////////////////////////////////////////////////////////////////////////
bool OpenRasterizer( RASTERARGS_OPENRASTERIZER* pOpenRasterizer )
{
    pOpenRasterizer->pRasterFuncs->pfnCreateContext     = Crystal::Raster::CreateContext;
    pOpenRasterizer->pRasterFuncs->pfnGetRingWriteInfo  = Crystal::Raster::GetRingWriteInfo;

    return true;
}

namespace Crystal
{
    namespace Raster
    {
        ////////////////////////////////////////////////////////////////////////////////
        bool CreateContext( RASTERARGS_CREATECONTEXT* pCreateContextArgs )
        {
            return Context::Create( pCreateContextArgs );
        }

        ////////////////////////////////////////////////////////////////////////////////
        void GetRingWriteInfo(
            RASTERCONTEXT_HANDLE handle,
            void* &pAddress,
            uint32_t& size )
        {
            Context* pContext = Context::FromHandle( handle );

            pAddress = reinterpret_cast<void*>( pContext->GetRing()->Checkout() );
            size     = pContext->GetRing()->CheckoutSize();
        }
    }
}