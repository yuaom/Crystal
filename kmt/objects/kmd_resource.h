#pragma once
#include "kmd_allocation.h"

namespace Crystal
{
    namespace KMD
    {
        class Resource
        {
        public:

            static Resource*    Create( D3DKMT_CREATEALLOCATION* pCreateResource );
            static void         Destroy( D3DKMT_HANDLE handle );

            D3DKMT_HANDLE    GetHandle() const;

        private:

            Resource( D3DKMT_CREATEALLOCATION* pCreateResource );

            ~Resource();

            D3DKMT_HANDLE   m_Handle;

            std::vector<Allocation*>    m_Allocations;
        };
    }
}