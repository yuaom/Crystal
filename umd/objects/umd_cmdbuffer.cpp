#include "pch.h"
#include "umd_cmdbuffer.h"
#include "kmt_privatedata.h"

namespace Crystal
{
    namespace UMD
    {
        ////////////////////////////////////////////////////////////////////////////////
        CommandBuffer* CommandBuffer::Create( 
            Device* pDevice,
            uint32_t size )
        {
            CommandBuffer* pCmdBuffer = new CommandBuffer( false, pDevice );

            if( size )
            {
                pCmdBuffer->Allocate( size );
            }

            return pCmdBuffer;
        }

        ////////////////////////////////////////////////////////////////////////////////
        CommandBuffer* CommandBuffer::Create(
            size_t placement, 
            uint32_t size )
        {
            CommandBuffer* pCmdBuffer = new CommandBuffer( true, nullptr );

            pCmdBuffer->m_pBuffer   = reinterpret_cast<byte*>( placement );
            pCmdBuffer->m_SizeTotal = size;

            return pCmdBuffer;
        }

        ////////////////////////////////////////////////////////////////////////////////
        void CommandBuffer::Destroy( CommandBuffer* pCmdBuffer )
        {
            if( pCmdBuffer &&
                !pCmdBuffer->m_IsPlaced )
            {
                delete pCmdBuffer;
            }
        }

        ////////////////////////////////////////////////////////////////////////////////
        CommandBuffer::CommandBuffer( bool isPlaced, Device* pDevice ) :
            m_pDevice( pDevice ),
            m_pBuffer( nullptr ),
            m_SizeUsed( 0 ),
            m_SizeTotal( 0 ),
            m_pAllocationInfo( nullptr ),
            m_AllocationHandle( 0 ),
            m_IsPlaced( isPlaced )
        {
        }

        ////////////////////////////////////////////////////////////////////////////////
        CommandBuffer::~CommandBuffer()
        {
            if( m_pAllocationInfo )
            {
                ZeroMemory( m_pAllocationInfo, sizeof( GMM::ALLOCATION_INFO ) );
                delete m_pAllocationInfo;
            }
        }

        ////////////////////////////////////////////////////////////////////////////////
        void CommandBuffer::Allocate( uint32_t size )
        {
            // Create allocation info
            m_pAllocationInfo = new GMM::ALLOCATION_INFO;
            ZeroMemory( m_pAllocationInfo, sizeof( GMM::ALLOCATION_INFO ) );

            m_pAllocationInfo->ArraySlices      = 1;
            m_pAllocationInfo->Format           = DXGI_FORMAT::DXGI_FORMAT_R32_UINT;
            m_pAllocationInfo->IsInternal       = true;
            m_pAllocationInfo->MipLevels        = 1;
            m_pAllocationInfo->Mip0TexelWidth   = size;
            m_pAllocationInfo->Mip0TexelHeight  = 1;
            m_pAllocationInfo->Mip0TexelDepth   = 1;
            m_pAllocationInfo->Dimension        = GMM::RESOURCE_DIMENSION::BUFFER;

            GMM::CreateAllocationInfo( m_pAllocationInfo );

            KMT::D3DDDI_ALLOCATIONINFO_PRIVATE allocInfoPrivateData;
            ZeroMemory( &allocInfoPrivateData, sizeof( KMT::D3DDDI_ALLOCATIONINFO_PRIVATE ) );
            allocInfoPrivateData.pAllocationInfo = m_pAllocationInfo;

            D3DDDI_ALLOCATIONINFO allocInfo;
            ZeroMemory( &allocInfo, sizeof( D3DDDI_ALLOCATIONINFO ) );

            allocInfo.pPrivateDriverData    = &allocInfoPrivateData;
            allocInfo.PrivateDriverDataSize = sizeof( KMT::D3DDDI_ALLOCATIONINFO_PRIVATE );

            D3DDDICB_ALLOCATE allocate = { 0 };
            allocate.NumAllocations     = 1;
            allocate.pAllocationInfo    = &allocInfo;

            m_pDevice->Allocate( allocate );

            m_AllocationHandle = allocInfo.hAllocation;

            m_SizeUsed  = 0;
            m_SizeTotal = size;
            m_pBuffer   = reinterpret_cast<byte*>( m_pAllocationInfo->Address );
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

        ////////////////////////////////////////////////////////////////////////////////
        size_t CommandBuffer::GetAddress() const
        {
            return reinterpret_cast<size_t>( m_pBuffer );
        }
    }
}