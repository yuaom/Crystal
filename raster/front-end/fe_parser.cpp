#include "pch.h"
#include "fe_parser.h"

namespace Crystal
{
    namespace Raster
    {
        ////////////////////////////////////////////////////////////////////////////////
        void Execute( COMMANDS::Header* pCmd )
        {
            switch( pCmd->Type )
            {
            case COMMANDS::COMMAND_TYPE::NEXT_COMMANDBUFFER:    Execute_NextCommandBuffer( reinterpret_cast<COMMANDS::NEXT_COMMANDBUFFER*>( pCmd ) ); break;
            case COMMANDS::COMMAND_TYPE::CLEAR_RTV:             Execute_ClearRTV( reinterpret_cast<COMMANDS::CLEAR_RENDER_TARGET_VIEW*>( pCmd ) ); break;
            case COMMANDS::COMMAND_TYPE::ATOMIC_WRITE:          Execute_AtomicWrite( reinterpret_cast<COMMANDS::ATOMIC_WRITE*>( pCmd ) ); break;
            default:
                assert( 0 );
            }
        }

        ////////////////////////////////////////////////////////////////////////////////
        void Execute_NextCommandBuffer( COMMANDS::NEXT_COMMANDBUFFER* pCmd )
        {
            LOG_RASTER_COMMAND( "NEXT_COMMAND_BUFFER" );
        }

        ////////////////////////////////////////////////////////////////////////////////
        void Execute_ClearRTV( COMMANDS::CLEAR_RENDER_TARGET_VIEW* pCmd )
        {
            LOG_RASTER_COMMAND( "CLEAR_RENDER_TARGET_VIEW" );

            COMMANDS::SURFACE_VIEW& view = pCmd->View;
            uint32_t Bpp = view.BitsPerPixel / 8;

            byte* pColorBuffer = reinterpret_cast<byte*>( view.Address );

            for( uint32_t row = 0; row < view.Height; row++ )
            {
                uint32_t row_offset = row * view.Pitch;

                for( uint32_t col = 0; col < view.Width; col++ )
                {
                    byte* pixel = pColorBuffer + row_offset + col * Bpp;

                    pixel[3] = static_cast<byte>( 255 * pCmd->ClearValues[0] );
                    pixel[2] = static_cast<byte>( 255 * pCmd->ClearValues[1] );
                    pixel[1] = static_cast<byte>( 255 * pCmd->ClearValues[2] );
                    pixel[0] = static_cast<byte>( 255 * pCmd->ClearValues[3] );
                }
            }
        }

        ////////////////////////////////////////////////////////////////////////////////
        void Execute_AtomicWrite( COMMANDS::ATOMIC_WRITE* pCmd )
        {
            LOG_RASTER_COMMAND( "ATOMIC_WRITE" );

            InterlockedExchange64( pCmd->Address, pCmd->Value );
        }
    }
}