#include "pch.h"
#include "kmd_handles.h"

// KmtHandleManager relies on pointer truncation
#pragma warning( push )
#pragma warning( disable : 4311 )

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
            m_pHandleAllocation( nullptr ),
            m_SizeUsed( 0 )
        {
            void* desiredUpperbound = reinterpret_cast<void*>( 0x100000000UL );

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
            auto& pManager = get();

            D3DKMT_HANDLE handle = 0;

            if( pManager->m_FreeList.size() == 0 )
            {
                if( pManager->m_SizeUsed % PAGE_SIZE == 0 )
                {
                    void* pResultAddress = VirtualAlloc(
                        pManager->m_pHandleAllocation,
                        PAGE_SIZE,
                        MEM_COMMIT,
                        PAGE_READWRITE );
                    assert( pResultAddress == pManager->m_pHandleAllocation );
                }

                HANDLE* pHandle = new( pManager->m_pHandleAllocation ) HANDLE( pObj );

                pManager->m_pHandleAllocation++;
                pManager->m_SizeUsed += sizeof( HANDLE );

                handle = reinterpret_cast<D3DKMT_HANDLE>( pHandle );
            }
            else
            {
                handle = pManager->m_FreeList.top();
                pManager->m_FreeList.pop();
            }

            return handle;
        }

        ////////////////////////////////////////////////////////////////////////////////
        void KmtHandleManager::Free( D3DKMT_HANDLE kmtHandle )
        {
            auto& pManager = get();

            HANDLE* handle = pManager->m_pHandleAllocation;
            handle->m_KmtHandle = kmtHandle;
            handle->m_KmdObject = nullptr;

            pManager->m_FreeList.push( kmtHandle );
        }
    }
}

#pragma warning( pop )