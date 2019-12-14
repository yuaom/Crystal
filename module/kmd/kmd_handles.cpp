#include "pch.h"
#include "kmd_handles.h"

namespace Crystal
{
    namespace KMD
    {
        ////////////////////////////////////////////////////////////////////////////////
        std::unique_ptr<KmtHandleManager>    KmtHandleManager::m_pHandles = nullptr;

        ////////////////////////////////////////////////////////////////////////////////
        void KmtHandleManager::OnDllProcessAttach()
        {
            if( m_pHandles == nullptr )
            {
                m_pHandles = std::make_unique<KmtHandleManager>();
            }
        }

        ////////////////////////////////////////////////////////////////////////////////
        void KmtHandleManager::OnDllProcessDetach()
        {
            m_pHandles.release();
        }

        ////////////////////////////////////////////////////////////////////////////////
        std::unique_ptr<KmtHandleManager>& KmtHandleManager::get()
        {
            return m_pHandles;
        }

        ////////////////////////////////////////////////////////////////////////////////
        KmtHandleManager::KmtHandleManager() :
            m_pHandleAllocation( nullptr )
        {
            void* desiredUpperbound = reinterpret_cast<void*>( 0x1000000000UL );

            // default is 512k handles, ~4MB, reserved, not committed
            uint32_t kmtHandleCount     = 512 * 1024;
            uint32_t allocSizeInBytes   = kmtHandleCount * sizeof( HANDLE );

            void* pResultAddress = VirtualAlloc(
                desiredUpperbound,
                allocSizeInBytes,
                MEM_RESERVE, 
                PAGE_READWRITE );
            assert( desiredUpperbound == pResultAddress );

            m_pHandleAllocation = reinterpret_cast<HANDLE*>( pResultAddress );
        }

        ////////////////////////////////////////////////////////////////////////////////
        KmtHandleManager::~KmtHandleManager()
        {

        }

        ////////////////////////////////////////////////////////////////////////////////
        D3DKMT_HANDLE KmtHandleManager::Allocate( void* pObj )
        {
            if( reinterpret_cast<size_t>( m_pHandleAllocation ) % PAGE_SIZE == 0 )
            {
                void* pResultAddress = VirtualAlloc( 
                    m_pHandleAllocation, 
                    PAGE_SIZE, 
                    MEM_COMMIT, 
                    PAGE_READWRITE );
                assert( pResultAddress == m_pHandleAllocation );
            }

            HANDLE* pHandle = new( m_pHandleAllocation ) HANDLE( pObj );
            m_pHandleAllocation++;
            return pHandle->m_KmtHandle;
        }
    }
}