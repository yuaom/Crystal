#include "pch.h"
#include "kmd_resource.h"
#include "kmd_privatedata.h"

////////////////////////////////////////////////////////////////////////////////
EXTERN_C NTSTATUS APIENTRY D3DKMTCreateAllocation( D3DKMT_CREATEALLOCATION* pCreateAllocation )
{
    LOG_DLL_ENTRY;

    const Crystal::KMD::D3DDDI_ALLOCATIONINFO_PRIVATE* pPrivateData = 
        reinterpret_cast<const Crystal::KMD::D3DDDI_ALLOCATIONINFO_PRIVATE*>( pCreateAllocation->pPrivateDriverData );

    Crystal::KMD::Resource* pResource = new Crystal::KMD::Resource();

    pPrivateData->pAllocationInfo->Address = 0x0000008401000000;

    pCreateAllocation->hResource = pResource->GetHandle();

    return STATUS_SUCCESS;
}