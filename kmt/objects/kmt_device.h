#pragma once
#include "kmt_handles.h"

namespace Crystal
{
    namespace KMT
    {
        ////////////////////////////////////////////////////////////////////////////////
        class Device : public KmtObject<Device>
        {
        public:

            static bool Create( D3DKMT_CREATEDEVICE* pKTCreateDevice );

            static void Destroy( D3DKMT_HANDLE handle );

            Device( const D3DKMT_CREATEDEVICE* pKtCreateDevice );

            ~Device();

            bool CreateContext( RASTERCONTEXT_HANDLE& handle );
            
            constexpr const std::unique_ptr<RASTER_FUNCTIONS>& GetRasterFuncs() const;

        private:

            bool LoadRasterizer();

            D3DKMT_CREATEDEVICEFLAGS            m_Flags;
            HMODULE                             m_hRaster;
            std::unique_ptr<RASTER_FUNCTIONS>   m_pRasterFuncs;
        };

        ////////////////////////////////////////////////////////////////////////////////
        constexpr const std::unique_ptr<RASTER_FUNCTIONS>& Device::GetRasterFuncs() const
        {
            return m_pRasterFuncs;
        }
    }
}