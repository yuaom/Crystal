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
            m_pResource( Resource::FromHandle( pCreateRenderTargetView->hDrvResource ) )
        {
            assert( m_pResource != nullptr );
        }

        ////////////////////////////////////////////////////////////////////////////////
        RenderTargetView::~RenderTargetView()
        {

        }
    }
}