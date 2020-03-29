#include "pch.h"

namespace Crystal
{
namespace UMD
{
namespace DDI
{

////////////////////////////////////////////////////////////////////////////////
VOID WINAPI DynamicConstantBufferUnmap(
    D3D10DDI_HDEVICE hDevice,
    D3D10DDI_HRESOURCE hResource,
    UINT Subresource )
{
    LOG_DLL_ENTRY;
}

////////////////////////////////////////////////////////////////////////////////
VOID WINAPI DynamicIABufferUnmap(
    D3D10DDI_HDEVICE hDevice,
    D3D10DDI_HRESOURCE hResource,
    UINT Subresource )
{
    LOG_DLL_ENTRY;
}

////////////////////////////////////////////////////////////////////////////////
VOID WINAPI DynamicResourceUnmap(
    D3D10DDI_HDEVICE hDevice,
    D3D10DDI_HRESOURCE hResource,
    UINT Subresource )
{
    LOG_DLL_ENTRY;
}

////////////////////////////////////////////////////////////////////////////////
VOID WINAPI ResourceMap(
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
VOID WINAPI ResourceUnmap(
    D3D10DDI_HDEVICE hDevice,
    D3D10DDI_HRESOURCE hResource,
    UINT Subresource )
{
    LOG_DLL_ENTRY;
}

////////////////////////////////////////////////////////////////////////////////
VOID WINAPI StagingResourceMap(
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
VOID WINAPI StagingResourceUnmap(
    D3D10DDI_HDEVICE hDevice,
    D3D10DDI_HRESOURCE hResource,
    UINT Subresource )
{
    LOG_DLL_ENTRY;
}

} // namespace DDI
} // namespace UMD
} // namespace Crystal
