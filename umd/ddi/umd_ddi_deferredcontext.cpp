#include "pch.h"

namespace Crystal
{
namespace UMD
{
namespace DDI
{

////////////////////////////////////////////////////////////////////////////////
VOID WINAPI CreateDeferredContext(
    D3D10DDI_HDEVICE hDevice,
    const D3D11DDIARG_CREATEDEFERREDCONTEXT* pCreateDeferredContext )
{
    LOG_DLL_ENTRY;
}

////////////////////////////////////////////////////////////////////////////////
HRESULT WINAPI RecycleCreateDeferredContext(
    D3D10DDI_HDEVICE hDevice,
    const D3D11DDIARG_CREATEDEFERREDCONTEXT* pCreateDeferredContext )
{
    LOG_DLL_ENTRY;
    return E_FAIL;
}

////////////////////////////////////////////////////////////////////////////////
SIZE_T WINAPI CalcDeferredContextHandleSize(
    D3D10DDI_HDEVICE hDevice,
    D3D11DDI_HANDLETYPE HandleType,
    void* pICObject )
{
    LOG_DLL_ENTRY;
    return 0;
}

////////////////////////////////////////////////////////////////////////////////
VOID WINAPI CheckDeferredContextHandleSizes(
    D3D10DDI_HDEVICE hDevice,
    UINT* pHSizes,
    D3D11DDI_HANDLESIZE* pHandleSize )
{
    LOG_DLL_ENTRY;
}

} // namespace DDI
} // namespace UMD
} // namespace Crystal
