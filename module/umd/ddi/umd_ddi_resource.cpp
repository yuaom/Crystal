#include "pch.h"
#include "umd_resource.h"

namespace Crystal
{
namespace UMD
{
namespace DDI
{

////////////////////////////////////////////////////////////////////////////////
VOID WINAPI CreateResource(
    D3D10DDI_HDEVICE hDevice,
    const D3D11DDIARG_CREATERESOURCE* pCreateResource,
    D3D10DDI_HRESOURCE hResource,
    D3D10DDI_HRTRESOURCE hRTResource )
{
    LOG_DLL_ENTRY;

    Resource::Create( hDevice, pCreateResource, hResource, hRTResource );
}

////////////////////////////////////////////////////////////////////////////////
VOID WINAPI DestroyResource(
    D3D10DDI_HDEVICE hDevice,
    D3D10DDI_HRESOURCE hResource )
{
    LOG_DLL_ENTRY;
}

////////////////////////////////////////////////////////////////////////////////
VOID WINAPI OpenResource(
    D3D10DDI_HDEVICE hDevice,
    const D3D10DDIARG_OPENRESOURCE* pOpenResource,
    D3D10DDI_HRESOURCE hResource,
    D3D10DDI_HRTRESOURCE hRTResource )
{
    LOG_DLL_ENTRY;
}

////////////////////////////////////////////////////////////////////////////////
VOID WINAPI Discard(
    D3D10DDI_HDEVICE hDevice,
    D3D11DDI_HANDLETYPE HandleType,
    void* hResourceOrView,
    const D3D10_DDI_RECT* pRects,
    UINT NumRects )
{
    LOG_DLL_ENTRY;
}

////////////////////////////////////////////////////////////////////////////////
VOID WINAPI SetResourceMinLOD(
    D3D10DDI_HDEVICE hDevice,
    D3D10DDI_HRESOURCE hResource,
    FLOAT MinLOD )
{
    LOG_DLL_ENTRY;
}

} // namespace DDI
} // namespace UMD
} // namespace Crystal
