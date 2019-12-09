#include "pch.h"

namespace Crystal
{
namespace UMD
{
namespace DDI
{

////////////////////////////////////////////////////////////////////////////////
VOID WINAPI CreateCommandList(
    D3D10DDI_HDEVICE hDevice,
    const D3D11DDIARG_CREATECOMMANDLIST* pCreateCommandList,
    D3D11DDI_HCOMMANDLIST hCommandList,
    D3D11DDI_HRTCOMMANDLIST hRTCommandList )
{
    LOG_DLL_ENTRY;
}

////////////////////////////////////////////////////////////////////////////////
HRESULT WINAPI RecycleCreateCommandList(
    D3D10DDI_HDEVICE hDevice,
    const D3D11DDIARG_CREATECOMMANDLIST* pCreateCommandList,
    D3D11DDI_HCOMMANDLIST hCommandList,
    D3D11DDI_HRTCOMMANDLIST hRTCommandList )
{
    LOG_DLL_ENTRY;
    return E_FAIL;
}

////////////////////////////////////////////////////////////////////////////////
VOID WINAPI DestroyCommandList(
    D3D10DDI_HDEVICE hDevice,
    D3D11DDI_HCOMMANDLIST hCommandList )
{
    LOG_DLL_ENTRY;
}

////////////////////////////////////////////////////////////////////////////////
VOID WINAPI RecycleDestroyCommandList(
    D3D10DDI_HDEVICE hDevice,
    D3D11DDI_HCOMMANDLIST hCommandList )
{
    LOG_DLL_ENTRY;
}

////////////////////////////////////////////////////////////////////////////////
VOID WINAPI AbandonCommandList(
    D3D10DDI_HDEVICE hDevice )
{
    LOG_DLL_ENTRY;
}

////////////////////////////////////////////////////////////////////////////////
VOID WINAPI CommandListExecute(
    D3D10DDI_HDEVICE hDevice,
    D3D11DDI_HCOMMANDLIST hCommandList )
{
    LOG_DLL_ENTRY;
}

////////////////////////////////////////////////////////////////////////////////
VOID WINAPI RecycleCommandList(
    D3D10DDI_HDEVICE hDevice,
    D3D11DDI_HCOMMANDLIST hCommandList )
{
    LOG_DLL_ENTRY;
}

} // namespace DDI
} // namespace UMD
} // namespace Crystal
