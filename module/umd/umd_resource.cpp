#include "pch.h"
#include "umd_resource.h"

namespace Crystal
{
    namespace UMD
    {
        ////////////////////////////////////////////////////////////////////////////////
        void Resource::Create(
            D3D10DDI_HDEVICE hDevice,
            const D3D11DDIARG_CREATERESOURCE* pCreateResource,
            D3D10DDI_HRESOURCE hResource,
            D3D10DDI_HRTRESOURCE hRTResource )
        {
            Device* pDevice = Device::FromHandle( hDevice );

            Resource* pResource = new( hResource.pDrvPrivate ) Resource(
                pCreateResource,
                pDevice,
                hRTResource );

            pResource->Allocate( pCreateResource );
        }

        ////////////////////////////////////////////////////////////////////////////////
        void Resource::Destroy( Resource* pResource )
        {

        }

        ////////////////////////////////////////////////////////////////////////////////
        uint32_t Resource::CalculateSize( const D3D11DDIARG_CREATERESOURCE* pCalcSize )
        {
            return sizeof( Resource );
        }

        ////////////////////////////////////////////////////////////////////////////////
        Resource* Resource::FromHandle( D3D10DDI_HRESOURCE handle )
        {
            return reinterpret_cast<Resource*>( handle.pDrvPrivate );
        }

        ////////////////////////////////////////////////////////////////////////////////
        Resource* Resource::FromHandle( DXGI_DDI_HRESOURCE handle )
        {
            return reinterpret_cast<Resource*>( handle );
        }

        ////////////////////////////////////////////////////////////////////////////////
        Resource::Resource( 
            const D3D11DDIARG_CREATERESOURCE* pCreateResource, 
            Device* pDevice, 
            D3D10DDI_HRTRESOURCE hRTResource ) :
            m_pDevice( pDevice ),
            m_hRTResource( hRTResource ),
            m_ResourceHandle( 0 ),
            m_pAllocation( nullptr )
        {

        }

        ////////////////////////////////////////////////////////////////////////////////
        Resource::~Resource()
        {
            delete m_pAllocation;
        }

        ////////////////////////////////////////////////////////////////////////////////
        Allocation* Resource::GetAllocation() const
        {
            return m_pAllocation;
        }

        ////////////////////////////////////////////////////////////////////////////////
        void Resource::Allocate( const D3D11DDIARG_CREATERESOURCE* pCreateResource )
        {
            // Create GMM allocation structure
            KMD::GMM_ALLOCATION_INFO allocInfo;
            ZeroMemory( &allocInfo, sizeof( allocInfo ) );
            allocInfo.ArraySlices   = pCreateResource->ArraySize;
            allocInfo.Format        = pCreateResource->Format;
            allocInfo.IsInternal    = false;
            allocInfo.MipLevels     = pCreateResource->MipLevels;

            // Allocate the Resource
            D3DDDICB_ALLOCATE allocate = { 0 };
            allocate.hResource      = m_hRTResource.handle;
            allocate.NumAllocations = 1;
            
            m_ResourceHandle = m_pDevice->Allocate( allocate );

            m_pAllocation = new Allocation( allocate.pAllocationInfo );

            // Map the resource VA
            D3DDDI_MAPGPUVIRTUALADDRESS map = { 0 };
            map.hAllocation = m_pAllocation->GetHandle();
            
            m_pDevice->MapGpuVirtualAddress( map );
        }
    }
}