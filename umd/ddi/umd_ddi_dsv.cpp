#include "pch.h"

namespace Crystal
{
namespace UMD
{
namespace DDI
{

////////////////////////////////////////////////////////////////////////////////
VOID WINAPI CreateDepthStencilView(
    D3D10DDI_HDEVICE hDevice,
    const D3D11DDIARG_CREATEDEPTHSTENCILVIEW* pCreateDepthStencilView,
    D3D10DDI_HDEPTHSTENCILVIEW hDepthStencilView,
    D3D10DDI_HRTDEPTHSTENCILVIEW hRTDepthStencilView )
{
    LOG_DLL_ENTRY;
}

////////////////////////////////////////////////////////////////////////////////
VOID WINAPI DestroyDepthStencilView(
    D3D10DDI_HDEVICE hDevice,
    D3D10DDI_HDEPTHSTENCILVIEW hDepthStencilView )
{
    LOG_DLL_ENTRY;
}

} // namespace DDI
} // namespace UMD
} // namespace Crystal
