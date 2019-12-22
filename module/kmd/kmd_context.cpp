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

            // Populate DDI Return Arguments
            //pCreateContext->hContext            = pContext->GetHandle();
            //pCreateContext->pCommandBuffer      = reinterpret_cast<void*>( pContext->GetRing()->GetNextCommandBufferAddress() );
            //pCreateContext->CommandBufferSize   = pContext->GetRing()->GetNextCommandBufferSize();

            return pContext;
        }

        ////////////////////////////////////////////////////////////////////////////////
        void Context::Destroy( D3DKMT_HANDLE handle )
        {
            Context* pContext = KmtHandleManager::To<Context>( handle );

            if( pContext )
            {
                delete pContext;
            }
        }

        ////////////////////////////////////////////////////////////////////////////////
        Context::Context( D3DKMT_CREATECONTEXT* pCreateContext ) :
            m_ClientHint( pCreateContext->ClientHint ),
            m_Flags( pCreateContext->Flags ),
            m_pDevice( nullptr ),
            m_pRing( nullptr )
        {
            m_pRing = RenderRing::Create( 32 * PAGE_SIZE, PAGE_SIZE );
        }

        ////////////////////////////////////////////////////////////////////////////////
        Context::~Context()
        {
            RenderRing::Destroy( m_pRing );
        }
    }
}