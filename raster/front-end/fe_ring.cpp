#include "pch.h"
#include "fe_ring.h"

namespace Crystal
{
    namespace Raster
    {
        ////////////////////////////////////////////////////////////////////////////////
        Ring::Ring( uint32_t size ) :
            m_MaxSize( size ),
            m_Tail( 0 ),
            m_Head( 0 ),
            m_CommandBuffer( std::make_unique<uint32_t[]>( size ) )
        {
        }

        ////////////////////////////////////////////////////////////////////////////////
        Ring::~Ring()
        {
            m_CommandBuffer.release();
        }

        ////////////////////////////////////////////////////////////////////////////////
        void* Ring::GetAddress() const
        {
            return m_CommandBuffer.get();
        }

        ////////////////////////////////////////////////////////////////////////////////
        uint32_t Ring::GetMaxSize() const
        {
            return m_MaxSize;
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
            m_ProducerHead( -1 ),
            m_ConsumerHead( -1 ),
            m_ConsumerTail( -1 )
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
        void RenderRing::AdvanceProducer()
        {
            m_ProducerHead = ( m_ProducerHead + 1 ) % m_Rings.size();
        }

        ////////////////////////////////////////////////////////////////////////////////
        std::unique_ptr<Ring>& RenderRing::GetProducerRing()
        {
            return m_Rings[m_ProducerHead];
        }

        ////////////////////////////////////////////////////////////////////////////////
        void RenderRing::ProducerDone()
        {
            m_ConsumerTail = m_ProducerHead;
        }

        ////////////////////////////////////////////////////////////////////////////////
        bool RenderRing::IsEmpty() const
        {
            return m_ConsumerHead == m_ConsumerTail;
        }

        ////////////////////////////////////////////////////////////////////////////////
        void RenderRing::AdvanceConsumerHead()
        {
            if( !IsEmpty() )
            {
                m_ConsumerHead = ( m_ConsumerHead + 1 ) % m_Rings.size();
            }
        }

        ////////////////////////////////////////////////////////////////////////////////
        std::unique_ptr<Ring>& RenderRing::GetConsumerRing()
        {
            return m_Rings[m_ConsumerHead];
        }
    }
}