#pragma once
#include "cmds.h"

namespace Crystal
{
    namespace Raster
    {
        void Execute( COMMANDS::Header* pCmd );

        void Execute_NextCommandBuffer( COMMANDS::NEXT_COMMANDBUFFER* pCmd );
        void Execute_ClearRTV( COMMANDS::CLEAR_RENDER_TARGET_VIEW* pCmd );
    }
}