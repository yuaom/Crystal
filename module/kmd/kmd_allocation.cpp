#include "pch.h"
#include "kmd_handles.h"
#include "kmd_allocation.h"

namespace Crystal
{
    namespace KMD
    {
        ////////////////////////////////////////////////////////////////////////////////
        Allocation* Allocation::Create( D3DDDI_ALLOCATIONINFO* pInfo )
        {
            Allocation* pAllocation = new Allocation( pInfo );

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
    }
}