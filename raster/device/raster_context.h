#pragma once
#include "fe_ring.h"

namespace Crystal
{
    namespace Raster
    {
        ////////////////////////////////////////////////////////////////////////////////
        class Context
        {
        public:
            static bool Create( RASTERARGS_CREATECONTEXT* pCreateContextArgs );
            static void Destroy();

        private:
            Context();
            ~Context();

            RenderRing* m_pRing;

            static void ConsumerStart( Context* pContext );
            std::atomic<bool>   m_ProducerExiting;
            std::thread         m_ConsumerThread;
        };
    }
}