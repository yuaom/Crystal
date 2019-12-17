#include "pch.h"
#include "kmd_device.h"

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
            m_Flags( pKtCreateDevice->Flags )
        {
        }

        ////////////////////////////////////////////////////////////////////////////////
        Device::~Device()
        {

        }
    }
}