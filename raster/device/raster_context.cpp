#include "pch.h"
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

                    //std::stringstream s;
                    //s << "Consumer processed 0x" << std::hex << std::setw(8) << std::setfill('0') << cmd << std::endl;
                    //OutputDebugString( s.str().c_str() );
                }
                else
                {
                    Sleep( 1 );
                }
            }
        }
    }
}