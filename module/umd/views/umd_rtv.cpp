#include "pch.h"
#include "umd_rtv.h"

namespace Crystal
{
    namespace UMD
    {
        ////////////////////////////////////////////////////////////////////////////////
        RenderTargetView* RenderTargetView::Create( 
            const D3D10DDIARG_CREATERENDERTARGETVIEW* pCreateRenderTargetView,
            D3D10DDI_HRENDERTARGETVIEW hRenderTargetView,
            D3D10DDI_HRTRENDERTARGETVIEW hRTRenderTargetView )
        {
            RenderTargetView* pRTV = new( hRenderTargetView.pDrvPrivate ) RenderTargetView(
                pCreateRenderTargetView,
                hRTRenderTargetView );

            return pRTV;
        }

        ////////////////////////////////////////////////////////////////////////////////
        void RenderTargetView::Destroy(
            D3D10DDI_HRENDERTARGETVIEW hRenderTargetView )
        {
            // Nothing to do
        }

        ////////////////////////////////////////////////////////////////////////////////
        RenderTargetView* RenderTargetView::FromHandle(
            D3D10DDI_HRENDERTARGETVIEW handle )
        {
            return reinterpret_cast<RenderTargetView*>( handle.pDrvPrivate );
        }

        ////////////////////////////////////////////////////////////////////////////////
        RenderTargetView::RenderTargetView( 
            const D3D10DDIARG_CREATERENDERTARGETVIEW* pCreateRenderTargetView,
            D3D10DDI_HRTRENDERTARGETVIEW hRuntimeHandle ) :
            m_RuntimeHandle( hRuntimeHandle ),
            m_pResource( Resource::FromHandle( pCreateRenderTargetView->hDrvResource ) ),
            m_Format( pCreateRenderTargetView->Format ),
            m_Type( pCreateRenderTargetView->ResourceDimension )
        {
            assert( m_pResource != nullptr );

            ZeroMemory( &m_View, sizeof( RasterCommands::SURFACE_VIEW ) );

            switch( m_Type )
            {
            case D3D10DDIRESOURCE_BUFFER:
                break;
            case D3D10DDIRESOURCE_TEXTURE1D:
                break;
            case D3D10DDIRESOURCE_TEXTURE2D:
                m_View.Address = m_pResource->GetAddress();
                m_View.Type    = RasterCommands::SURFACE_TYPE::_2D;
                break;
            case D3D10DDIRESOURCE_TEXTURE3D:
                break;
            case D3D10DDIRESOURCE_TEXTURECUBE:
                break;
            default:
                assert( 0 );
            }
        }

        ////////////////////////////////////////////////////////////////////////////////
        RenderTargetView::~RenderTargetView()
        {

        }

        ////////////////////////////////////////////////////////////////////////////////
        const RasterCommands::SURFACE_VIEW& RenderTargetView::GetView()
        {
            return m_View;
        }
    }
}