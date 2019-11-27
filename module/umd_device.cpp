#include "pch.h"
#include "umd_device.h"

namespace Crystal
{
	namespace UMD
	{
#pragma region DDI Entrypoints

		////////////////////////////////////////////////////////////////////////////////
		SIZE_T APIENTRY CalcPrivateDeviceSize( 
			D3D10DDI_HADAPTER hAdapter, 
			const D3D10DDIARG_CALCPRIVATEDEVICESIZE* pCalcPrivateDeviceSize )
		{
			LOG_DLL_ENTRY;

			return 0;
		}

		////////////////////////////////////////////////////////////////////////////////
		HRESULT APIENTRY CreateDevice( 
			D3D10DDI_HADAPTER hAdapter, 
			D3D10DDIARG_CREATEDEVICE* pCreateDevice )
		{
			LOG_DLL_ENTRY;

			return S_OK;
		}

#pragma endregion
	}
}