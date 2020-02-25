#pragma once
#include "objects\umd_resource.h"

namespace Crystal
{
    namespace UMD
    {
        ////////////////////////////////////////////////////////////////////////////////
        class RenderTargetView
        {
        public:
            static RenderTargetView*    Create( 
                const D3D10DDIARG_CREATERENDERTARGETVIEW* pCreateRenderTargetView,
                D3D10DDI_HRENDERTARGETVIEW hRenderTargetView,
                D3D10DDI_HRTRENDERTARGETVIEW hRTRenderTargetView );

            static void                 Destroy(
                D3D10DDI_HRENDERTARGETVIEW hRenderTargetView );

            static RenderTargetView*    FromHandle( D3D10DDI_HRENDERTARGETVIEW handle );
            static constexpr uint32_t   CalculateSize();

            constexpr Resource*  GetResource() const;

            const RasterCommands::SURFACE_VIEW& GetView();

        private:
            RenderTargetView( 
                const D3D10DDIARG_CREATERENDERTARGETVIEW* pCreateRenderTargetView, 
                D3D10DDI_HRTRENDERTARGETVIEW hRuntimeHandle );
            ~RenderTargetView();

            D3D10DDI_HRTRENDERTARGETVIEW    m_RuntimeHandle;

            Resource*                       m_pResource;

            // Creation parameters
            DXGI_FORMAT                     m_Format;
            D3D10DDIRESOURCE_TYPE           m_Type;

            // HW State
            RasterCommands::SURFACE_VIEW    m_View;
        };

        ////////////////////////////////////////////////////////////////////////////////
        constexpr uint32_t RenderTargetView::CalculateSize()
        {
            return sizeof( RenderTargetView );
        }

        ////////////////////////////////////////////////////////////////////////////////
        constexpr Resource* RenderTargetView::GetResource() const
        {
            return m_pResource;
        }
    }
}