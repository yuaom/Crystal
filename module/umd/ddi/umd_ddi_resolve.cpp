#include "pch.h"

namespace Crystal
{
namespace UMD
{
namespace DDI
{

////////////////////////////////////////////////////////////////////////////////
VOID WINAPI ResourceResolveSubresource(
    D3D10DDI_HDEVICE hDevice,
    D3D10DDI_HRESOURCE hDstResource,
    UINT DstSubresource,
    D3D10DDI_HRESOURCE hSrcResource,
    UINT SrcSubresource,
    DXGI_FORMAT ResolveFormat )
{
    LOG_DLL_ENTRY;
}

} // namespace DDI
} // namespace UMD
} // namespace Crystal
