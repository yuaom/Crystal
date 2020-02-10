#pragma once
#include "umd_device.h"
#include "gmm.h"

namespace Crystal
{
    namespace UMD
    {
        ////////////////////////////////////////////////////////////////////////////////
        class Resource
        {
        public:
            static void         Create( D3D10DDI_HDEVICE hDevice, const D3D11DDIARG_CREATERESOURCE* pCreateResource, D3D10DDI_HRESOURCE hResource, D3D10DDI_HRTRESOURCE hRTResource );
            static void         Destroy( D3D10DDI_HRESOURCE hResource );
            static uint32_t     CalculateSize( const D3D11DDIARG_CREATERESOURCE* pCalcSize );
            static Resource*    FromHandle( D3D10DDI_HRESOURCE handle );
            static Resource*    FromHandle( DXGI_DDI_HRESOURCE handle );

            D3DKMT_HANDLE   GetAllocationHandle() const;
            size_t          GetAddress() const;
            uint32_t        GetWidth() const;
            uint32_t        GetHeight() const;
            uint32_t        GetPitch() const;
            uint32_t        GetBitsPerPixel() const;

        private:

            Resource( const D3D11DDIARG_CREATERESOURCE* pCreateResource, Device* pDevice, D3D10DDI_HRTRESOURCE hRTResource );
            ~Resource();

            void Allocate( const D3D11DDIARG_CREATERESOURCE* pCreateResource );

            D3D10DDI_HRTRESOURCE    m_hRTResource;
            D3DKMT_HANDLE           m_ResourceHandle;
            D3DKMT_HANDLE           m_AllocationHandle;
            GMM::ALLOCATION_INFO*   m_pAllocationInfo;
            Device*                 m_pDevice;
        };
    }
}