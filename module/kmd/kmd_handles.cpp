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
        KmtHandleManager*   KmtHandleManager::m_pHandles = nullptr;

        ////////////////////////////////////////////////////////////////////////////////
        void KmtHandleManager::OnDllProcessAttach()
        {
            if( m_pHandles == nullptr )
            {
                m_pHandles = new KmtHandleManager();
            }
        }

        ////////////////////////////////////////////////////////////////////////////////
        void KmtHandleManager::OnDllProcessDetach()
        {
            if( m_pHandles )
            {
                delete m_pHandles;
            }
        }

        ////////////////////////////////////////////////////////////////////////////////
        KmtHandleManager* KmtHandleManager::get()
        {
            return m_pHandles;
        }

        ////////////////////////////////////////////////////////////////////////////////
        KmtHandleManager::KmtHandleManager() :
            m_Base( 0 ),
            m_pCurrent( nullptr ),
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

            m_Base      = reinterpret_cast<size_t>( pResultAddress );
            m_pCurrent  = reinterpret_cast<HANDLE*>( pResultAddress );
        }

        ////////////////////////////////////////////////////////////////////////////////
        KmtHandleManager::~KmtHandleManager()
        {

        }

        ////////////////////////////////////////////////////////////////////////////////
        D3DKMT_HANDLE KmtHandleManager::Allocate( void* pObj )
        {
            KmtHandleManager* pManager = get();

            D3DKMT_HANDLE handle = 0;

            if( pManager->m_FreeList.size() == 0 )
            {
                if( pManager->m_SizeUsed % PAGE_SIZE == 0 )
                {
                    void* pResultAddress = VirtualAlloc(
                        pManager->m_pCurrent,
                        PAGE_SIZE,
                        MEM_COMMIT,
                        PAGE_READWRITE );
                    assert( pResultAddress == pManager->m_pCurrent );
                }

                HANDLE* pHandle = new( pManager->m_pCurrent ) HANDLE( pObj );

                pManager->m_pCurrent++;
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
            KmtHandleManager* pManager = get();

            HANDLE* handle = reinterpret_cast<HANDLE*>( pManager->m_Base + kmtHandle );
            handle->m_KmdObject = nullptr;

            pManager->m_FreeList.push( kmtHandle );
        }
    }
}

#pragma warning( pop )