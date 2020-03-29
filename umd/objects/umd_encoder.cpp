#include "pch.h"
#include "umd_encoder.h"

namespace Crystal
{
    namespace UMD
    {
        ////////////////////////////////////////////////////////////////////////////////
        Encoder* Encoder::Create( 
            Device* pDevice, 
            CommandBuffer* pInitialBuffer )
        {
            Encoder* pEncoder = new Encoder( pDevice );

            pEncoder->m_CommandBuffers.push_back( pInitialBuffer );

            return pEncoder;
        }

        ////////////////////////////////////////////////////////////////////////////////
        void Encoder::Destroy( Encoder* pEncoder )
        {
            for( auto& pCommandBuffer : pEncoder->m_CommandBuffers )
            {
                CommandBuffer::Destroy( pCommandBuffer );
            }

            pEncoder->m_CommandBuffers.clear();

            delete pEncoder;
        }

        ////////////////////////////////////////////////////////////////////////////////
        Encoder::Encoder( Device* pDevice ) :
            m_pDevice( pDevice )
        {

        }

        ////////////////////////////////////////////////////////////////////////////////
        Encoder::~Encoder()
        {

        }

        ////////////////////////////////////////////////////////////////////////////////
        void Encoder::Render()
        {
            m_pDevice->Render( m_CommandBuffers.front()->SizeUsed() );
        }

        ////////////////////////////////////////////////////////////////////////////////
        void Encoder::EnsureSpace( uint32_t size )
        {
            size += sizeof( Raster::COMMANDS::NEXT_COMMANDBUFFER );

            if( !m_CommandBuffers.back()->HasSpace( size ) )
            {
                m_CommandBuffers.push_back( CommandBuffer::Create( m_pDevice, size ) );
            }
        }
    }
}