#include "pch.h"
#include "kmd_device.h"

namespace Crystal
{
    namespace KMD
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
            m_hRaster( NULL )
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

            m_hRaster = LoadLibrary( "CrystalRaster64.dll" );

            if( m_hRaster )
            {
                PFNOPENRASTERIZER pfnOpenRasterizer =
                    reinterpret_cast<PFNOPENRASTERIZER>( GetProcAddress( m_hRaster, "OpenRasterizer" ) );

                if( pfnOpenRasterizer )
                {
                    success = pfnOpenRasterizer();
                }
                else
                {
                    success = false;
                }

            }
            else
            {
                success = false;
            }

            return success;
        }
    }
}