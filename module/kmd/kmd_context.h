#pragma once
#include "kmd_handles.h"
#include "kmd_device.h"
#include "kmd_ring.h"

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

            constexpr RenderRing* GetRing() const;

        private:

            Context( D3DKMT_CREATECONTEXT* pCreateContext );

            ~Context( void );

            D3DKMT_CLIENTHINT           m_ClientHint;
            D3DDDI_CREATECONTEXTFLAGS   m_Flags;

            Device*     m_pDevice;

            RenderRing* m_pRing;
        };

        ////////////////////////////////////////////////////////////////////////////////
        constexpr RenderRing* Context::GetRing() const { return m_pRing; }
    }
}