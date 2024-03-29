#include "pch.h"
#include "objects\umd_device.h"
#include "objects\umd_encoder.h"
#include "views\umd_rtv.h"

namespace Crystal
{
namespace UMD
{
namespace DDI
{

////////////////////////////////////////////////////////////////////////////////
VOID WINAPI ClearDepthStencilView(
    D3D10DDI_HDEVICE hDevice,
    D3D10DDI_HDEPTHSTENCILVIEW hDepthStencilView,
    UINT Stencil,
    FLOAT Depth,
    UINT8 Flags )
{
    LOG_DLL_ENTRY;
}

////////////////////////////////////////////////////////////////////////////////
VOID WINAPI ClearRenderTargetView(
    D3D10DDI_HDEVICE hDevice,
    D3D10DDI_HRENDERTARGETVIEW hRenderTargetView,
    FLOAT pColorRGBA[4] )
{
    LOG_DLL_ENTRY;

    Device* pDevice = Device::FromHandle( hDevice );
    Encoder* pEncoder = pDevice->GetEncoder();
    RenderTargetView* pRTV = RenderTargetView::FromHandle( hRenderTargetView );

    RasterCommands::CLEAR_RENDER_TARGET_VIEW clear;

    clear.View              = pRTV->GetView();
    clear.ClearValues[0]    = pColorRGBA[0];
    clear.ClearValues[1]    = pColorRGBA[1];
    clear.ClearValues[2]    = pColorRGBA[2];
    clear.ClearValues[3]    = pColorRGBA[3];

    pEncoder->Encode( clear );
}

////////////////////////////////////////////////////////////////////////////////
VOID WINAPI ClearUnorderedAccessViewFloat(
    D3D10DDI_HDEVICE hDevice,
    D3D11DDI_HUNORDEREDACCESSVIEW hUnorderedAccessView,
    const FLOAT FLOAT[4] )
{
    LOG_DLL_ENTRY;
}

////////////////////////////////////////////////////////////////////////////////
VOID WINAPI ClearUnorderedAccessViewUint(
    D3D10DDI_HDEVICE hDevice,
    D3D11DDI_HUNORDEREDACCESSVIEW hUnorderedAccessView,
    const UINT UINT[4] )
{
    LOG_DLL_ENTRY;
}

////////////////////////////////////////////////////////////////////////////////
VOID WINAPI ClearView(
    D3D10DDI_HDEVICE hDevice,
    D3D11DDI_HANDLETYPE viewType,
    void* hView,
    const FLOAT Color[4],
    const D3D10_DDI_RECT* pRect,
    UINT NumRects )
{
    LOG_DLL_ENTRY;
}

} // namespace DDI
} // namespace UMD
} // namespace Crystal
