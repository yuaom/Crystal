#include "pch.h"

namespace Crystal
{
namespace UMD
{
namespace DDI
{

////////////////////////////////////////////////////////////////////////////////
VOID WINAPI PsSetShaderResources(
    D3D10DDI_HDEVICE hDevice,
    UINT StartSlot,
    UINT NumViews,
    const D3D10DDI_HSHADERRESOURCEVIEW* phShaderResourceViews )
{
    LOG_DLL_ENTRY;
}
////////////////////////////////////////////////////////////////////////////////
VOID WINAPI VsSetShaderResources(
    D3D10DDI_HDEVICE hDevice,
    UINT StartSlot,
    UINT NumViews,
    const D3D10DDI_HSHADERRESOURCEVIEW* phShaderResourceViews )
{
    LOG_DLL_ENTRY;
}
////////////////////////////////////////////////////////////////////////////////
VOID WINAPI GsSetShaderResources(
    D3D10DDI_HDEVICE hDevice,
    UINT StartSlot,
    UINT NumViews,
    const D3D10DDI_HSHADERRESOURCEVIEW* phShaderResourceViews )
{
    LOG_DLL_ENTRY;
}
////////////////////////////////////////////////////////////////////////////////
VOID WINAPI ShaderResourceViewReadAfterWriteHazard(
    D3D10DDI_HDEVICE hDevice,
    D3D10DDI_HSHADERRESOURCEVIEW hResource,
    D3D10DDI_HRESOURCE hShaderResourceView )
{
    LOG_DLL_ENTRY;
}
////////////////////////////////////////////////////////////////////////////////
VOID WINAPI CreateShaderResourceView(
    D3D10DDI_HDEVICE hDevice,
    const D3D11DDIARG_CREATESHADERRESOURCEVIEW* pCreateShaderResourceView,
    D3D10DDI_HSHADERRESOURCEVIEW hShaderResourceView,
    D3D10DDI_HRTSHADERRESOURCEVIEW hRTShaderResourceView )
{
    LOG_DLL_ENTRY;
}
////////////////////////////////////////////////////////////////////////////////
VOID WINAPI DestroyShaderResourceView(
    D3D10DDI_HDEVICE hDevice,
    D3D10DDI_HSHADERRESOURCEVIEW hShaderResourceView )
{
    LOG_DLL_ENTRY;
}
////////////////////////////////////////////////////////////////////////////////
VOID WINAPI HsSetShaderResources(
    D3D10DDI_HDEVICE hDevice,
    UINT StartSlot,
    UINT NumViews,
    const D3D10DDI_HSHADERRESOURCEVIEW* phShaderResourceViews )
{
    LOG_DLL_ENTRY;
}
////////////////////////////////////////////////////////////////////////////////
VOID WINAPI DsSetShaderResources(
    D3D10DDI_HDEVICE hDevice,
    UINT StartSlot,
    UINT NumViews,
    const D3D10DDI_HSHADERRESOURCEVIEW* phShaderResourceViews )
{
    LOG_DLL_ENTRY;
}
////////////////////////////////////////////////////////////////////////////////
VOID WINAPI CsSetShaderResources(
    D3D10DDI_HDEVICE hDevice,
    UINT StartSlot,
    UINT NumViews,
    const D3D10DDI_HSHADERRESOURCEVIEW* phShaderResourceViews )
{
    LOG_DLL_ENTRY;
}

} // namespace DDI
} // namespace UMD
} // namespace Crystal
