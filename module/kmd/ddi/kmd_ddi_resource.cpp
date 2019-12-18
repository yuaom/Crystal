#include "pch.h"
#include "kmd_resource.h"
#include "kmd_privatedata.h"

////////////////////////////////////////////////////////////////////////////////
EXTERN_C NTSTATUS APIENTRY D3DKMTCreateAllocation( D3DKMT_CREATEALLOCATION* pCreateAllocation )
{
    LOG_DLL_ENTRY;

    Crystal::KMD::Resource::Create( pCreateAllocation );

    return STATUS_SUCCESS;
}

////////////////////////////////////////////////////////////////////////////////
EXTERN_C NTSTATUS APIENTRY D3DKMTDestroyAllocation( CONST D3DKMT_DESTROYALLOCATION* pDestroyAllocation )
{
    LOG_DLL_ENTRY;

    Crystal::KMD::Resource::Destroy( pDestroyAllocation->hResource );

    return STATUS_SUCCESS;
}