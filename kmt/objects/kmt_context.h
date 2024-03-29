#pragma once
#include "kmt_handles.h"
#include "kmt_device.h"

namespace Crystal
{
    namespace KMT
    {
        ////////////////////////////////////////////////////////////////////////////////
        class Context : public KmtObject<Context>
        {
        public:

            static Context* Create( D3DKMT_CREATECONTEXT* pCreateContext );
            static void     Destroy( D3DKMT_HANDLE handle );

            void RingDoorbell( uint32_t writeSize );
            void GetNextCommandBuffer( VOID*& pBuffer, UINT& maxSize );

            __declspec( align( 64 ) ) volatile LONG64   m_RenderFenceGPU;
            __declspec( align( 64 ) ) LONG64            m_RenderFenceCPU;

            void*           m_pCurrentCommandBuffer;

            struct RenderEpilog
            {
                Crystal::Raster::COMMANDS::ATOMIC_WRITE fenceUpdate;
            };

        private:

            Context( D3DKMT_CREATECONTEXT* pCreateContext );

            ~Context( void );

            bool CreateRasterContext();

            D3DKMT_CLIENTHINT           m_ClientHint;
            D3DDDI_CREATECONTEXTFLAGS   m_Flags;

            Device*     m_pDevice;

            RASTERCONTEXT_HANDLE    m_hRasterContext;
        };
    }
}