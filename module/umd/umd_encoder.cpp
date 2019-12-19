#include "pch.h"
#include "umd_encoder.h"

namespace Crystal
{
    namespace UMD
    {
        ////////////////////////////////////////////////////////////////////////////////
        Encoder* Encoder::Create( Device* pDevice )
        {
            Encoder* pEncoder = new Encoder( pDevice );
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

            render.CommandLength = m_CommandBuffers.front()->SizeUsed();

            m_pDevice->Render( render );
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