#include "pch.h"

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
     // LOG_DLL_ENTRY;
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
