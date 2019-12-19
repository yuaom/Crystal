#pragma once

namespace Crystal
{
    namespace Commands
    {
        ////////////////////////////////////////////////////////////////////////////////
        enum class COMMAND_TYPE
        {
            COMMAND_TYPE_CLEAR_RTV
        };

        ////////////////////////////////////////////////////////////////////////////////
        struct CLEAR_RENDER_TARGET_VIEW
        {
            CLEAR_RENDER_TARGET_VIEW()
            {
                ZeroMemory( this, sizeof( CLEAR_RENDER_TARGET_VIEW ) );
                Type = COMMAND_TYPE::COMMAND_TYPE_CLEAR_RTV;
            }

            COMMAND_TYPE    Type;
            D3DKMT_HANDLE   hAllocation;
            float           ClearValues[4];
        };
    }
}