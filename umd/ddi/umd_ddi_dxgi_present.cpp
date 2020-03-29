#include "pch.h"
#include "objects\umd_device.h"
#include "objects\umd_resource.h"

namespace Crystal
{
namespace UMD
{
namespace DDI
{

////////////////////////////////////////////////////////////////////////////////
HRESULT WINAPI CheckPresentDurationSupport(
    DXGI_DDI_ARG_CHECKPRESENTDURATIONSUPPORT* pCheckpresentdurationsupport )
{
    LOG_DLL_ENTRY;
    return E_FAIL;
}

////////////////////////////////////////////////////////////////////////////////
HRESULT WINAPI Present(
    DXGI_DDI_ARG_PRESENT* pPresent )
{
    LOG_DLL_ENTRY;
    return E_FAIL;
}

////////////////////////////////////////////////////////////////////////////////
HRESULT WINAPI Present1(
    DXGI1_6_1_DDI_ARG_PRESENT* pPresent )
{
    LOG_DLL_ENTRY;

    Device* pDevice = Device::FromHandle( pPresent->hDevice );

    // Submit work
    pDevice->GetEncoder()->Render();

    // Present
    Crystal::UMD::Resource* pResource = 
        Crystal::UMD::Resource::FromHandle( pPresent->phSurfacesToPresent[0].hSurface );

    DXGIDDICB_PRESENT present = { 0 };
    present.hContext        = pDevice->GetContextHandle();
    present.pDXGIContext    = pPresent->pDXGIContext;
    present.hSrcAllocation  = pResource->GetAllocationHandle();

    pDevice->Present( present );

    return S_OK;
}

////////////////////////////////////////////////////////////////////////////////
HRESULT WINAPI PresentMultiplaneOverlay(
    DXGI_DDI_ARG_PRESENTMULTIPLANEOVERLAY* pPresentmultiplaneoverlay )
{
    LOG_DLL_ENTRY;
    return E_FAIL;
}

////////////////////////////////////////////////////////////////////////////////
HRESULT WINAPI PresentMultiplaneOverlay1(
    DXGI1_6_1_DDI_ARG_PRESENTMULTIPLANEOVERLAY* pPresentmultiplaneoverlay )
{
    LOG_DLL_ENTRY;
    return E_FAIL;
}

////////////////////////////////////////////////////////////////////////////////
HRESULT WINAPI SetDisplayMode(
    DXGI_DDI_ARG_SETDISPLAYMODE* pSetdisplaymode )
{
    LOG_DLL_ENTRY;
    return E_FAIL;
}

} // namespace DDI
} // namespace UMD
} // namespace Crystal
