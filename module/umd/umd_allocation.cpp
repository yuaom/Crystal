#include "pch.h"
#include "umd_allocation.h"

namespace Crystal
{
    namespace UMD
    {
        ////////////////////////////////////////////////////////////////////////////////
        Allocation::Allocation( D3DDDI_ALLOCATIONINFO* pAllocInfo ) :
            m_Handle( pAllocInfo->hAllocation ),
            m_IsPrimary( pAllocInfo->Flags.Primary ),
            m_IsStereo( pAllocInfo->Flags.Stereo ),
            m_Size( 0 )
        {

        }

        ////////////////////////////////////////////////////////////////////////////////
        Allocation::~Allocation()
        {

        }

        ////////////////////////////////////////////////////////////////////////////////
        D3DKMT_HANDLE Allocation::GetHandle() const
        {
            return m_Handle;
        }

        ////////////////////////////////////////////////////////////////////////////////
        uint32_t Allocation::GetSize() const
        {
            return m_Size;
        }
    }
}