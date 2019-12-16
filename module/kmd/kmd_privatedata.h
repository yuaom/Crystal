#pragma once

namespace Crystal
{
    namespace KMD
    {
        ////////////////////////////////////////////////////////////////////////////////
        struct GMM_ALLOCATION_INFO
        {
            uint64_t    SizeInBytes;
            uint64_t    Address;
        };

        ////////////////////////////////////////////////////////////////////////////////
        struct D3DDDI_ALLOCATIONINFO_PRIVATE
        {
            GMM_ALLOCATION_INFO* pAllocationInfo;
        };
    }
}