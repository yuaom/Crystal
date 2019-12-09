#include "pch.h"

namespace Crystal
{
namespace UMD
{
namespace DDI
{

////////////////////////////////////////////////////////////////////////////////
VOID WINAPI SetRenderTargets(
    D3D10DDI_HDEVICE hDevice,
    const D3D10DDI_HRENDERTARGETVIEW* phRenderTargetView,
    UINT NumRTVs,
    UINT RTVNumbertoUnbind,
    D3D10DDI_HDEPTHSTENCILVIEW hDepthStencilView,
    const D3D11DDI_HUNORDEREDACCESSVIEW* phUnorderedAccessView,
    const UINT* pUAVInitialCounts,
    UINT UAVStartSlot,
    UINT NumUAVs,
    UINT UAVRangeStart,
    UINT UAVRangeSize )
{
    LOG_DLL_ENTRY;
}
////////////////////////////////////////////////////////////////////////////////
VOID WINAPI ClearRenderTargetView(
    D3D10DDI_HDEVICE hDevice,
    D3D10DDI_HRENDERTARGETVIEW pColorRGBA,
    FLOAT hRenderTargetView[4] )
{
    LOG_DLL_ENTRY;
}
////////////////////////////////////////////////////////////////////////////////
VOID WINAPI CreateRenderTargetView(
    D3D10DDI_HDEVICE hDevice,
    const D3D10DDIARG_CREATERENDERTARGETVIEW* pCreateRenderTargetView,
    D3D10DDI_HRENDERTARGETVIEW hRenderTargetView,
    D3D10DDI_HRTRENDERTARGETVIEW hRTRenderTargetView )
{
    LOG_DLL_ENTRY;
}
////////////////////////////////////////////////////////////////////////////////
VOID WINAPI DestroyRenderTargetView(
    D3D10DDI_HDEVICE hDevice,
    D3D10DDI_HRENDERTARGETVIEW hRenderTargetView )
{
    LOG_DLL_ENTRY;
}

} // namespace DDI
} // namespace UMD
} // namespace Crystal
