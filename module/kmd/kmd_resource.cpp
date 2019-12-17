#include "pch.h"
#include "kmd_resource.h"
#include "kmd_handles.h"

namespace Crystal
{
    namespace KMD
    {
        ////////////////////////////////////////////////////////////////////////////////
        Resource* Resource::Create( D3DKMT_CREATEALLOCATION* pCreateResource )
        {
            Resource* pResource = new Resource( pCreateResource );

            for( uint32_t i = 0; i < pCreateResource->NumAllocations; i++ )
            {
                D3DDDI_ALLOCATIONINFO* pInfo = &pCreateResource->pAllocationInfo[i];

                Allocation* pAllocation = Allocation::Create( pInfo );

                pResource->m_Allocations.push_back( pAllocation );
            }

            // Populate DDI Return Arguments
            pCreateResource->hResource = pResource->GetHandle();

            return pResource;
        }

        ////////////////////////////////////////////////////////////////////////////////
        void Resource::Destroy( D3DKMT_HANDLE handle )
        {
            Resource* pResource = KmtHandleManager::To<Resource>( handle );
            delete pResource;
        }

        ////////////////////////////////////////////////////////////////////////////////
        Resource::Resource( D3DKMT_CREATEALLOCATION* pCreateResource ) :
            m_Handle( KmtHandleManager::Allocate( this ) )
        {
        }

        ////////////////////////////////////////////////////////////////////////////////
        Resource::~Resource()
        {
            KmtHandleManager::Free( m_Handle );
        }

        ////////////////////////////////////////////////////////////////////////////////
        D3DKMT_HANDLE Resource::GetHandle() const
        {
            return m_Handle;
        }
    }
}