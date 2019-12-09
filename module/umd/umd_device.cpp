#include "pch.h"
#include "umd_device.h"
#include "umd_ddi.h"

namespace Crystal
{
	namespace UMD
	{
#pragma region Device

		////////////////////////////////////////////////////////////////////////////////
		void Device::Create( 
			D3D10DDIARG_CREATEDEVICE* pCreateDevice,
			Adapter* pAdapter )
		{
			new( reinterpret_cast<void*>( pCreateDevice->hDrvDevice.pDrvPrivate ) ) Device( 
				pCreateDevice, 
				pAdapter );
		}

		////////////////////////////////////////////////////////////////////////////////
		void Device::Destroy()
		{

		}

		////////////////////////////////////////////////////////////////////////////////
		uint32_t Device::CalculateSize( const D3D10DDIARG_CALCPRIVATEDEVICESIZE* pCalcSize )
		{
			return sizeof( Device );
		}

		////////////////////////////////////////////////////////////////////////////////
		Device::Device( 
			D3D10DDIARG_CREATEDEVICE* pCreateDevice,
			Adapter* pAdapter ) :
			m_RuntimeHandle( pCreateDevice->hRTDevice ),
			m_pAdapter( pAdapter )
		{
			uint32_t cnt = sizeof( *pCreateDevice->pWDDM2_6DeviceFuncs ) / sizeof( void* );
			uint64_t* pFunc = reinterpret_cast<uint64_t*>( pCreateDevice->pWDDM2_6DeviceFuncs );
			for( uint64_t i = 0; i < cnt; i++, pFunc++ )*pFunc = ( 1ULL << 32 ) | ( i + 1 );

			cnt = sizeof( *pCreateDevice->DXGIBaseDDI.pDXGIDDIBaseFunctions6_1 ) / sizeof( void* );
			pFunc = reinterpret_cast<uint64_t*>( pCreateDevice->DXGIBaseDDI.pDXGIDDIBaseFunctions6_1 );
			for( uint64_t i = 0; i < cnt; i++, pFunc++ )*pFunc = ( 2ULL << 32 ) | ( i + 1 );

			DDI::FillDdiTable( pCreateDevice->p11_1DeviceFuncs );			
		}

		////////////////////////////////////////////////////////////////////////////////
		Device::~Device()
		{

		}

#pragma endregion
#pragma region DDI Entrypoints

		////////////////////////////////////////////////////////////////////////////////
		SIZE_T APIENTRY CalcPrivateDeviceSize( 
			D3D10DDI_HADAPTER hAdapter, 
			const D3D10DDIARG_CALCPRIVATEDEVICESIZE* pCalcPrivateDeviceSize )
		{
			LOG_DLL_ENTRY;

			size_t size = Device::CalculateSize( pCalcPrivateDeviceSize );

			return 0;
		}

		////////////////////////////////////////////////////////////////////////////////
		HRESULT APIENTRY CreateDevice( 
			D3D10DDI_HADAPTER hAdapter, 
			D3D10DDIARG_CREATEDEVICE* pCreateDevice )
		{
			LOG_DLL_ENTRY;

			Adapter* pAdpater = Adapter::FromHandle( hAdapter );

			Device::Create( pCreateDevice, pAdpater );

			return S_OK;
		}

#pragma endregion
	}
}