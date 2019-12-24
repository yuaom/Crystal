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
                pContext->m_ProducerExiting = true;

                if( pContext->m_ConsumerThread.joinable() )
                {
                    pContext->m_ConsumerThread.join();
                }

                delete pContext;
            }
        }

        ////////////////////////////////////////////////////////////////////////////////
        Context::Context( D3DKMT_CREATECONTEXT* pCreateContext ) :
            m_ClientHint( pCreateContext->ClientHint ),
            m_Flags( pCreateContext->Flags ),
            m_pDevice( Device::FromHandle( pCreateContext->hDevice ) ),
            m_ProducerExiting( false ),
            m_hRasterContext( 0 )
        {
            //m_pRing = RenderRing::Create( 16 * KILOBYTE );
        }

        ////////////////////////////////////////////////////////////////////////////////
        Context::~Context()
        {
            //RenderRing::Destroy( m_pRing );
        }

        ////////////////////////////////////////////////////////////////////////////////
        bool Context::CreateRasterContext()
        {
            return m_pDevice->CreateContext( m_hRasterContext );
        }

        ////////////////////////////////////////////////////////////////////////////////
        //void Context::ConsumerStart( Context* pContext )
        //{
        //    RenderRing* pRenderRing = nullptr;

        //    while( !pContext->m_ProducerExiting )
        //    {
        //        if( pRenderRing == nullptr )
        //        {
        //            pRenderRing = pContext->GetRing();
        //        }
        //        else
        //        {
        //            if( !pRenderRing->Empty() )
        //            {
        //                uint32_t cmd = pRenderRing->Get();

        //                // do something with command
        //                std::stringstream s;
        //                s << "Consumer processed 0x" << std::hex << std::setw(8) << std::setfill('0') << cmd << std::endl;
        //                OutputDebugString( s.str().c_str() );
        //            }
        //            else
        //            {
        //                Sleep( 1 );
        //            }
        //        }
        //    }
        //}
    }
}