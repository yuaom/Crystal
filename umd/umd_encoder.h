#pragma once
#include "umd_device.h"
#include "umd_cmdbuffer.h"

namespace Crystal
{
    namespace UMD
    {
        ////////////////////////////////////////////////////////////////////////////////
        /// @brief Forward declarations
        struct Device;
        struct CommandBuffer;

        ////////////////////////////////////////////////////////////////////////////////
        class Encoder
        {
        public:
            static Encoder* Create( Device* pDevice, CommandBuffer* pInitialBuffer = nullptr );
            static void     Destroy( Encoder* pEncoder );

            template< typename CmdT >
            void Encode( CmdT& command );

            void Render();

        private:
            Encoder( Device* pDevice );

            ~Encoder();

            void    EnsureSpace( uint32_t size );

            Device* m_pDevice;

            std::vector<CommandBuffer*> m_CommandBuffers;
        };

        ////////////////////////////////////////////////////////////////////////////////
        template< typename CmdT >
        void Encoder::Encode( CmdT& command )
        {
            const uint32_t size = sizeof( CmdT );

            EnsureSpace( size );

            CmdT* pData = reinterpret_cast<CmdT*>( m_CommandBuffers.back()->GetSpace( size ) );

            if( pData )
            {
                memcpy_s( pData, sizeof( CmdT ), &command, sizeof( CmdT ) );
            }
        }
    }
}