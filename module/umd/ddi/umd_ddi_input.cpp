#include "pch.h"

namespace Crystal
{
namespace UMD
{
namespace DDI
{

////////////////////////////////////////////////////////////////////////////////
VOID WINAPI IaSetInputLayout(
    D3D10DDI_HDEVICE hDevice,
    D3D10DDI_HELEMENTLAYOUT hInputLayout )
{
    LOG_DLL_ENTRY;
}
////////////////////////////////////////////////////////////////////////////////
VOID WINAPI IaSetVertexBuffers(
    D3D10DDI_HDEVICE hDevice,
    UINT StartSlot,
    UINT NumBuffers,
    const D3D10DDI_HRESOURCE* phBuffers,
    const UINT* pStrides,
    const UINT* pOffsets )
{
    LOG_DLL_ENTRY;
}
////////////////////////////////////////////////////////////////////////////////
VOID WINAPI IaSetIndexBuffer(
    D3D10DDI_HDEVICE hDevice,
    D3D10DDI_HRESOURCE hBuffer,
    DXGI_FORMAT Format,
    UINT Offset )
{
    LOG_DLL_ENTRY;
}
////////////////////////////////////////////////////////////////////////////////
VOID WINAPI IaSetTopology(
    D3D10DDI_HDEVICE hDevice,
    D3D10_DDI_PRIMITIVE_TOPOLOGY PrimitiveTopology )
{
    LOG_DLL_ENTRY;
}
////////////////////////////////////////////////////////////////////////////////
VOID WINAPI CreateElementLayout(
    D3D10DDI_HDEVICE hDevice,
    const D3D10DDIARG_CREATEELEMENTLAYOUT* pCreateElementLayout,
    D3D10DDI_HELEMENTLAYOUT hElementLayout,
    D3D10DDI_HRTELEMENTLAYOUT hRTElementLayout )
{
    LOG_DLL_ENTRY;
}
////////////////////////////////////////////////////////////////////////////////
VOID WINAPI DestroyElementLayout(
    D3D10DDI_HDEVICE hDevice,
    D3D10DDI_HELEMENTLAYOUT hElementLayout )
{
    LOG_DLL_ENTRY;
}

} // namespace DDI
} // namespace UMD
} // namespace Crystal
