#pragma once
#include "gmm.h"

namespace Crystal
{
    namespace UMD
    {
        ////////////////////////////////////////////////////////////////////////////////
        class Allocation
        {
        public:
            Allocation( D3DDDI_ALLOCATIONINFO* pAllocInfo );

            ~Allocation();

            D3DKMT_HANDLE   GetHandle() const;
            uint32_t        GetSize() const;

        private:
            D3DKMT_HANDLE                   m_Handle;
            D3DDDI_VIDEO_PRESENT_SOURCE_ID  m_VidPin;
            bool                            m_IsPrimary;
            bool                            m_IsStereo;
            
            GMM::ALLOCATION_INFO            m_Info;

            uint32_t    m_Size;
        };
    }
}