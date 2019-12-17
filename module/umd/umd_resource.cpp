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

            pResource->Allocate();
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
        D3DKMT_HANDLE Resource::GetHandle() const
        {
            return m_Handle;
        }

        ////////////////////////////////////////////////////////////////////////////////
        Resource::Resource( 
            const D3D11DDIARG_CREATERESOURCE* pCreateResource, 
            Device* pDevice, 
            D3D10DDI_HRTRESOURCE hRTResource ) :
            m_pDevice( pDevice ),
            m_hRTResource( hRTResource ),
            m_Address( 0 ),
            m_Handle( 0 )
        {

        }

        ////////////////////////////////////////////////////////////////////////////////
        Resource::~Resource()
        {

        }

        ////////////////////////////////////////////////////////////////////////////////
        void Resource::Allocate()
        {
            D3DDDICB_ALLOCATE allocate = { 0 };
            allocate.hResource = m_hRTResource.handle;
            
            std::tie( m_Address, m_Handle ) = m_pDevice->Allocate( allocate );
        }
    }
}