#pragma once
#include "kmd_handles.h"

namespace Crystal
{
    namespace KMD
    {
        ////////////////////////////////////////////////////////////////////////////////
        class Device : public KmtObject<Device>
        {
        public:

            static bool Create( D3DKMT_CREATEDEVICE* pKTCreateDevice );

            static void Destroy( D3DKMT_HANDLE handle );

            Device( const D3DKMT_CREATEDEVICE* pKtCreateDevice );

            ~Device();

        private:

            bool LoadRasterizer();

            D3DKMT_CREATEDEVICEFLAGS    m_Flags;
            HMODULE                     m_hRaster;
        };
    }
}