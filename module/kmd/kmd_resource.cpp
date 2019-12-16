#include "pch.h"
#include "kmd_resource.h"
#include "kmd_handles.h"

namespace Crystal
{
    namespace KMD
    {
        ////////////////////////////////////////////////////////////////////////////////
        void Resource::Destroy( D3DKMT_HANDLE handle )
        {
            Resource* pResource = KmtHandleManager::To<Resource>( handle );
            delete pResource;
        }

        ////////////////////////////////////////////////////////////////////////////////
        Resource::Resource() :
            m_Handle( KmtHandleManager::Allocate( this ) )
        {
        }

        ////////////////////////////////////////////////////////////////////////////////
        Resource::~Resource()
        {
            KmtHandleManager::Free( m_Handle );
            m_Handle = 0;
        }

        ////////////////////////////////////////////////////////////////////////////////
        D3DKMT_HANDLE Resource::GetHandle()
        {
            return m_Handle;
        }
    }
}