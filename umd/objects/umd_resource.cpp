#include "pch.h"
#include "umd_resource.h"
#include "kmt_privatedata.h"

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
        void Resource::Destroy( D3D10DDI_HRESOURCE hResource )
        {
            Resource* pResource = Resource::FromHandle( hResource );

            D3DDDICB_DEALLOCATE cb;
            ZeroMemory( &cb, sizeof( D3DDDICB_DEALLOCATE ) );
            cb.hResource = pResource->m_hRTResource.handle;

            pResource->m_pDevice->Deallocate( cb );
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
            m_AllocationHandle( 0 ),
            m_pAllocationInfo( new GMM::ALLOCATION_INFO )
        {
            ZeroMemory( m_pAllocationInfo, sizeof( GMM::ALLOCATION_INFO ) );

            m_pAllocationInfo->ArraySlices      = pCreateResource->ArraySize;
            m_pAllocationInfo->Format           = pCreateResource->Format;
            m_pAllocationInfo->IsInternal       = false;
            m_pAllocationInfo->MipLevels        = pCreateResource->MipLevels;
            m_pAllocationInfo->Mip0TexelWidth   = pCreateResource->pMipInfoList[0].TexelWidth;
            m_pAllocationInfo->Mip0TexelHeight  = pCreateResource->pMipInfoList[0].TexelHeight;
            m_pAllocationInfo->Mip0TexelDepth   = pCreateResource->pMipInfoList[0].TexelDepth;
            m_pAllocationInfo->Dimension        = GMM::ConvertDDIResourceType( pCreateResource->ResourceDimension );

            GMM::CreateAllocationInfo( m_pAllocationInfo );
        }

        ////////////////////////////////////////////////////////////////////////////////
        Resource::~Resource()
        {
            if( m_pAllocationInfo ) delete m_pAllocationInfo;
        }

        ////////////////////////////////////////////////////////////////////////////////
        D3DKMT_HANDLE Resource::GetAllocationHandle() const
        {
            return m_AllocationHandle;
        }

        ////////////////////////////////////////////////////////////////////////////////
        void Resource::Allocate( const D3D11DDIARG_CREATERESOURCE* pCreateResource )
        {
            KMT::D3DDDI_ALLOCATIONINFO_PRIVATE allocInfoPrivateData;
            ZeroMemory( &allocInfoPrivateData, sizeof( KMT::D3DDDI_ALLOCATIONINFO_PRIVATE ) );
            allocInfoPrivateData.pAllocationInfo = m_pAllocationInfo;

            // Allocate the Resource
            D3DDDI_ALLOCATIONINFO allocInfo;
            ZeroMemory( &allocInfo, sizeof( D3DDDI_ALLOCATIONINFO ) );

            allocInfo.pPrivateDriverData    = &allocInfoPrivateData;
            allocInfo.PrivateDriverDataSize = sizeof( KMT::D3DDDI_ALLOCATIONINFO_PRIVATE );

            D3DDDICB_ALLOCATE allocate = { 0 };
            allocate.hResource          = m_hRTResource.handle;
            allocate.NumAllocations     = 1;
            allocate.pAllocationInfo    = &allocInfo;

            m_ResourceHandle = m_pDevice->Allocate( allocate );

            m_AllocationHandle = allocInfo.hAllocation;
        }

        ////////////////////////////////////////////////////////////////////////////////
        size_t Resource::GetAddress() const
        {
            return m_pAllocationInfo->Address;
        }

        ////////////////////////////////////////////////////////////////////////////////
        uint32_t Resource::GetWidth() const
        {
            return m_pAllocationInfo->Mip0TexelWidth;
        }

        ////////////////////////////////////////////////////////////////////////////////
        uint32_t Resource::GetHeight() const
        {
            return m_pAllocationInfo->Mip0TexelHeight;
        }

        ////////////////////////////////////////////////////////////////////////////////
        uint32_t Resource::GetPitch() const
        {
            return m_pAllocationInfo->Pitch;
        }

        ////////////////////////////////////////////////////////////////////////////////
        uint32_t Resource::GetBitsPerPixel() const
        {
            return m_pAllocationInfo->BitsPerPixel;
        }
    }
}