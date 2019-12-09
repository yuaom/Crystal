#include "pch.h"

namespace Crystal
{
namespace UMD
{
namespace DDI
{

////////////////////////////////////////////////////////////////////////////////
VOID WINAPI DynamicIABufferMapNoOverwrite(
    D3D10DDI_HDEVICE hDevice,
    D3D10DDI_HRESOURCE hResource,
    UINT Subresource,
    D3D10_DDI_MAP DDIMap,
    UINT Flags,
    D3D10DDI_MAPPED_SUBRESOURCE* pMappedSubResource )
{
    LOG_DLL_ENTRY;
}
////////////////////////////////////////////////////////////////////////////////
VOID WINAPI DynamicConstantBufferMapDiscard(
    D3D10DDI_HDEVICE hDevice,
    D3D10DDI_HRESOURCE hResource,
    UINT Subresource,
    D3D10_DDI_MAP DDIMap,
    UINT Flags,
    D3D10DDI_MAPPED_SUBRESOURCE* pMappedSubResource )
{
    LOG_DLL_ENTRY;
}
////////////////////////////////////////////////////////////////////////////////
VOID WINAPI DynamicIABufferMapDiscard(
    D3D10DDI_HDEVICE hDevice,
    D3D10DDI_HRESOURCE hResource,
    UINT Subresource,
    D3D10_DDI_MAP DDIMap,
    UINT Flags,
    D3D10DDI_MAPPED_SUBRESOURCE* pMappedSubResource )
{
    LOG_DLL_ENTRY;
}
////////////////////////////////////////////////////////////////////////////////
VOID WINAPI DynamicResourceMapDiscard(
    D3D10DDI_HDEVICE hDevice,
    D3D10DDI_HRESOURCE hResource,
    UINT Subresource,
    D3D10_DDI_MAP DDIMap,
    UINT Flags,
    D3D10DDI_MAPPED_SUBRESOURCE* pMappedSubResource )
{
    LOG_DLL_ENTRY;
}
////////////////////////////////////////////////////////////////////////////////
VOID WINAPI DynamicConstantBufferMapNoOverwrite(
    D3D10DDI_HDEVICE hDevice,
    D3D10DDI_HRESOURCE hResource,
    UINT Subresource,
    D3D10_DDI_MAP DDIMap,
    UINT Flags,
    D3D10DDI_MAPPED_SUBRESOURCE* pMappedSubResource )
{
    LOG_DLL_ENTRY;
}

} // namespace DDI
} // namespace UMD
} // namespace Crystal
