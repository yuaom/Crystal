#include "pch.h"

namespace Crystal
{
namespace UMD
{
namespace DDI
{

////////////////////////////////////////////////////////////////////////////////
VOID WINAPI SetDepthStencilState(
    D3D10DDI_HDEVICE hDevice,
    D3D10DDI_HDEPTHSTENCILSTATE hState,
    UINT StencilRef )
{
    LOG_DLL_ENTRY;
}
////////////////////////////////////////////////////////////////////////////////
VOID WINAPI CreateDepthStencilState(
    D3D10DDI_HDEVICE hDevice,
    const D3D10_DDI_DEPTH_STENCIL_DESC* pDepthStencilDesc,
    D3D10DDI_HDEPTHSTENCILSTATE hDepthStencilState,
    D3D10DDI_HRTDEPTHSTENCILSTATE hRTDepthStencilState )
{
    LOG_DLL_ENTRY;
}
////////////////////////////////////////////////////////////////////////////////
VOID WINAPI DestroyDepthStencilState(
    D3D10DDI_HDEVICE hDevice,
    D3D10DDI_HDEPTHSTENCILSTATE hDepthStencilState )
{
    LOG_DLL_ENTRY;
}

} // namespace DDI
} // namespace UMD
} // namespace Crystal
