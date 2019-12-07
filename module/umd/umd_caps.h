#pragma once

namespace Crystal
{
	namespace UMD
	{
#pragma region DDI Entrypoints

		////////////////////////////////////////////////////////////////////////////////
		HRESULT APIENTRY GetSupportedVersions( D3D10DDI_HADAPTER hAdpater, UINT32* puEntries, UINT64* pSupportedDDIInterfaceVersions );
		HRESULT APIENTRY GetCaps( D3D10DDI_HADAPTER hAdapter, CONST D3D10_2DDIARG_GETCAPS* pCaps );

#pragma endregion
	}
}