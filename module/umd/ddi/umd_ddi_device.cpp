#include "pch.h"

namespace Crystal
{
namespace UMD
{
namespace DDI
{

////////////////////////////////////////////////////////////////////////////////
VOID WINAPI ResourceReadAfterWriteHazard(
    D3D10DDI_HDEVICE hDevice,
    D3D10DDI_HRESOURCE hResource )
{
    LOG_DLL_ENTRY;
}
////////////////////////////////////////////////////////////////////////////////
BOOL WINAPI Flush(
    D3D10DDI_HDEVICE hDevice,
    UINT FlushFlags )
{
    LOG_DLL_ENTRY;
    return FALSE;
}
////////////////////////////////////////////////////////////////////////////////
BOOL WINAPI ResourceIsStagingBusy(
    D3D10DDI_HDEVICE hDevice,
    D3D10DDI_HRESOURCE hResource )
{
    LOG_DLL_ENTRY;
    return FALSE;
}
////////////////////////////////////////////////////////////////////////////////
VOID WINAPI RelocateDeviceFuncs(
    D3D10DDI_HDEVICE hDevice,
    struct D3D11_1DDI_DEVICEFUNCS* pDeviceFunctions )
{
    LOG_DLL_ENTRY;
}
////////////////////////////////////////////////////////////////////////////////
VOID WINAPI CheckFormatSupport(
    D3D10DDI_HDEVICE hDevice,
    DXGI_FORMAT Format,
    UINT* pFormatCaps )
{
    LOG_DLL_ENTRY;
}
////////////////////////////////////////////////////////////////////////////////
VOID WINAPI CheckMultisampleQualityLevels(
    D3D10DDI_HDEVICE hDevice,
    DXGI_FORMAT Format,
    UINT SampleCount,
    UINT* pNumQualityLevels )
{
    LOG_DLL_ENTRY;
}
////////////////////////////////////////////////////////////////////////////////
VOID WINAPI DestroyDevice(
    D3D10DDI_HDEVICE hDevice )
{
    LOG_DLL_ENTRY;
}
////////////////////////////////////////////////////////////////////////////////
VOID WINAPI SetTextFilterSize(
    D3D10DDI_HDEVICE hDevice,
    UINT Width,
    UINT Height )
{
    LOG_DLL_ENTRY;
}
////////////////////////////////////////////////////////////////////////////////
VOID WINAPI CheckDirectFlipSupport(
    D3D10DDI_HDEVICE hDevice,
    D3D10DDI_HRESOURCE hResource1,
    D3D10DDI_HRESOURCE hResource2,
    UINT CheckDirectFlipFlags,
    BOOL* pSupported )
{
    LOG_DLL_ENTRY;
}

} // namespace DDI
} // namespace UMD
} // namespace Crystal
