#include "pch.h"
#include "kmd_device.h"
#include "kmd_handles.h"

namespace Crystal
{
    namespace KMD
    {
        ////////////////////////////////////////////////////////////////////////////////
        void Device::Destroy( D3DKMT_HANDLE handle )
        {
            Device* pDevice = KmtHandleManager::To<Device>( handle );
            delete pDevice;
        }

        ////////////////////////////////////////////////////////////////////////////////
        Device::Device( const D3DKMT_CREATEDEVICE* pKtCreateDevice ) :
            m_Handle( KmtHandleManager::Allocate( this ) ),
            m_Flags( pKtCreateDevice->Flags )
        {
        }

        ////////////////////////////////////////////////////////////////////////////////
        Device::~Device()
        {
            KmtHandleManager::Free( m_Handle );
            m_Handle = 0;
        }

        ////////////////////////////////////////////////////////////////////////////////
        D3DKMT_HANDLE Device::GetHandle()
        {
            return m_Handle;
        }
    }
}