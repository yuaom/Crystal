#include "pch.h"
#include "kmd_context.h"

////////////////////////////////////////////////////////////////////////////////
EXTERN_C NTSTATUS APIENTRY D3DKMTRender( D3DKMT_RENDER* pRender )
{
    LOG_DLL_ENTRY;

    Crystal::KMD::Context* pContext = Crystal::KMD::Context::FromHandle( pRender->hContext );

    //pContext->GetRing()->AdvanceHead( pRender->CommandLength );

    //pRender->pNewCommandBuffer      = reinterpret_cast<void*>( pContext->GetRing()->GetNextCommandBufferAddress() );
    //pRender->NewCommandBufferSize   = pContext->GetRing()->GetNextCommandBufferSize();

    return STATUS_SUCCESS;
}