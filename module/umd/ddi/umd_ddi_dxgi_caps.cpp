#include "pch.h"

namespace Crystal
{
namespace UMD
{
namespace DDI
{

////////////////////////////////////////////////////////////////////////////////
HRESULT WINAPI CheckMultiplaneOverlayColorSpaceSupport(
    DXGI_DDI_ARG_CHECKMULTIPLANEOVERLAYCOLORSPACESUPPORT* pCheckmultiplaneoverlaycolorspacesupport )
{
    LOG_DLL_ENTRY;
    return E_FAIL;
}

////////////////////////////////////////////////////////////////////////////////
HRESULT WINAPI GetGammaCaps(
    DXGI_DDI_ARG_GET_GAMMA_CONTROL_CAPS* pGetGammaControlCaps )
{
    LOG_DLL_ENTRY;
    return E_FAIL;
}

////////////////////////////////////////////////////////////////////////////////
HRESULT WINAPI GetMultiplaneOverlayCaps(
    DXGI_DDI_ARG_GETMULTIPLANEOVERLAYCAPS* pGetmultiplaneoverlaycaps )
{
    LOG_DLL_ENTRY;
    return E_FAIL;
}

////////////////////////////////////////////////////////////////////////////////
HRESULT WINAPI GetMultiplaneOverlayGroupCaps(
    DXGI_DDI_ARG_GETMULTIPLANEOVERLAYGROUPCAPS* pGetmultiplaneoverlaygroupcaps )
{
    LOG_DLL_ENTRY;
    return E_FAIL;
}

} // namespace DDI
} // namespace UMD
} // namespace Crystal
