#pragma once
#include "umd_device.h"
#include "umd_allocation.h"

namespace Crystal
{
    namespace UMD
    {
        ////////////////////////////////////////////////////////////////////////////////
        class Resource
        {
        public:
            static void         Create( D3D10DDI_HDEVICE hDevice, const D3D11DDIARG_CREATERESOURCE* pCreateResource, D3D10DDI_HRESOURCE hResource, D3D10DDI_HRTRESOURCE hRTResource );
            static void         Destroy( Resource* pResource );
            static uint32_t     CalculateSize( const D3D11DDIARG_CREATERESOURCE* pCalcSize );
            static Resource*    FromHandle( D3D10DDI_HRESOURCE handle );
            static Resource*    FromHandle( DXGI_DDI_HRESOURCE handle );

            Allocation* GetAllocation() const;

        private:

            Resource( const D3D11DDIARG_CREATERESOURCE* pCreateResource, Device* pDevice, D3D10DDI_HRTRESOURCE hRTResource );
            ~Resource();

            void Allocate( const D3D11DDIARG_CREATERESOURCE* pCreateResource );

            D3D10DDI_HRTRESOURCE    m_hRTResource;
            D3DKMT_HANDLE           m_ResourceHandle;
            Allocation*             m_pAllocation;

            Device* m_pDevice;
        };
    }
}