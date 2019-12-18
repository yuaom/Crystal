#include "pch.h"
#include "kmd_handles.h"
#include "kmd_allocation.h"
#include "gmm.h"
#include "kmd_privatedata.h"

namespace Crystal
{
    namespace KMD
    {
        ////////////////////////////////////////////////////////////////////////////////
        Allocation* Allocation::Create( D3DDDI_ALLOCATIONINFO* pInfo )
        {
            Allocation* pAllocation = new Allocation( pInfo );

            pAllocation->Allocate( pInfo );

            // Populate DDI Return Arguments
            pInfo->hAllocation = pAllocation->GetHandle();

            return pAllocation;
        }

        ////////////////////////////////////////////////////////////////////////////////
        void Allocation::Destroy( D3DKMT_HANDLE handle )
        {
            Allocation* pAllocation = KmtHandleManager::To<Allocation>( handle );
            delete pAllocation;
        }

        ////////////////////////////////////////////////////////////////////////////////
        Allocation::Allocation( D3DDDI_ALLOCATIONINFO* pInfo ) :
            m_Handle( KmtHandleManager::Allocate( this ) )
        {

        }

        ////////////////////////////////////////////////////////////////////////////////
        Allocation::~Allocation()
        {
            KmtHandleManager::Free( m_Handle );
        }

        ////////////////////////////////////////////////////////////////////////////////
        D3DKMT_HANDLE Allocation::GetHandle() const
        {
            return m_Handle;
        }

        ////////////////////////////////////////////////////////////////////////////////
        void Allocation::Allocate( D3DDDI_ALLOCATIONINFO* pInfo )
        {
            D3DDDI_ALLOCATIONINFO_PRIVATE* pPrivateData = 
                reinterpret_cast<D3DDDI_ALLOCATIONINFO_PRIVATE*>( pInfo->pPrivateDriverData );
            GMM::ALLOCATION_INFO* pAllocationInfo = pPrivateData->pAllocationInfo;

            void* cpuAddress = VirtualAlloc( 
                0, 
                pAllocationInfo->Size, 
                MEM_RESERVE | MEM_COMMIT, 
                PAGE_READWRITE );

            if( cpuAddress != NULL )
            {
                pAllocationInfo->Address = reinterpret_cast<size_t>( cpuAddress );
            }
            else
            {
                assert( 0 );
            }
        }
    }
}