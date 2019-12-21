#include "pch.h"
#include "kmd_ring.h"

namespace Crystal
{
    namespace KMD
    {
        ////////////////////////////////////////////////////////////////////////////////
        RenderRing* RenderRing::Create( uint32_t size )
        {
            return new RenderRing( size );
        }

        ////////////////////////////////////////////////////////////////////////////////
        void RenderRing::Destroy( RenderRing* pRing )
        {
            if( pRing ) delete pRing;
        }

        ////////////////////////////////////////////////////////////////////////////////
        RenderRing::RenderRing( uint32_t size ) :
            m_Size( size ),
            m_pAllocationInfo( new GMM::ALLOCATION_INFO ),
            m_pHead( 0 ),
            m_pTail( 0 ),
            m_pEnd( 0 ),
            m_pAllocation( nullptr )
        {
            assert( m_pHead.is_lock_free() );
            assert( m_pTail.is_lock_free() );

            ZeroMemory( m_pAllocationInfo, sizeof( GMM::ALLOCATION_INFO ) );

            m_pAllocationInfo->ArraySlices      = 1;
            m_pAllocationInfo->Format           = DXGI_FORMAT::DXGI_FORMAT_R32_UINT;
            m_pAllocationInfo->IsInternal       = true;
            m_pAllocationInfo->MipLevels        = 1;
            m_pAllocationInfo->Mip0TexelWidth   = m_Size / 4;
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

            m_pHead = m_pAllocation->GetAddress();
            m_pTail = m_pAllocation->GetAddress();
            m_pEnd  = m_pAllocation->GetAddress() + m_pAllocation->GetSize();
        }

        ////////////////////////////////////////////////////////////////////////////////
        RenderRing::~RenderRing()
        {
            if( m_pAllocation )
            {
                Allocation::Destroy( m_pAllocation );
            }

            if( m_pAllocationInfo )
            {
                ZeroMemory( m_pAllocationInfo, sizeof( GMM::ALLOCATION_INFO ) );
                delete m_pAllocationInfo;
                m_pAllocationInfo = nullptr;
            }

            m_pHead = 0;
            m_pTail = 0;
            m_pEnd  = 0;
            m_Size  = 0;
        }

        ////////////////////////////////////////////////////////////////////////////////
        size_t RenderRing::GetHead() const
        {
            return m_pHead.load();
        }

        ////////////////////////////////////////////////////////////////////////////////
        size_t RenderRing::GetTail() const
        {
            return m_pTail.load();
        }

        ////////////////////////////////////////////////////////////////////////////////
        size_t RenderRing::GetEnd() const
        {
            return m_pEnd;
        }

        ////////////////////////////////////////////////////////////////////////////////
        uint32_t RenderRing::GetSize() const
        {
            return m_Size;
        }

        ////////////////////////////////////////////////////////////////////////////////
        uint32_t RenderRing::GetWriteDistance() const
        {
            uint32_t distance = ( m_pTail <= m_pHead )
                ? m_pEnd - m_pHead
                : m_pTail - m_pHead;

            return distance;
        }

        ////////////////////////////////////////////////////////////////////////////////
        void RenderRing::Advance( uint32_t offset, uint32_t length )
        {
            assert( m_pHead + offset + length <= m_pEnd );

            m_pHead += length;
        }
    }
}