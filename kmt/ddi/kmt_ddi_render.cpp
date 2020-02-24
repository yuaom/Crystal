#include "pch.h"
#include "../objects/kmt_context.h"
#include "cmds/cmds.h"

////////////////////////////////////////////////////////////////////////////////
EXTERN_C NTSTATUS APIENTRY D3DKMTRender( D3DKMT_RENDER* pRender )
{
    LOG_DLL_ENTRY;

    Crystal::KMT::Context* pContext = Crystal::KMT::Context::FromHandle( pRender->hContext );

    // Render Epilog
    Crystal::KMT::Context::RenderEpilog epilog;

    epilog.fenceUpdate.Address  = &pContext->m_RenderFenceGPU;
    epilog.fenceUpdate.Value    = ++pContext->m_RenderFenceCPU;

    byte* pCommandBuffer = 
        reinterpret_cast<byte*>( pContext->m_pCurrentCommandBuffer ) + 
        pRender->CommandLength;

    memcpy( pCommandBuffer, &epilog, sizeof( Crystal::KMT::Context::RenderEpilog ) );
    pRender->CommandLength += sizeof( Crystal::KMT::Context::RenderEpilog );

    // Commit the written command buffer commands
    pContext->RingDoorbell( 
        pRender->CommandLength );

    // Retrieve the next command buffer
    pContext->GetNextCommandBuffer( 
        pRender->pNewCommandBuffer, 
        pRender->NewCommandBufferSize );

    return STATUS_SUCCESS;
}