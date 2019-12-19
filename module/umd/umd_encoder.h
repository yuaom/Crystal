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
            static Encoder* Create( Device* pDevice );
            static void     Destroy( Encoder* pEncoder );

            template< typename CmdT >
            void Encode( CmdT& command );

        private:
            Encoder( Device* pDevice );

            ~Encoder();

            void    EnsureSpace( uint32_t size );

            Device* m_pDevice;

            std::vector<CommandBuffer*> m_CommandBuffers;
            CommandBuffer*              m_pCurrent;
        };

        ////////////////////////////////////////////////////////////////////////////////
        template< typename CmdT >
        void Encoder::Encode( CmdT& command )
        {
            const uint32_t size = sizeof( CmdT );

            EnsureSpace( size );

            CmdT* pData = reinterpret_cast<CmdT*>( m_pCurrent->GetSpace( size ) );

            if( pData )
            {
                memcpy_s( pData, sizeof( CmdT ), &command, sizeof( CmdT ) );
            }
        }
    }
}