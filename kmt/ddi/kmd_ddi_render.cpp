#include "pch.h"
#include "../objects/kmd_context.h"
#include "cmds/cmds.h"

////////////////////////////////////////////////////////////////////////////////
EXTERN_C NTSTATUS APIENTRY D3DKMTRender( D3DKMT_RENDER* pRender )
{
    LOG_DLL_ENTRY;

    Crystal::KMD::Context* pContext = Crystal::KMD::Context::FromHandle( pRender->hContext );

    // Render Epilog
    Crystal::KMD::Context::RenderEpilog epilog;

    epilog.fenceUpdate.Address  = &pContext->m_RenderFenceGPU;
    epilog.fenceUpdate.Value    = ++pContext->m_RenderFenceCPU;

    byte* pCommandBuffer = 
        reinterpret_cast<byte*>( pContext->m_pCurrentCommandBuffer ) + 
        pRender->CommandLength;

    memcpy( pCommandBuffer, &epilog, sizeof( Crystal::KMD::Context::RenderEpilog ) );
    pRender->CommandLength += sizeof( Crystal::KMD::Context::RenderEpilog );

    // Commit the written command buffer commands
    pContext->RingDoorbell( 
        pRender->CommandLength );

    // Retrieve the next command buffer
    pContext->GetNextCommandBuffer( 
        pRender->pNewCommandBuffer, 
        pRender->NewCommandBufferSize );

    return STATUS_SUCCESS;
}