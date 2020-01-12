#include "pch.h"
#include "kmd_context.h"

////////////////////////////////////////////////////////////////////////////////
EXTERN_C NTSTATUS APIENTRY D3DKMTRender( D3DKMT_RENDER* pRender )
{
    LOG_DLL_ENTRY;

    Crystal::KMD::Context* pContext = Crystal::KMD::Context::FromHandle( pRender->hContext );

    // Commit the written DMA commands
    pContext->RingDoorbell( 
        pRender->CommandLength );

    // Retrieve the next DMA buffer
    pContext->GetDmaBuffer( 
        pRender->pNewCommandBuffer, 
        pRender->NewCommandBufferSize );

    return STATUS_SUCCESS;
}