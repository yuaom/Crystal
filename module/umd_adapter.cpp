#include "pch.h"
#include "umd_adapter.h"
#include "umd_device.h"
#include "umd_caps.h"

namespace Crystal
{
	namespace UMD
	{
#pragma region Adapter
		////////////////////////////////////////////////////////////////////////////////
		void Adapter::Create( D3D10DDIARG_OPENADAPTER* pOpenAdapter )
		{
			Adapter* pAdpater = new Adapter( pOpenAdapter );

			pOpenAdapter->hAdapter = MAKE_D3D10DDI_HADAPTER( pAdpater );
		}

		////////////////////////////////////////////////////////////////////////////////
		Adapter::Adapter( D3D10DDIARG_OPENADAPTER* pOpenAdapter ) :
			m_hRuntimeHandle( pOpenAdapter->hRTAdapter ),
			m_Interface( pOpenAdapter->Interface ),
			m_Version( pOpenAdapter->Version )
		{
			memcpy_s(
				&m_AdapterCallbacks,
				sizeof( D3DDDI_ADAPTERCALLBACKS ),
				pOpenAdapter->pAdapterCallbacks,
				sizeof( D3DDDI_ADAPTERCALLBACKS ) );

			pOpenAdapter->pAdapterFuncs_2->pfnCalcPrivateDeviceSize = CalcPrivateDeviceSize;
			pOpenAdapter->pAdapterFuncs_2->pfnCreateDevice			= CreateDevice;
			pOpenAdapter->pAdapterFuncs_2->pfnCloseAdapter			= CloseAdapter;
			pOpenAdapter->pAdapterFuncs_2->pfnGetCaps				= GetCaps;
			pOpenAdapter->pAdapterFuncs_2->pfnGetSupportedVersions	= GetSupportedVersions;
		}

		////////////////////////////////////////////////////////////////////////////////
		Adapter::~Adapter()
		{

		}

#pragma endregion
#pragma region DDI Entrypoints

		////////////////////////////////////////////////////////////////////////////////
		HRESULT APIENTRY CloseAdapter( D3D10DDI_HADAPTER hAdapter )
		{
			return S_OK;
		}

#pragma endregion

	} // namespace UMD
} // namespace Crystal