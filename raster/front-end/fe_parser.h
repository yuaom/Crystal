#pragma once
#include "cmds.h"

namespace Crystal
{
    namespace Raster
    {
        void Execute( COMMANDS::Header* pCmd );

        void Execute_NextCommandBuffer( COMMANDS::NEXT_COMMANDBUFFER* pCmd );
    }
}