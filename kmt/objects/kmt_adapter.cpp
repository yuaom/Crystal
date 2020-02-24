#include "pch.h"
#include "kmt_adapter.h"
#include "kmt_handles.h"

namespace Crystal
{
    namespace KMT
    {
#pragma region KmtAdapter

        ////////////////////////////////////////////////////////////////////////////////
        KmtAdapter::KmtAdapter( const LUID& luid ) :
            m_Handle( KmtHandleManager::Allocate( this ) ),
            m_LUID( luid )
        {
        }

        ////////////////////////////////////////////////////////////////////////////////
        KmtAdapter::~KmtAdapter()
        {
            KmtHandleManager::Free( m_Handle );
            m_Handle = 0;
        }

        ////////////////////////////////////////////////////////////////////////////////
        D3DKMT_HANDLE KmtAdapter::GetHandle()
        {
            return m_Handle;
        }

        ////////////////////////////////////////////////////////////////////////////////
        const LUID& KmtAdapter::GetLUID()
        {
            return m_LUID;
        }

#pragma endregion
#pragma region KmtAdapterManager

        ////////////////////////////////////////////////////////////////////////////////
        std::unique_ptr<KmtAdapterManager>    KmtAdapterManager::m_pAdapters = nullptr;

        ////////////////////////////////////////////////////////////////////////////////
        void KmtAdapterManager::OnDllProcessAttach()
        {
            if( m_pAdapters == nullptr )
            {
                m_pAdapters = std::make_unique<KmtAdapterManager>();
            }
        }

        ////////////////////////////////////////////////////////////////////////////////
        void KmtAdapterManager::OnDllProcessDetach()
        {
            m_pAdapters.release();
        }

        ////////////////////////////////////////////////////////////////////////////////
        std::unique_ptr<KmtAdapterManager>& KmtAdapterManager::get()
        {
            return m_pAdapters;
        }

        ////////////////////////////////////////////////////////////////////////////////
        KmtAdapterManager::KmtAdapterManager()
        {
        }

        ////////////////////////////////////////////////////////////////////////////////
        KmtAdapterManager::~KmtAdapterManager()
        {
        }
    }
#pragma endregion
}