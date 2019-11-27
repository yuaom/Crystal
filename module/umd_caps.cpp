#include "pch.h"
#include "umd_caps.h"
#include "umd_adapter.h"

namespace Crystal
{
	namespace UMD
	{
#pragma region DDI Entrypoints

		////////////////////////////////////////////////////////////////////////////////
		HRESULT APIENTRY GetSupportedVersions( 
			D3D10DDI_HADAPTER hAdapter, 
			UINT32* puEntries,
			UINT64* pSupportedDDIInterfaceVersions )
		{
			LOG_DLL_ENTRY;

			auto pAdapter = Adapter::FromHandle( hAdapter );
			const auto& versions = pAdapter->GetSupportedVersions();

			uint32_t entryCount = *puEntries;

			if( entryCount &&
				pSupportedDDIInterfaceVersions != nullptr )
			{
				memcpy_s(
					pSupportedDDIInterfaceVersions,
					entryCount * sizeof( UINT64 ),
					versions.data(),
					versions.size() * sizeof( UINT64 ) );
			}
			else
			{
				*puEntries = pAdapter->GetSupportedVersions().size();
			}

			return S_OK;
		}

		////////////////////////////////////////////////////////////////////////////////
		HRESULT APIENTRY GetCaps( 
			D3D10DDI_HADAPTER hAdapter,
			CONST D3D10_2DDIARG_GETCAPS* pCaps )
		{
			LOG_DLL_ENTRY;

			HRESULT hr = S_OK;

			auto pAdapter = Adapter::FromHandle( hAdapter );

			switch( pCaps->Type )
			{
			case D3D11DDICAPS_THREADING:
			{
				D3D11DDI_THREADING_CAPS* pThreadingCaps = 
					static_cast<D3D11DDI_THREADING_CAPS*>( pCaps->pData );
				hr = pAdapter->GetCaps( pThreadingCaps );
			}
			break;
			case D3D11DDICAPS_SHADER:
			{
				D3D11DDI_SHADER_CAPS* pShaderCaps =
					static_cast<D3D11DDI_SHADER_CAPS*>( pCaps->pData );
				hr = pAdapter->GetCaps( pShaderCaps );
			}
			break;
			case D3D11DDICAPS_3DPIPELINESUPPORT:
			{
				D3D11DDI_3DPIPELINESUPPORT_CAPS* pPipelineSupport = 
					static_cast<D3D11DDI_3DPIPELINESUPPORT_CAPS*>( pCaps->pData );
				hr = pAdapter->GetCaps( pPipelineSupport );
			}
				break;
			default:
				hr = E_NOTIMPL;
				break;
			}

			return hr;
		}

#pragma endregion
	}
}