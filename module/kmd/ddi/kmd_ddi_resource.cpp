#include "pch.h"
#include "kmd_ddi_resource.h"

////////////////////////////////////////////////////////////////////////////////
EXTERN_C NTSTATUS APIENTRY D3DKMTCreateAllocation( D3DKMT_CREATEALLOCATION* pCreateAllocation )
{
    LOG_DLL_ENTRY;
    return STATUS_SUCCESS;
}