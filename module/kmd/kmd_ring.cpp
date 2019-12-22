#include "pch.h"
#include "kmd_ring.h"

namespace Crystal
{
    namespace KMD
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
            m_MaxSize( size ),
            m_pAllocationInfo( new GMM::ALLOCATION_INFO ),
            m_Head( 0 ),
            m_Tail( 0 ),
            m_pAllocation( nullptr ),
            m_pBuffer( nullptr ),
            m_IsFull( false )
        {
            assert( size % sizeof( uint32_t ) == 0 );
            ZeroMemory( m_pAllocationInfo, sizeof( GMM::ALLOCATION_INFO ) );

            m_pAllocationInfo->ArraySlices      = 1;
            m_pAllocationInfo->Format           = DXGI_FORMAT::DXGI_FORMAT_R8_UINT;
            m_pAllocationInfo->IsInternal       = true;
            m_pAllocationInfo->MipLevels        = 1;
            m_pAllocationInfo->Mip0TexelWidth   = m_MaxSize;
            m_pAllocationInfo->Mip0TexelHeight  = 1;
            m_pAllocationInfo->Mip0TexelDepth   = 1;
            m_pAllocationInfo->Dimension        = GMM::RESOURCE_DIMENSION::BUFFER;

            GMM::CreateAllocationInfo( m_pAllocationInfo );

            D3DDDI_ALLOCATIONINFO_PRIVATE data;
            data.pAllocationInfo = m_pAllocationInfo;

            D3DDDI_ALLOCATIONINFO allocInfo;
            ZeroMemory( &allocInfo, sizeof( D3DDDI_ALLOCATIONINFO ) );
            allocInfo.pPrivateDriverData    = &data;
            allocInfo.PrivateDriverDataSize = sizeof( D3DDDI_ALLOCATIONINFO_PRIVATE );

            m_pAllocation = Allocation::Create( &allocInfo );

            m_pBuffer = reinterpret_cast<byte*>( m_pAllocation->GetAddress() );
        }

        ////////////////////////////////////////////////////////////////////////////////
        RenderRing::~RenderRing()
        {
            Allocation::Destroy( m_pAllocation );

            if( m_pAllocationInfo )
            {
                ZeroMemory( m_pAllocationInfo, sizeof( GMM::ALLOCATION_INFO ) );
                delete m_pAllocationInfo;
                m_pAllocationInfo = nullptr;
            }
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
            m_Head = 0;
        }

        ////////////////////////////////////////////////////////////////////////////////
        void RenderRing::Put( byte item )
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
        byte* RenderRing::Checkout()
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
        byte RenderRing::Get()
        {
            std::lock_guard<std::mutex> lock( m_Mutex );

            if( Empty() ) return 0;

            byte value = m_pBuffer[ m_Tail ];

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