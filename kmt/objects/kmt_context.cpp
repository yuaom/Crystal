#include "pch.h"
#include "kmt_context.h"


namespace Crystal
{
    namespace KMT
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

                pContext->GetNextCommandBuffer(
                    pCreateContext->pCommandBuffer,
                    pCreateContext->CommandBufferSize );
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
            m_hRasterContext( 0 ),
            m_RenderFenceGPU( 0 ),
            m_RenderFenceCPU( 0 ),
            m_pCurrentCommandBuffer( nullptr )
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

        ////////////////////////////////////////////////////////////////////////////////
        void Context::RingDoorbell( uint32_t writeSize )
        {
            m_pDevice->GetRasterFuncs()->pfnRingDoorbell(
                m_hRasterContext,
                writeSize );
        }

        ////////////////////////////////////////////////////////////////////////////////
        void Context::GetNextCommandBuffer( VOID*& pBuffer, UINT& maxSize )
        {
            m_pDevice->GetRasterFuncs()->pfnGetNextCommandBuffer(
                m_hRasterContext,
                pBuffer,
                maxSize );

            m_pCurrentCommandBuffer = pBuffer;
        }
    }
}