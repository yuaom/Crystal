#include "pch.h"
#include "kmd_adapter.h"
#include "kmd_handles.h"

namespace Crystal
{
    namespace KMD
    {
#pragma region KmdAdapter

        ////////////////////////////////////////////////////////////////////////////////
        KmdAdapter::KmdAdapter() :
            m_Handle( KmtHandleManager::get()->Allocate( this ) )
        {
        }

        ////////////////////////////////////////////////////////////////////////////////
        KmdAdapter::~KmdAdapter()
        {
        }

        ////////////////////////////////////////////////////////////////////////////////
        D3DKMT_HANDLE KmdAdapter::GetHandle()
        {
            return m_Handle;
        }

#pragma endregion
#pragma region KmdAdapterManager

        ////////////////////////////////////////////////////////////////////////////////
        std::unique_ptr<KmdAdapterManager>    KmdAdapterManager::m_pAdapters = nullptr;

        ////////////////////////////////////////////////////////////////////////////////
        void KmdAdapterManager::OnDllProcessAttach()
        {
            if( m_pAdapters == nullptr )
            {
                m_pAdapters = std::make_unique<KmdAdapterManager>();
            }
        }

        ////////////////////////////////////////////////////////////////////////////////
        void KmdAdapterManager::OnDllProcessDetach()
        {
            m_pAdapters.release();
        }

        ////////////////////////////////////////////////////////////////////////////////
        std::unique_ptr<KmdAdapterManager>& KmdAdapterManager::get()
        {
            return m_pAdapters;
        }

        ////////////////////////////////////////////////////////////////////////////////
        KmdAdapterManager::KmdAdapterManager()
        {
        }

        ////////////////////////////////////////////////////////////////////////////////
        KmdAdapterManager::~KmdAdapterManager()
        {
        }

        ////////////////////////////////////////////////////////////////////////////////
        D3DKMT_HANDLE KmdAdapterManager::ListIndexToKmtHandle( uint32_t i )
        {
            return static_cast<D3DKMT_HANDLE>( i + 1 );
        }

        ////////////////////////////////////////////////////////////////////////////////
        uint32_t KmdAdapterManager::KmtHandleToListIndex( D3DKMT_HANDLE handle )
        {
            return static_cast<uint32_t>( handle ) - 1;
        }
    }
#pragma endregion
}