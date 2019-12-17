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
            pCreateContext->hContext = pContext->GetHandle();

            return pContext;
        }

        ////////////////////////////////////////////////////////////////////////////////
        void Context::Destroy( D3DKMT_HANDLE handle )
        {
            Context* pAllocation = KmtHandleManager::To<Context>( handle );
            delete pAllocation;
        }

        ////////////////////////////////////////////////////////////////////////////////
        Context::Context( D3DKMT_CREATECONTEXT* pCreateContext ) :
            m_ClientHint( pCreateContext->ClientHint ),
            m_Flags( pCreateContext->Flags ),
            m_pDevice( nullptr )
        {

        }

        ////////////////////////////////////////////////////////////////////////////////
        Context::~Context()
        {
        }
    }
}