#pragma once
#include "umd_adapter.h"
#include "umd_encoder.h"
#include "umd_cmdbuffer.h"

namespace Crystal
{
    namespace UMD
    {
#pragma region Device
        ////////////////////////////////////////////////////////////////////////////////
        /// @brief Forward declarations
        struct Encoder;

        ////////////////////////////////////////////////////////////////////////////////
        /// @brief UMD Device
        class Device
        {
        public:
            static void     Create( D3D10DDIARG_CREATEDEVICE* pCreateDevice, Adapter* pAdapter );
            static void     Destroy( Device* pDevice );
            static uint32_t CalculateSize( const D3D10DDIARG_CALCPRIVATEDEVICESIZE* pCalcSize );
            static Device*  FromHandle( D3D10DDI_HDEVICE handle );
            static Device*  FromHandle( DXGI_DDI_HDEVICE handle );

            void GetFormatSupport( DXGI_FORMAT format, UINT* pOut );
            void GetMultisampleSupport( DXGI_FORMAT format, UINT sampleCount, UINT* pNumQualityLevels );

            HANDLE      GetContextHandle() const;
            Encoder*    GetEncoder() const;

            // DXGI Callbacks
            void Present( DXGIDDICB_PRESENT& cb );

            // Memory Callbacks
            D3DKMT_HANDLE   Allocate( D3DDDICB_ALLOCATE& cb );
            void            Deallocate( D3DDDICB_DEALLOCATE& cb );

            // Render Callbacks
            void Render( uint32_t size );

        private:

            Device( D3D10DDIARG_CREATEDEVICE* pCreateDevice, Adapter* pAdapter );

            ~Device();

            void CreateContexts();

            const D3DDDI_DEVICECALLBACKS*                   m_pKTCallbacks;
            const D3DWDDM2_6DDI_CORELAYER_DEVICECALLBACKS*  m_pCoreLayerCallbacks;
            const DXGI_DDI_BASE_CALLBACKS*                  m_pDXGICallbacks;

            D3D10DDI_HRTDEVICE      m_hRTDevice;
            D3D10DDI_HRTCORELAYER   m_hRTCoreLayer;

            // Submission
            HANDLE          m_ContextHandle;

            Adapter* m_pAdapter;
            Encoder* m_pEncoder;
        };

#pragma endregion
#pragma region DDI Entrypoints

        SIZE_T APIENTRY CalcPrivateDeviceSize( D3D10DDI_HADAPTER hAdapter, const D3D10DDIARG_CALCPRIVATEDEVICESIZE* pCalcPrivateDeviceSize );
        HRESULT APIENTRY CreateDevice( D3D10DDI_HADAPTER hAdapter, D3D10DDIARG_CREATEDEVICE* pCreateDevice );

#pragma endregion
    }
}