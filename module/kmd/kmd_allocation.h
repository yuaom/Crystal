#pragma once
#include "gmm.h"
#include "kmd_privatedata.h"
#include "kmd_handles.h"

namespace Crystal
{
    namespace KMD
    {
        class Allocation : public KmtObject<Allocation>
        {
        public:

            static Allocation* Create( D3DDDI_ALLOCATIONINFO* pInfo );
            static void Destroy( Allocation* &pAllocation );

            D3DKMT_HANDLE   GetHandle() const;
            size_t          GetAddress() const;
            size_t          GetSize() const;
            uint32_t        GetWidth() const;
            uint32_t        GetHeight() const;
            uint32_t        GetBitsPerPixel() const;

        private:

            Allocation( D3DDDI_ALLOCATIONINFO* pInfo );

            ~Allocation( void );

            void Allocate();
            void Deallocate();

            D3DKMT_HANDLE           m_Handle;
            GMM::ALLOCATION_INFO*   m_pAllocationInfo;
        };
    }
}