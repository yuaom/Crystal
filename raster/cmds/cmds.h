#pragma once
#include <Windows.h>
#include <cstdint>

#pragma pack(push)
#pragma pack(4)
namespace Crystal
{
    namespace Raster
    {
        namespace COMMANDS
        {
            ////////////////////////////////////////////////////////////////////////////////
            enum class COMMAND_TYPE
            {
                NOOP = 0,
                NEXT_COMMANDBUFFER,
                CLEAR_RTV
            };

            ////////////////////////////////////////////////////////////////////////////////
            struct Header
            {
                COMMAND_TYPE    Type    : 16;
                uint32_t        Length  : 16;
            };

            ////////////////////////////////////////////////////////////////////////////////
            /// @brief Chains to another command buffer
            struct NEXT_COMMANDBUFFER
            {
                NEXT_COMMANDBUFFER()
                {
                    ZeroMemory( this, sizeof( NEXT_COMMANDBUFFER ) );
                    Header.Type     = COMMAND_TYPE::NEXT_COMMANDBUFFER;
                    Header.Length   = sizeof( NEXT_COMMANDBUFFER ) / sizeof(uint32_t);
                }

                Header      Header;
                size_t      Address;
                uint32_t    Size;
            };

            ////////////////////////////////////////////////////////////////////////////////
            /// @brief Clears a surface to an RGBA float4 value
            struct CLEAR_RENDER_TARGET_VIEW
            {
                CLEAR_RENDER_TARGET_VIEW()
                {
                    ZeroMemory( this, sizeof( CLEAR_RENDER_TARGET_VIEW ) );
                    Header.Type     = COMMAND_TYPE::CLEAR_RTV;
                    Header.Length   = sizeof( CLEAR_RENDER_TARGET_VIEW ) / sizeof( uint32_t );
                }

                Header  Header;
                size_t  Address;
                float   ClearValues[4];
            };
        }
    }
}
#pragma pack(pop)