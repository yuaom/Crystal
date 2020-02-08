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
            OutputDebugString( "NEXT_COMMAND_BUFFER\n" );
        }

        ////////////////////////////////////////////////////////////////////////////////
        void Execute_ClearRTV( COMMANDS::CLEAR_RENDER_TARGET_VIEW* pCmd )
        {
            OutputDebugString( "CLEAR_RENDER_TARGET_VIEW\n" );

            COMMANDS::SURFACE_VIEW& view = pCmd->View;
            byte* pColorBuffer = reinterpret_cast<byte*>( view.Address );

            for( uint32_t j = 0; j < view.Height; j++ )
            {
                for( uint32_t i = 0; i < view.Width; i++ )
                {
                    byte* pixel = &pColorBuffer[j * view.Width + i * 4];

                    pixel[0] = static_cast<byte>( 255 * pCmd->ClearValues[0] );
                    pixel[1] = static_cast<byte>( 255 * pCmd->ClearValues[1] );
                    pixel[2] = static_cast<byte>( 255 * pCmd->ClearValues[2] );
                    pixel[3] = static_cast<byte>( 255 * pCmd->ClearValues[3] );
                }
            }
        }

        ////////////////////////////////////////////////////////////////////////////////
        void Execute_AtomicWrite( COMMANDS::ATOMIC_WRITE* pCmd )
        {
            OutputDebugString( "ATOMIC_WRITE\n" );
            InterlockedExchange64( pCmd->Address, pCmd->Value );
        }
    }
}