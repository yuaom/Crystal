#pragma once

namespace Crystal
{
    namespace KMD
    {
        ////////////////////////////////////////////////////////////////////////////////
        /// @brief Abstract allocation descriptor
        struct GMM_ALLOCATION_INFO
        {
            enum RESOURCE_DIMENSION
            {
                RESOURCE_DIMENSION_LINEAR,
                RESOURCE_DIMENSION_1D,
                RESOURCE_DIMENSION_2D,
                RESOURCE_DIMENSION_3D
            };

            DXGI_FORMAT         Format;
            RESOURCE_DIMENSION  Dimension;
            uint32_t            MipLevels;
            uint32_t            ArraySlices;
            uint64_t            Size;
            bool                IsInternal;
            uint64_t            Address;
        };

        ////////////////////////////////////////////////////////////////////////////////
        struct D3DDDI_ALLOCATIONINFO_PRIVATE
        {
            GMM_ALLOCATION_INFO* pAllocationInfo;
        };
    }
}