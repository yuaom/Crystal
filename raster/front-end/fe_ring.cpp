#include "pch.h"
#include "fe_ring.h"

namespace Crystal
{
    namespace Raster
    {
        ////////////////////////////////////////////////////////////////////////////////
        RenderRing* RenderRing::Create( 
            uint32_t size )
        {
            return new RenderRing( size );
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
        RenderRing::RenderRing( uint32_t size ) :
            m_MaxSize( size / sizeof(uint32_t) ),
            m_Head( 0 ),
            m_Tail( 0 ),
            m_pBuffer( nullptr ),
            m_IsFull( false )
        {
            assert( size % sizeof( uint32_t ) == 0 );

            m_pBuffer = std::make_unique<uint32_t[]>( m_MaxSize );
        }

        ////////////////////////////////////////////////////////////////////////////////
        RenderRing::~RenderRing()
        {
            m_pBuffer.release();
        }

        ////////////////////////////////////////////////////////////////////////////////
        bool RenderRing::Empty() const
        {
            return !m_IsFull && ( m_Head == m_Tail );
        }

        ////////////////////////////////////////////////////////////////////////////////
        bool RenderRing::Full() const
        {
            return m_IsFull;
        }

        ////////////////////////////////////////////////////////////////////////////////
        uint32_t RenderRing::Capacity() const
        {
            return m_MaxSize;
        }

        ////////////////////////////////////////////////////////////////////////////////
        uint32_t RenderRing::Size() const
        {
            uint32_t size = m_MaxSize;

            if( !m_IsFull )
            {
                if( m_Head > m_Tail )
                {
                    size = m_Head - m_Tail;
                }
                else
                {
                    size = m_MaxSize + m_Head - m_Tail;
                }
            }

            return size;
        }

        ////////////////////////////////////////////////////////////////////////////////
        void RenderRing::ResetHead()
        {
            std::lock_guard<std::mutex> lock( m_Mutex );
            uint32_t remaining = ( m_MaxSize - m_Head ) * sizeof( uint32_t );
            ZeroMemory( &m_pBuffer[m_Head], remaining );
            m_Head = 0;
        }

        ////////////////////////////////////////////////////////////////////////////////
        void RenderRing::Put( uint32_t item )
        {
            std::lock_guard<std::mutex> lock( m_Mutex );

            m_pBuffer[ m_Head ] = item;

            if( m_IsFull )
            {
                m_Tail = ( m_Tail + 1 ) % m_MaxSize;
            }

            m_Head = ( m_Head + 1 ) % m_MaxSize;

            m_IsFull = m_Head == m_Tail;
        }

        ////////////////////////////////////////////////////////////////////////////////
        uint32_t* RenderRing::Checkout()
        {
            return &m_pBuffer[m_Head];
        }

        ////////////////////////////////////////////////////////////////////////////////
        uint32_t RenderRing::CheckoutSize()
        {
            uint32_t size = ( m_Tail <= m_Head )
                ? m_MaxSize - m_Head
                : m_Tail - m_Head;
            return size;
        }

        ////////////////////////////////////////////////////////////////////////////////
        void RenderRing::Commit( uint32_t size )
        {
            std::lock_guard<std::mutex> lock( m_Mutex );

            if( m_IsFull )
            {
                m_Tail = ( m_Tail + size ) % m_MaxSize;
            }

            m_Head = ( m_Head + size ) % m_MaxSize;

            m_IsFull = m_Head == m_Tail;
        }

        ////////////////////////////////////////////////////////////////////////////////
        uint32_t RenderRing::Get()
        {
            std::lock_guard<std::mutex> lock( m_Mutex );

            if( Empty() ) return 0;

            uint32_t value = m_pBuffer[ m_Tail ];

            m_IsFull = false;
            m_Tail = ( m_Tail + 1 ) % m_MaxSize;

            return value;
        }

        ////////////////////////////////////////////////////////////////////////////////
        uint32_t RenderRing::Head() const
        {
            return m_Head;
        }

        ////////////////////////////////////////////////////////////////////////////////
        uint32_t RenderRing::Tail() const
        {
            return m_Tail;
        }
    }
}