#include "pch.h"
#include "kmt_device.h"

namespace Crystal
{
    namespace KMT
    {
        ////////////////////////////////////////////////////////////////////////////////
        bool Device::Create( D3DKMT_CREATEDEVICE* pKTCreateDevice )
        {
            Device* pDevice = new Device( pKTCreateDevice );

            bool success = true;
            
            if( success )
            {
                success = pDevice->LoadRasterizer();
            }

            if( success )
            {
                pKTCreateDevice->hDevice = pDevice->GetHandle();
            }

            if( !success )
            {
                delete pDevice;
                pDevice = nullptr;
            }

            return success;
        }

        ////////////////////////////////////////////////////////////////////////////////
        void Device::Destroy( D3DKMT_HANDLE handle )
        {
            Device* pDevice = FromHandle( handle );
            delete pDevice;
        }

        ////////////////////////////////////////////////////////////////////////////////
        Device::Device( const D3DKMT_CREATEDEVICE* pKtCreateDevice ) :
            m_Flags( pKtCreateDevice->Flags ),
            m_hRaster( NULL ),
            m_pRasterFuncs( std::make_unique<RASTER_FUNCTIONS>() )
        {

        }

        ////////////////////////////////////////////////////////////////////////////////
        Device::~Device()
        {
            FreeLibrary( m_hRaster );
        }

        ////////////////////////////////////////////////////////////////////////////////
        bool Device::LoadRasterizer()
        {
            bool success = true;

            PFNOPENRASTERIZER pfnOpenRasterizer = nullptr;

            m_hRaster = LoadLibrary( "CrystalRaster64.dll" );

            if( m_hRaster )
            {
                pfnOpenRasterizer = reinterpret_cast<PFNOPENRASTERIZER>( 
                    GetProcAddress( m_hRaster, "OpenRasterizer" ) );

                if( pfnOpenRasterizer == nullptr )
                {
                    success = false;
                }
            }
            else
            {
                success = false;
            }

            if( success )
            {
                RASTERARGS_OPENRASTERIZER rasterArgs = { 0 };
                rasterArgs.options.TotalRingSize        = 16 * KILOBYTE;
                rasterArgs.options.MinimumRingWriteSize = 32 * sizeof( uint32_t );
                rasterArgs.pRasterFuncs                 = m_pRasterFuncs.get();

                if( pfnOpenRasterizer )
                {
                    success = pfnOpenRasterizer( &rasterArgs );
                }
                else
                {
                    success = false;
                }
            }

            return success;
        }

        ////////////////////////////////////////////////////////////////////////////////
        bool Device::CreateContext( RASTERCONTEXT_HANDLE& handle )
        {
            RASTERARGS_CREATECONTEXT args = { 0 };

            bool success = m_pRasterFuncs->pfnCreateContext( &args );
            
            if( success )
            {
                handle = args.hHandle;
            }

            return success;
        }
    }
}