#include "pch.h"
#include "umd_cmdbuffer.h"

namespace Crystal
{
    namespace UMD
    {
        ////////////////////////////////////////////////////////////////////////////////
        CommandBuffer* CommandBuffer::Create( 
            Device* pDevice,
            uint32_t size )
        {
            CommandBuffer* pCmdBuffer = new CommandBuffer( pDevice );

            if( size )
            {
                pCmdBuffer->Allocate( size );
            }

            return pCmdBuffer;
        }

        ////////////////////////////////////////////////////////////////////////////////
        void CommandBuffer::Destroy( CommandBuffer* pCmdBuffer )
        {
            delete pCmdBuffer;
        }

        ////////////////////////////////////////////////////////////////////////////////
        CommandBuffer::CommandBuffer( Device* pDevice ) :
            m_pDevice( pDevice ),
            m_pBuffer( nullptr ),
            m_SizeUsed( 0 ),
            m_SizeTotal( 0 )
        {

        }

        ////////////////////////////////////////////////////////////////////////////////
        CommandBuffer::~CommandBuffer()
        {

        }

        ////////////////////////////////////////////////////////////////////////////////
        void CommandBuffer::Allocate( uint32_t size )
        {
            m_SizeUsed  = 0;
            m_SizeTotal = size;
        }

        ////////////////////////////////////////////////////////////////////////////////
        byte* CommandBuffer::GetSpace( uint32_t size )
        {
            byte* pData = m_pBuffer;

            m_pBuffer   += size;
            m_SizeUsed  += size;

            return pData;
        }

        ////////////////////////////////////////////////////////////////////////////////
        bool CommandBuffer::HasSpace( uint32_t size ) const
        {
            return m_SizeUsed + size <= m_SizeTotal;
        }
    }
}