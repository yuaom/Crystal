#include "pch.h"

namespace Crystal
{
namespace UMD
{
namespace DDI
{

////////////////////////////////////////////////////////////////////////////////
VOID WINAPI CreateUnorderedAccessView(
    D3D10DDI_HDEVICE hDevice,
    const D3D11DDIARG_CREATEUNORDEREDACCESSVIEW* pCreateUnorderedAccessView,
    D3D11DDI_HUNORDEREDACCESSVIEW hUnorderedAccessView,
    D3D11DDI_HRTUNORDEREDACCESSVIEW hRTUnorderedAccessView )
{
    LOG_DLL_ENTRY;
}
////////////////////////////////////////////////////////////////////////////////
VOID WINAPI DestroyUnorderedAccessView(
    D3D10DDI_HDEVICE hDevice,
    D3D11DDI_HUNORDEREDACCESSVIEW hUnorderedAccessView )
{
    LOG_DLL_ENTRY;
}
////////////////////////////////////////////////////////////////////////////////
VOID WINAPI ClearUnorderedAccessViewUint(
    D3D10DDI_HDEVICE hDevice,
    D3D11DDI_HUNORDEREDACCESSVIEW hUnorderedAccessView,
    const UINT UINT[4] )
{
    LOG_DLL_ENTRY;
}
////////////////////////////////////////////////////////////////////////////////
VOID WINAPI ClearUnorderedAccessViewFloat(
    D3D10DDI_HDEVICE hDevice,
    D3D11DDI_HUNORDEREDACCESSVIEW hUnorderedAccessView,
    const FLOAT FLOAT[4] )
{
    LOG_DLL_ENTRY;
}
////////////////////////////////////////////////////////////////////////////////
VOID WINAPI CsSetUnorderedAccessViews(
    D3D10DDI_HDEVICE hDevice,
    UINT StartSlot,
    UINT NumViews,
    const D3D11DDI_HUNORDEREDACCESSVIEW* pUAVInitialCounts,
    const UINT* phUnorderedAccessView )
{
    LOG_DLL_ENTRY;
}

} // namespace DDI
} // namespace UMD
} // namespace Crystal
