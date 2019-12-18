#pragma once

namespace Crystal
{
    namespace GMM
    {
        ////////////////////////////////////////////////////////////////////////////////
        /// @brief Resource dimension
        enum class RESOURCE_DIMENSION
        {
            UNKNOWN,
            LINEAR,
            _1D,
            _2D,
            _3D
        };

        ////////////////////////////////////////////////////////////////////////////////
        /// @brief Abstract allocation descriptor
        struct ALLOCATION_INFO
        {
            // @input
            uint32_t            Mip0TexelHeight;
            uint32_t            Mip0TexelWidth;
            uint32_t            Mip0TexelDepth;
            DXGI_FORMAT         Format;
            RESOURCE_DIMENSION  Dimension;
            uint32_t            MipLevels;
            uint32_t            ArraySlices;
            bool                IsInternal;

            // @create
            uint32_t            Size;
            uint32_t            BitsPerPixel;

            // @map
            uint64_t            Address;
        };

        void        CreateAllocationInfo( ALLOCATION_INFO* pInfo );

        uint32_t    GetBitsPerPixel( DXGI_FORMAT format );

        RESOURCE_DIMENSION  ConvertDDIResourceType( D3D10DDIRESOURCE_TYPE type );
    }
}