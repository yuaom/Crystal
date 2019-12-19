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

            pEncoder->m_pCurrent = pInitialBuffer;

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
            m_pDevice( pDevice ),
            m_pCurrent( nullptr )
        {

        }

        ////////////////////////////////////////////////////////////////////////////////
        Encoder::~Encoder()
        {

        }

        ////////////////////////////////////////////////////////////////////////////////
        void Encoder::Render()
        {
            D3DDDICB_RENDER render;
            ZeroMemory( &render, sizeof( render ) );

            m_pDevice->Render( m_CommandBuffers.front() );
        }

        ////////////////////////////////////////////////////////////////////////////////
        void Encoder::EnsureSpace( uint32_t size )
        {
            size += 0x40; // temporary

            if( m_pCurrent == nullptr )
            {
                m_pCurrent = CommandBuffer::Create( m_pDevice, size );
                m_CommandBuffers.push_back( m_pCurrent );
            }
            else if( !m_pCurrent->HasSpace( size ) )
            {
                m_pCurrent = CommandBuffer::Create( m_pDevice, size );
                m_CommandBuffers.push_back( m_pCurrent );
            }
        }
    }
}