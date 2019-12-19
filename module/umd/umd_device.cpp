#include "pch.h"
#include "umd_device.h"
#include "umd_ddi.h"
#include "kmd_privatedata.h"

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
            Device* pDevice = new( pCreateDevice->hDrvDevice.pDrvPrivate ) Device(
                pCreateDevice,
                pAdapter );

            pDevice->CreateContexts();
        }

        ////////////////////////////////////////////////////////////////////////////////
        void Device::Destroy( Device* pDevice )
        {
            Encoder::Destroy( pDevice->m_pEncoder );

            ZeroMemory( pDevice, sizeof( Device ) );
        }

        ////////////////////////////////////////////////////////////////////////////////
        Device* Device::FromHandle( D3D10DDI_HDEVICE handle )
        {
            return reinterpret_cast<Device*>( handle.pDrvPrivate );
        }

        ////////////////////////////////////////////////////////////////////////////////
        Device* Device::FromHandle( DXGI_DDI_HDEVICE handle )
        {
            return reinterpret_cast<Device*>( handle );
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
            m_hRTDevice( pCreateDevice->hRTDevice ),
            m_hRTCoreLayer( pCreateDevice->hRTCoreLayer ),
            m_pAdapter( pAdapter ),
            m_pEncoder( nullptr ),
            m_pKTCallbacks( nullptr ),
            m_pCoreLayerCallbacks( nullptr ),
            m_pDXGICallbacks( nullptr ),
            m_ContextHandle( 0 )
        {
            m_pKTCallbacks = pCreateDevice->pKTCallbacks;
            m_pCoreLayerCallbacks = pCreateDevice->pWDDM2_6UMCallbacks;
            m_pDXGICallbacks = pCreateDevice->DXGIBaseDDI.pDXGIBaseCallbacks;

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

            m_pEncoder = Encoder::Create( this );
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
            *pOut =
                D3D10_DDI_FORMAT_SUPPORT_SHADER_SAMPLE |
                D3D10_DDI_FORMAT_SUPPORT_RENDERTARGET |
                D3D10_DDI_FORMAT_SUPPORT_BLENDABLE |
                D3D11_1DDI_FORMAT_SUPPORT_VERTEX_BUFFER |
                D3D11_1DDI_FORMAT_SUPPORT_UAV_WRITES |
                D3D11_1DDI_FORMAT_SUPPORT_BUFFER |
                D3D11_1DDI_FORMAT_SUPPORT_SHADER_GATHER;
        }

        ////////////////////////////////////////////////////////////////////////////////
        void Device::GetMultisampleSupport(
            DXGI_FORMAT format,
            UINT sampleCount,
            UINT* pNumQualityLevels )
        {
            if( pNumQualityLevels )
            {
                *pNumQualityLevels = 0;
            }
        }

        ////////////////////////////////////////////////////////////////////////////////
        void Device::CreateContexts()
        {
            HRESULT hr = S_OK;

            D3DDDI_CREATECONTEXTFLAGS flags = { 0 };
            flags.DisableGpuTimeout = TRUE;

            D3DDDICB_CREATECONTEXT cb = { 0 };
            cb.NodeOrdinal = 0;
            cb.EngineAffinity = 0;
            cb.Flags.Value = flags.Value;

            hr = m_pKTCallbacks->pfnCreateContextCb(
                m_hRTDevice.handle,
                &cb );

            if( SUCCEEDED( hr ) )
            {
                m_ContextHandle = cb.hContext;
            }
        }

        ////////////////////////////////////////////////////////////////////////////////
        HANDLE Device::GetContextHandle() const
        {
            assert( m_ContextHandle != 0 );
            return m_ContextHandle;
        }

        ////////////////////////////////////////////////////////////////////////////////
        Encoder* Device::GetEncoder() const
        {
            return m_pEncoder;
        }

        ////////////////////////////////////////////////////////////////////////////////
        void Device::Present( DXGIDDICB_PRESENT& cb )
        {
            HRESULT hr = m_pDXGICallbacks->pfnPresentCb(
                m_hRTDevice.handle,
                &cb );

            if( FAILED( hr ) )
            {
                m_pCoreLayerCallbacks->pfnSetErrorCb( m_hRTCoreLayer, hr );
            }
        }

        ////////////////////////////////////////////////////////////////////////////////
        D3DKMT_HANDLE Device::Allocate( D3DDDICB_ALLOCATE& cb )
        {
            HRESULT hr = m_pKTCallbacks->pfnAllocateCb(
                m_hRTDevice.handle,
                &cb );

            if( FAILED( hr ) )
            {
                m_pCoreLayerCallbacks->pfnSetErrorCb( m_hRTCoreLayer, hr );
                return 0;
            }

            return cb.hKMResource;
        }

        ////////////////////////////////////////////////////////////////////////////////
        void Device::Deallocate( D3DDDICB_DEALLOCATE& cb )
        {
            HRESULT hr = m_pKTCallbacks->pfnDeallocateCb( 
                m_hRTDevice.handle, 
                &cb );

            if( FAILED( hr ) )
            {
                m_pCoreLayerCallbacks->pfnSetErrorCb( m_hRTCoreLayer, hr );
            }
        }

        ////////////////////////////////////////////////////////////////////////////////
        void Device::Render( D3DDDICB_RENDER& cb )
        {
            cb.hContext = m_ContextHandle;

            HRESULT hr = m_pKTCallbacks->pfnRenderCb(
                m_hRTDevice.handle,
                &cb );

            if( FAILED( hr ) )
            {
                m_pCoreLayerCallbacks->pfnSetErrorCb( m_hRTCoreLayer, hr );
            }
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

            return size;
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