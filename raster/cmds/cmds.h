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
                ATOMIC_WRITE,
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
            enum class SURFACE_TYPE
            {
                _1D,
                _2D,
                _3D,
                LINEAR
            };

            ////////////////////////////////////////////////////////////////////////////////
            /// @brief Clears a surface to an RGBA float4 value
            struct SURFACE_VIEW
            {
                SURFACE_TYPE    Type;
                size_t          Address;
                uint32_t        Width;
                uint32_t        Height;
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

                Header          Header;
                SURFACE_VIEW    View;
                float           ClearValues[4];
            };

            ////////////////////////////////////////////////////////////////////////////////
            /// @brief Atomically writes a value to the address
            struct ATOMIC_WRITE
            {
                ATOMIC_WRITE()
                {
                    ZeroMemory( this, sizeof( ATOMIC_WRITE ) );
                    Header.Type     = COMMAND_TYPE::ATOMIC_WRITE;
                    Header.Length   = sizeof( ATOMIC_WRITE ) / sizeof( uint32_t );
                }

                Header              Header;
                volatile LONG64*    Address;
                LONG64              Value;
            };
        }
    }
}
#pragma pack(pop)