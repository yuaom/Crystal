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
            new( pCreateDevice->hDrvDevice.pDrvPrivate ) Device( 
                pCreateDevice, 
                pAdapter );
        }

        ////////////////////////////////////////////////////////////////////////////////
        void Device::Destroy( Device* pDevice )
        {
            ZeroMemory( pDevice, sizeof( Device ) );
        }

        ////////////////////////////////////////////////////////////////////////////////
        Device* Device::FromHandle( D3D10DDI_HDEVICE handle )
        {
            return reinterpret_cast<Device*>( handle.pDrvPrivate );
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
            m_pKTCallbacks = pCreateDevice->pKTCallbacks;

            switch( pCreateDevice->Interface )
            {
            case D3DWDDM1_3_DDI_INTERFACE_VERSION:
                DDI::FillDdiTable( pCreateDevice->pWDDM1_3DeviceFuncs );
                break;
            case D3D11_1_DDI_INTERFACE_VERSION:
            case D3D10_1_DDI_INTERFACE_VERSION:
            case D3D11_0_DDI_INTERFACE_VERSION:
            case D3DWDDM2_0_DDI_INTERFACE_VERSION:
            case D3DWDDM2_1_DDI_INTERFACE_VERSION:
            case D3DWDDM2_2_DDI_INTERFACE_VERSION:
            case D3DWDDM2_6_DDI_INTERFACE_VERSION:
            default:
                assert( 0 );
            }
            
            DDI::FillDdiTable( pCreateDevice->DXGIBaseDDI.pDXGIDDIBaseFunctions6_1 );
        }

        ////////////////////////////////////////////////////////////////////////////////
        Device::~Device()
        {

        }

        ////////////////////////////////////////////////////////////////////////////////
        void Device::GetFormatSupport( 
            DXGI_FORMAT format, 
            UINT* pOut )
        {
            // For simplicity, support almost all access types on all formats
            *pOut = D3D10_DDI_FORMAT_SUPPORT_SHADER_SAMPLE |
                D3D10_DDI_FORMAT_SUPPORT_RENDERTARGET |
                D3D10_DDI_FORMAT_SUPPORT_BLENDABLE |
                D3D10_DDI_FORMAT_SUPPORT_MULTISAMPLE_RENDERTARGET |
                D3D10_DDI_FORMAT_SUPPORT_MULTISAMPLE_LOAD |
                D3D11_1DDI_FORMAT_SUPPORT_VERTEX_BUFFER |
                D3D11_1DDI_FORMAT_SUPPORT_UAV_WRITES |
                D3D11_1DDI_FORMAT_SUPPORT_BUFFER |
                D3D11_1DDI_FORMAT_SUPPORT_OUTPUT_MERGER_LOGIC_OP |
                D3D11_1DDI_FORMAT_SUPPORT_SHADER_GATHER;
        }

        ////////////////////////////////////////////////////////////////////////////////
        void Device::GetMultisampleSupport( 
            DXGI_FORMAT format, 
            UINT sampleCount, 
            UINT* pNumQualityLevels )
        {
            // Return support for 1x, 2x, 4x, 16x
            if ( sampleCount == 1 || 
                 sampleCount == 2 || 
                 sampleCount == 4 || 
                 sampleCount == 16 )
            {
                *pNumQualityLevels = 1;
            }
            else *pNumQualityLevels = 0;
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