#include "pch.h"
#include "umd_caps.h"

namespace Crystal
{
	namespace UMD
	{
#pragma region DDI Entrypoints

		////////////////////////////////////////////////////////////////////////////////
		HRESULT APIENTRY GetSupportedVersions( 
			D3D10DDI_HADAPTER hAdpater, 
			UINT32* puEntries,
			UINT64* pSupportedDDIInterfaceVersions )
		{
			LOG_DLL_ENTRY;

			return S_OK;
		}

		////////////////////////////////////////////////////////////////////////////////
		HRESULT APIENTRY GetCaps( 
			D3D10DDI_HADAPTER hAdapter,
			CONST D3D10_2DDIARG_GETCAPS* pCaps )
		{
			LOG_DLL_ENTRY;

			return S_OK;
		}

#pragma endregion
	}
}