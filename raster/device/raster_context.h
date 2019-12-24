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
            static bool     Create( RASTERARGS_CREATECONTEXT* pCreateContextArgs );
            static void     Destroy();
            static Context* FromHandle( RASTERCONTEXT_HANDLE handle );

            constexpr RenderRing* GetRing() const;

        private:
            Context();
            ~Context();

            RenderRing* m_pRing;

            static void ConsumerStart( Context* pContext );
            std::atomic<bool>   m_ProducerExiting;
            std::thread         m_ConsumerThread;
        };

        ////////////////////////////////////////////////////////////////////////////////
        constexpr RenderRing* Context::GetRing() const
        {
            return m_pRing;
        }
    }
}