#include "pch.h"
#include "kmd_context.h"


namespace Crystal
{
    namespace KMD
    {
        ////////////////////////////////////////////////////////////////////////////////
        Context* Context::Create( D3DKMT_CREATECONTEXT* pCreateContext )
        {
            Context* pContext = new Context( pCreateContext );

            pContext->CreateRenderRing();

            // Populate DDI Return Arguments
            pCreateContext->hContext            = pContext->GetHandle();
            pCreateContext->pCommandBuffer      = reinterpret_cast<void*>( pContext->m_pRing->GetAddress() );
            pCreateContext->CommandBufferSize   = pContext->m_pRing->GetSize();

            return pContext;
        }

        ////////////////////////////////////////////////////////////////////////////////
        void Context::Destroy( D3DKMT_HANDLE handle )
        {
            Context* pContext = KmtHandleManager::To<Context>( handle );
            delete pContext;
        }

        ////////////////////////////////////////////////////////////////////////////////
        Context::Context( D3DKMT_CREATECONTEXT* pCreateContext ) :
            m_ClientHint( pCreateContext->ClientHint ),
            m_Flags( pCreateContext->Flags ),
            m_pDevice( nullptr ),
            m_pRing( nullptr ),
            m_pAllocationInfo( new GMM::ALLOCATION_INFO )
        {
            ZeroMemory( m_pAllocationInfo, sizeof( GMM::ALLOCATION_INFO ) );

            m_pAllocationInfo->ArraySlices      = 1;
            m_pAllocationInfo->Format           = DXGI_FORMAT::DXGI_FORMAT_R32_UINT;
            m_pAllocationInfo->IsInternal       = true;
            m_pAllocationInfo->MipLevels        = 1;
            m_pAllocationInfo->Mip0TexelWidth   = PAGE_SIZE / 4;
            m_pAllocationInfo->Mip0TexelHeight  = 1;
            m_pAllocationInfo->Mip0TexelDepth   = 1;
            m_pAllocationInfo->Dimension        = GMM::RESOURCE_DIMENSION::BUFFER;

            GMM::CreateAllocationInfo( m_pAllocationInfo );
        }

        ////////////////////////////////////////////////////////////////////////////////
        Context::~Context()
        {
            ZeroMemory( m_pAllocationInfo, sizeof( GMM::ALLOCATION_INFO ) );
            delete m_pAllocationInfo;
        }

        ////////////////////////////////////////////////////////////////////////////////
        void Context::CreateRenderRing()
        {
            assert( m_pRing == nullptr );

            D3DDDI_ALLOCATIONINFO_PRIVATE data;
            data.pAllocationInfo = m_pAllocationInfo;

            D3DDDI_ALLOCATIONINFO allocInfo;
            ZeroMemory( &allocInfo, sizeof( D3DDDI_ALLOCATIONINFO ) );
            allocInfo.pPrivateDriverData    = &data;
            allocInfo.PrivateDriverDataSize = sizeof( D3DDDI_ALLOCATIONINFO_PRIVATE );

            m_pRing = Allocation::Create( &allocInfo );
        }
    }
}