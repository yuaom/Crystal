#pragma once
#include "kmd_handles.h"
#include "kmd_device.h"
#include "kmd_allocation.h"
#include "gmm.h"

namespace Crystal
{
    namespace KMD
    {
        ////////////////////////////////////////////////////////////////////////////////
        class Context : public KmtObject
        {
        public:

            static Context* Create( D3DKMT_CREATECONTEXT* pCreateContext );

            static void Destroy( D3DKMT_HANDLE handle );

        private:

            Context( D3DKMT_CREATECONTEXT* pCreateContext );

            ~Context( void );

            void CreateRenderRing();

            D3DKMT_CLIENTHINT           m_ClientHint;
            D3DDDI_CREATECONTEXTFLAGS   m_Flags;

            Device*     m_pDevice;

            // RenderRing
            GMM::ALLOCATION_INFO*   m_pAllocationInfo;
            Allocation*             m_pRing;
        };
    }
}