#include "pch.h"
#include "kmd_adapter.h"

namespace Crystal
{
#pragma region KmdAdapter

    ////////////////////////////////////////////////////////////////////////////////
    KmdAdapter::KmdAdapter( D3DKMT_HANDLE handle ) :
        m_Handle( handle )
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

#pragma endregion
}