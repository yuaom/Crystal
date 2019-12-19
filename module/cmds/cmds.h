#pragma once

namespace Crystal
{
    namespace Commands
    {
        ////////////////////////////////////////////////////////////////////////////////
        enum class COMMAND_TYPE
        {
            NEXT_COMMANDBUFFER,
            COMMAND_TYPE_CLEAR_RTV
        };

        ////////////////////////////////////////////////////////////////////////////////
        /// @brief Chains to another command buffer
        struct NEXT_COMMANDBUFFER
        {
            NEXT_COMMANDBUFFER()
            {
                ZeroMemory( this, sizeof( NEXT_COMMANDBUFFER ) );
                Type = COMMAND_TYPE::NEXT_COMMANDBUFFER;
            }

            COMMAND_TYPE    Type;
            size_t          Address;
            uint32_t        Size;
        };

        ////////////////////////////////////////////////////////////////////////////////
        /// @brief Clears a surface to an RGBA float4 value
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