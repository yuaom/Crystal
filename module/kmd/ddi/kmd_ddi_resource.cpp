#include "pch.h"
#include "kmd_resource.h"
#include "kmd_privatedata.h"

////////////////////////////////////////////////////////////////////////////////
EXTERN_C NTSTATUS APIENTRY D3DKMTCreateAllocation( D3DKMT_CREATEALLOCATION* pCreateAllocation )
{
    LOG_DLL_ENTRY;

    const Crystal::KMD::D3DDDI_ALLOCATIONINFO_PRIVATE* pPrivateData = 
        reinterpret_cast<const Crystal::KMD::D3DDDI_ALLOCATIONINFO_PRIVATE*>( pCreateAllocation->pPrivateDriverData );

    Crystal::KMD::Resource::Create( pCreateAllocation );

    return STATUS_SUCCESS;
}