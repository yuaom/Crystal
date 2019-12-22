#include "pch.h"
#include "kmd_context.h"
#include "kmd_ring.h"

////////////////////////////////////////////////////////////////////////////////
EXTERN_C NTSTATUS APIENTRY D3DKMTRender( D3DKMT_RENDER* pRender )
{
    LOG_DLL_ENTRY;

    Crystal::KMD::Context* pContext = Crystal::KMD::Context::FromHandle( pRender->hContext );
    Crystal::KMD::RenderRing* pRenderRing = pContext->GetRing();

    assert( pRender->CommandLength % sizeof( uint32_t ) == 0 );
    uint32_t commands = pRender->CommandLength / sizeof( uint32_t );

    // Submit the work
    pRenderRing->Commit( commands );

    // Checkout the next command buffer span
    pRender->pNewCommandBuffer      = reinterpret_cast<void*>( pRenderRing->Checkout() );
    pRender->NewCommandBufferSize   = pRenderRing->CheckoutSize();

    uint32_t minimumSize = 32;

    if( pRender->NewCommandBufferSize < minimumSize )
    {
        // Wait for consumer to pick up work
        while( pRenderRing->Tail() == 0 ) Sleep( 10 );

        // Reset the head
        pRenderRing->ResetHead();

        // Retrieve the new check-out
        pRender->pNewCommandBuffer = reinterpret_cast<void*>( pRenderRing->Checkout() );

        // Loop until the tail advances far enough to meet the minimum requirement
        while( pRender->NewCommandBufferSize < minimumSize )
        {
            pRender->NewCommandBufferSize = pRenderRing->CheckoutSize();
            Sleep( 10 );
        }
    }

    // Convert size into bytes
    pRender->NewCommandBufferSize *= sizeof( uint32_t );

    return STATUS_SUCCESS;
}