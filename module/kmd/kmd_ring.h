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
            static RenderRing* Create( uint32_t size, uint32_t min_distance );

            static void Destroy( RenderRing* &pRing );

            bool        Empty() const;
            bool        Full() const;
            uint32_t    Capacity() const;
            uint32_t    Size() const;
            void        Put( uint32_t item );
            uint32_t    Get();

        private:

            RenderRing( uint32_t size, uint32_t min_distance );

            ~RenderRing();

            std::mutex              m_Mutex;
            uint32_t*               m_pBuffer;
            uint32_t                m_Head;
            uint32_t                m_Tail;
            uint32_t                m_MaxSize;
            bool                    m_IsFull;

            uint32_t                m_MinDistance;
            GMM::ALLOCATION_INFO*   m_pAllocationInfo;
            Allocation*             m_pAllocation;
        };
    }
}