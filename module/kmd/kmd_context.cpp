#include "pch.h"
#include "kmd_context.h"


namespace Crystal
{
    namespace KMD
    {
        ////////////////////////////////////////////////////////////////////////////////
        Context* Context::Create( D3DKMT_CREATECONTEXT* pCreateContext )
        {
            bool success = true;

            Context* pContext = new Context( pCreateContext );

            if( success )
            {
                success = pContext->CreateRasterContext();
            }

            if( success )
            {
                // Populate DDI Return Arguments
                pCreateContext->hContext = pContext->GetHandle();
                //pCreateContext->pCommandBuffer      = reinterpret_cast<void*>( pContext->GetRing()->Checkout() );
                //pCreateContext->CommandBufferSize   = pContext->GetRing()->CheckoutSize();
            }

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
            m_pDevice( Device::FromHandle( pCreateContext->hDevice ) ),
            m_hRasterContext( 0 )
        {
            
        }

        ////////////////////////////////////////////////////////////////////////////////
        Context::~Context()
        {

        }

        ////////////////////////////////////////////////////////////////////////////////
        bool Context::CreateRasterContext()
        {
            return m_pDevice->CreateContext( m_hRasterContext );
        }
    }
}