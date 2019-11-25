#include "pch.h"
#include "entrypoints.h"

////////////////////////////////////////////////////////////////////////////////
EXTERN_C HRESULT APIENTRY OpenAdapter10( D3D10DDIARG_OPENADAPTER* arg1 )
{
	LOG_DLL_ENTRY;
	return S_OK;
}

////////////////////////////////////////////////////////////////////////////////
EXTERN_C HRESULT APIENTRY OpenAdapter10_2( D3D10DDIARG_OPENADAPTER* arg1 )
{
	LOG_DLL_ENTRY;
	return S_OK;
}

////////////////////////////////////////////////////////////////////////////////
EXTERN_C NTSTATUS APIENTRY D3DKMTCreateDevice( _Inout_ D3DKMT_CREATEDEVICE* )
{
	LOG_DLL_ENTRY;
	return 1;
}

////////////////////////////////////////////////////////////////////////////////
EXTERN_C NTSTATUS APIENTRY D3DKMTOpenAdapterFromGdiDisplayName( _Inout_ D3DKMT_OPENADAPTERFROMGDIDISPLAYNAME* )
{
	LOG_DLL_ENTRY;
	return 1;
}

////////////////////////////////////////////////////////////////////////////////
EXTERN_C NTSTATUS APIENTRY D3DKMTOpenAdapterFromDeviceName( _Inout_ D3DKMT_OPENADAPTERFROMDEVICENAME* )
{
	LOG_DLL_ENTRY;
	return 1;
}

////////////////////////////////////////////////////////////////////////////////
EXTERN_C NTSTATUS APIENTRY D3DKMTQueryAdapterInfo( _Inout_ CONST D3DKMT_QUERYADAPTERINFO* adapterInfo )
{
	LOG_DLL_ENTRY;

	NTSTATUS result = STATUS_SUCCESS;

	switch (adapterInfo->Type)
	{
	case KMTQAITYPE_UMDRIVERNAME:
	{
		D3DKMT_UMDFILENAMEINFO* pFileNameInfo = reinterpret_cast<D3DKMT_UMDFILENAMEINFO*>(adapterInfo->pPrivateDriverData);

		if (pFileNameInfo->Version == KMTUMDVERSION_DX10 ||
			pFileNameInfo->Version == KMTUMDVERSION_DX11)
		{
			wcscpy( pFileNameInfo->UmdFileName, L"Crystal Rasterizer" );
		}
		else
		{
			result = STATUS_INVALID_PARAMETER;
		}
	}
	break;
	case KMTQAITYPE_CHECKDRIVERUPDATESTATUS:
	{
		BOOL* pUpdateStatus = reinterpret_cast<BOOL*>(adapterInfo->pPrivateDriverData);
		*pUpdateStatus = FALSE;
	}
	break;
	default:
		result = STATUS_INVALID_PARAMETER;
		break;
	};

	return result;
}