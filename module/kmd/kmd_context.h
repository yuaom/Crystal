#pragma once
#include "kmd_handles.h"
#include "kmd_device.h"

namespace Crystal
{
    namespace KMD
    {
        ////////////////////////////////////////////////////////////////////////////////
        class Context : public KmtObject<Context>
        {
        public:

            static Context* Create( D3DKMT_CREATECONTEXT* pCreateContext );
            static void     Destroy( D3DKMT_HANDLE handle );

            void RingDoorbell( uint32_t writeSize );
            void GetNextCommandBuffer( VOID*& pBuffer, UINT& maxSize );

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