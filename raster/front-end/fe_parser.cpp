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
            case COMMANDS::COMMAND_TYPE::NEXT_COMMANDBUFFER: Execute_NextCommandBuffer( reinterpret_cast<COMMANDS::NEXT_COMMANDBUFFER*>( pCmd ) ); break;
            default:
                assert( 0 );
            }
        }

        ////////////////////////////////////////////////////////////////////////////////
        void Execute_NextCommandBuffer( COMMANDS::NEXT_COMMANDBUFFER* pCmd )
        {
            OutputDebugString( "NEXT_COMMAND_BUFFER" );
        }
    }
}