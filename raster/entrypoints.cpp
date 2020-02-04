#include "pch.h"
#include "entrypoints.h"
#include "raster_context.h"

////////////////////////////////////////////////////////////////////////////////
bool OpenRasterizer( RASTERARGS_OPENRASTERIZER* pOpenRasterizer )
{
    pOpenRasterizer->pRasterFuncs->pfnCreateContext         = Crystal::Raster::CreateContext;
    pOpenRasterizer->pRasterFuncs->pfnGetNextCommandBuffer  = Crystal::Raster::GetNextCommandBuffer;
    pOpenRasterizer->pRasterFuncs->pfnRingDoorbell          = Crystal::Raster::RingDoorbell;

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
        void GetNextCommandBuffer(
            RASTERCONTEXT_HANDLE handle,
            void* &pAddress,
            uint32_t& size )
        {
            Context* pContext = Context::FromHandle( handle );

            RenderRing* pRenderRings = pContext->GetRing();
            pRenderRings->AdvanceWriteHead();

            Ring::ptr_t& pRing = pRenderRings->GetWrite();

            pAddress = pRing->GetAddress();
            size     = pRing->GetMaxSize();
        }

        ////////////////////////////////////////////////////////////////////////////////
        void RingDoorbell( 
            RASTERCONTEXT_HANDLE handle,
            uint32_t size )
        {
            Context* pContext = Context::FromHandle( handle );

            RenderRing* pRenderRings = pContext->GetRing();

            pRenderRings->GetWrite()->SetTail( size );
            pRenderRings->WriteComplete();
        }
    }
}