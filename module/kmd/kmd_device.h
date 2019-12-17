#pragma once
#include "kmd_handles.h"

namespace Crystal
{
    namespace KMD
    {
        ////////////////////////////////////////////////////////////////////////////////
        class Device : public KmtObject
        {
        public:

            static void Destroy( D3DKMT_HANDLE handle );

            Device( const D3DKMT_CREATEDEVICE* pKtCreateDevice );

            ~Device();

        private:
            D3DKMT_CREATEDEVICEFLAGS    m_Flags;
        };
    }
}