#pragma once

namespace Crystal
{
    namespace KMD
    {
        class Device
        {
        public:

            static void Destroy( D3DKMT_HANDLE handle );

            Device( const D3DKMT_CREATEDEVICE* pKtCreateDevice );

            ~Device();

            D3DKMT_HANDLE    GetHandle();

        private:
            D3DKMT_HANDLE               m_Handle;
            D3DKMT_CREATEDEVICEFLAGS    m_Flags;
        };
    }
}