#include "pch.h"
#include "objects/kmt_resource.h"

////////////////////////////////////////////////////////////////////////////////
EXTERN_C NTSTATUS APIENTRY D3DKMTCreateAllocation( D3DKMT_CREATEALLOCATION* pCreateAllocation )
{
    LOG_DLL_ENTRY;

    Crystal::KMT::Resource::Create( pCreateAllocation );

    return STATUS_SUCCESS;
}

////////////////////////////////////////////////////////////////////////////////
EXTERN_C NTSTATUS APIENTRY D3DKMTDestroyAllocation( CONST D3DKMT_DESTROYALLOCATION* pDestroyAllocation )
{
    LOG_DLL_ENTRY;

    Crystal::KMT::Resource::Destroy( pDestroyAllocation->hResource );

    return STATUS_SUCCESS;
}