#pragma once
#include "kmd_allocation.h"
#include "gmm.h"

namespace Crystal
{
    namespace KMD
    {
        ////////////////////////////////////////////////////////////////////////////////
        class RenderRing
        {
        public:
            static RenderRing* Create( uint32_t size );

            static void Destroy( RenderRing* ring );

            size_t      GetHead() const;
            size_t      GetTail() const;
            uint32_t    GetWriteDistance() const;

            void        Advance( uint32_t offset, uint32_t length );

        private:
            RenderRing( uint32_t size );

            ~RenderRing();

            std::atomic_size_t      m_pHead;
            std::atomic_size_t      m_pTail;
            size_t                  m_pEnd;
            const uint32_t          m_Size;
            GMM::ALLOCATION_INFO*   m_pAllocationInfo;
            Allocation*             m_pAllocation;
        };
    }
}