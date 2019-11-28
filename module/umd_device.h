#pragma once
#include "umd_adapter.h"

namespace Crystal
{
	namespace UMD
	{
#pragma region Device

		////////////////////////////////////////////////////////////////////////////////
		/// @brief UMD Device
		class Device
		{
		public:
			static void Create( D3D10DDIARG_CREATEDEVICE* pCreateDevice, Adapter* pAdapter );

			static void Destroy();

			static uint32_t	CalculateSize( const D3D10DDIARG_CALCPRIVATEDEVICESIZE* pCalcSize );

		private:

			Device( D3D10DDIARG_CREATEDEVICE* pCreateDevice, Adapter* pAdapter );

			~Device();

			D3D10DDI_HRTDEVICE	m_RuntimeHandle;

			Adapter* m_pAdapter;
		};

#pragma endregion
#pragma region DDI Entrypoints

		SIZE_T APIENTRY CalcPrivateDeviceSize( D3D10DDI_HADAPTER hAdapter, const D3D10DDIARG_CALCPRIVATEDEVICESIZE* pCalcPrivateDeviceSize );
		HRESULT APIENTRY CreateDevice( D3D10DDI_HADAPTER hAdapter, D3D10DDIARG_CREATEDEVICE* pCreateDevice );

#pragma endregion
	}
}