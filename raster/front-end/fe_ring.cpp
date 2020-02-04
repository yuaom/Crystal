#include "pch.h"
#include "fe_ring.h"

namespace Crystal
{
    namespace Raster
    {
        ////////////////////////////////////////////////////////////////////////////////
        Ring::Ring( uint32_t size ) :
            m_Tail( 0 ),
            m_Head( 0 ),
            m_CommandBuffer( size, 0 )
        {
        }

        ////////////////////////////////////////////////////////////////////////////////
        Ring::~Ring()
        {

        }

        ////////////////////////////////////////////////////////////////////////////////
        void* Ring::GetAddress()
        {
            return reinterpret_cast<void*>( &m_CommandBuffer );
        }

        ////////////////////////////////////////////////////////////////////////////////
        uint32_t Ring::GetMaxSize() const
        {
            return m_CommandBuffer.size();
        }

        ////////////////////////////////////////////////////////////////////////////////
        void Ring::SetTail( uint32_t offset )
        {
            m_Tail = offset;
        }

        ////////////////////////////////////////////////////////////////////////////////
        RenderRing* RenderRing::Create( 
            uint32_t count,
            uint32_t size )
        {
            return new RenderRing( count, size );
        }

        ////////////////////////////////////////////////////////////////////////////////
        void RenderRing::Destroy( RenderRing* &pRing )
        {
            if( pRing )
            {
                delete pRing;
                pRing = nullptr;
            }
        }

        ////////////////////////////////////////////////////////////////////////////////
        RenderRing::RenderRing( uint32_t count, uint32_t size ) :
            m_WriteHead( -1 ),
            m_ReadHead( -1 ),
            m_ReadTail( -1 )
        {
            assert( size % sizeof( uint32_t ) == 0 );

            for( uint32_t i = 0; i < count; i++ )
            {
                m_Rings.emplace_back( std::make_unique<Ring>( size ) );
            }
        }

        ////////////////////////////////////////////////////////////////////////////////
        RenderRing::~RenderRing()
        {
            m_Rings.clear();
        }

        ////////////////////////////////////////////////////////////////////////////////
        void RenderRing::AdvanceWriteHead()
        {
            m_WriteHead = ( ++m_WriteHead ) % m_Rings.size();

            while( m_WriteHead == m_ReadHead )
            {
                assert( 0 );
                Sleep( 100 );
            }
        }

        ////////////////////////////////////////////////////////////////////////////////
        Ring::ptr_t& RenderRing::GetWrite()
        {
            return m_Rings[m_WriteHead];
        }

        ////////////////////////////////////////////////////////////////////////////////
        void RenderRing::WriteComplete()
        {
            m_ReadTail = m_WriteHead;
        }

        ////////////////////////////////////////////////////////////////////////////////
        bool RenderRing::HasWork() const
        {
            return m_ReadHead != m_ReadTail;
        }

        ////////////////////////////////////////////////////////////////////////////////
        void RenderRing::AdvanceReadHead()
        {
            m_ReadHead = ( ++m_ReadHead ) % m_Rings.size();
        }

        ////////////////////////////////////////////////////////////////////////////////
        Ring::ptr_t& RenderRing::GetRead()
        {
            return m_Rings[m_ReadHead];
        }
    }
}