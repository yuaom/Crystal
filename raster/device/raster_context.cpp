#include "pch.h"
#include "cmds.h"
#include "fe_parser.h"
#include "raster_context.h"

namespace Crystal
{
    namespace Raster
    {
        ////////////////////////////////////////////////////////////////////////////////
        bool Context::Create( RASTERARGS_CREATECONTEXT* pCreateContextArgs )
        {
            bool success = true;

            Context* pContext = new Context();

            pCreateContextArgs->hHandle = reinterpret_cast<RASTERCONTEXT_HANDLE>( pContext );

            return success;
        }

        ////////////////////////////////////////////////////////////////////////////////
        void Context::Destroy()
        {

        }

        ////////////////////////////////////////////////////////////////////////////////
        Context::Context() :
            m_pRenderRing( RenderRing::Create( 8, 64 * KILOBYTE ) ),
            m_ProducerExiting( false ),
            m_ConsumerThread( ConsumerStart, this )
        {

        }

        ////////////////////////////////////////////////////////////////////////////////
        Context::~Context()
        {
            m_ProducerExiting = true;

            if( m_ConsumerThread.joinable() )
            {
                m_ConsumerThread.join();
            }

            RenderRing::Destroy( m_pRenderRing );
        }

        ////////////////////////////////////////////////////////////////////////////////
        Context* Context::FromHandle( RASTERCONTEXT_HANDLE handle )
        {
            return reinterpret_cast<Context*>( handle );
        }

        ////////////////////////////////////////////////////////////////////////////////
        void Context::ConsumerStart( Context* pContext )
        {
            Utilities::SetThreadName( "CrystalRaster-Consumer" );

            RenderRing*& pRenderRing = pContext->m_pRenderRing;

            while( !pContext->m_ProducerExiting )
            {
                if( pRenderRing->HasWork() )
                {
                    pRenderRing->AdvanceReadHead();

                    Ring::ptr_t& pRing = pRenderRing->GetRead();
                    uint32_t* pCommand = pRing->GetAddress();
                    uint32_t  count = pRing->GetCommandCount();

                    assert( count > 0 );

                    while( count )
                    {
                        COMMANDS::Header* pCommandHeader = reinterpret_cast<COMMANDS::Header*>( pCommand );

                        Execute( pCommandHeader );

                        pCommand    += pCommandHeader->Length;
                        count       -= pCommandHeader->Length;
                    }
                }
                else
                {
                    Sleep( 1 );
                }
            }
        }
    }
}