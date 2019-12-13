#include "pch.h"
#include "umd_device.h"

namespace Crystal
{
namespace UMD
{
namespace DDI
{

////////////////////////////////////////////////////////////////////////////////
VOID WINAPI DestroyDevice(
    D3D10DDI_HDEVICE hDevice )
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

////////////////////////////////////////////////////////////////////////////////
VOID WINAPI CheckFormatSupport(
    D3D10DDI_HDEVICE hDevice,
    DXGI_FORMAT Format,
    UINT* pFormatCaps )
{
    LOG_DLL_ENTRY;

    Device* pDevice = Device::FromHandle( hDevice );

    pDevice->GetFormatSupport( Format, pFormatCaps );
}

////////////////////////////////////////////////////////////////////////////////
VOID WINAPI CheckMultisampleQualityLevels(
    D3D10DDI_HDEVICE hDevice,
    DXGI_FORMAT Format,
    UINT SampleCount,
    UINT Flags,
    UINT* pNumQualityLevels )
{
    LOG_DLL_ENTRY;

    Device* pDevice = Device::FromHandle( hDevice );

    pDevice->GetMultisampleSupport( Format, SampleCount, pNumQualityLevels );
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
VOID WINAPI GetMipPacking(
    D3D10DDI_HDEVICE hDevice,
    D3D10DDI_HRESOURCE hTiledResource,
    UINT* pNumPackedMips,
    UINT* pNumTilesForPackedMips )
{
    LOG_DLL_ENTRY;
}

////////////////////////////////////////////////////////////////////////////////
VOID WINAPI RelocateDeviceFuncs(
    D3D10DDI_HDEVICE hDevice,
    struct D3DWDDM1_3DDI_DEVICEFUNCS* DeviceFuncs )
{
    LOG_DLL_ENTRY;
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
VOID WINAPI ResourceReadAfterWriteHazard(
    D3D10DDI_HDEVICE hDevice,
    D3D10DDI_HRESOURCE hResource )
{
    LOG_DLL_ENTRY;
}

////////////////////////////////////////////////////////////////////////////////
VOID WINAPI SetMarker(
    D3D10DDI_HDEVICE hDevice )
{
    LOG_DLL_ENTRY;
}

////////////////////////////////////////////////////////////////////////////////
VOID WINAPI SetMarkerMode(
    D3D10DDI_HDEVICE hDevice,
    D3DWDDM1_3DDI_MARKER_TYPE Type,
    UINT Flags )
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

} // namespace DDI
} // namespace UMD
} // namespace Crystal
