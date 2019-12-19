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

            pAllocation->Allocate();

            // Populate DDI Return Arguments
            pInfo->hAllocation = pAllocation->GetHandle();

            return pAllocation;
        }

        ////////////////////////////////////////////////////////////////////////////////
        void Allocation::Destroy( Allocation* pAllocation )
        {
            pAllocation->Deallocate();

            delete pAllocation;
        }

        ////////////////////////////////////////////////////////////////////////////////
        Allocation::Allocation( D3DDDI_ALLOCATIONINFO* pInfo ) :
            m_Handle( KmtHandleManager::Allocate( this ) ),
            m_pAllocationInfo( nullptr )
        {
            D3DDDI_ALLOCATIONINFO_PRIVATE* pPrivateData =
                reinterpret_cast<D3DDDI_ALLOCATIONINFO_PRIVATE*>( pInfo->pPrivateDriverData );
            m_pAllocationInfo = pPrivateData->pAllocationInfo;
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
        size_t Allocation::GetAddress() const
        {
            return m_pAllocationInfo->Address;
        }

        ////////////////////////////////////////////////////////////////////////////////
        size_t Allocation::GetSize() const
        {
            return m_pAllocationInfo->Size;
        }

        ////////////////////////////////////////////////////////////////////////////////
        void Allocation::Allocate()
        {
            void* cpuAddress = VirtualAlloc( 
                0, 
                m_pAllocationInfo->Size,
                MEM_RESERVE | MEM_COMMIT, 
                PAGE_READWRITE );

            if( cpuAddress != NULL )
            {
                m_pAllocationInfo->Address = reinterpret_cast<size_t>( cpuAddress );
            }
            else
            {
                assert( 0 );
            }
        }

        ////////////////////////////////////////////////////////////////////////////////
        void Allocation::Deallocate()
        {
            if( m_pAllocationInfo->Address )
            {
                void* address = reinterpret_cast<void*>( m_pAllocationInfo->Address );

                BOOL result = VirtualFree( 
                    address,
                    0, 
                    MEM_RELEASE );

                if( result )
                {
                    m_pAllocationInfo->Address = 0;
                }
                else
                {
                    assert( 0 );
                }
                
            }
        }
    }
}