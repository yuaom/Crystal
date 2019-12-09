#include "pch.h"

namespace Crystal
{
namespace UMD
{
namespace DDI
{

////////////////////////////////////////////////////////////////////////////////
VOID WINAPI DefaultConstantBufferUpdateSubresourceUP(
    D3D10DDI_HDEVICE hDevice,
    D3D10DDI_HRESOURCE hDstResource,
    UINT DstSubresource,
    const D3D10_DDI_BOX* pDstBox,
    const void* pSysMemUP,
    UINT RowPitch,
    UINT DepthPitch,
    UINT CopyFlags )
{
    LOG_DLL_ENTRY;
}
////////////////////////////////////////////////////////////////////////////////
VOID WINAPI ResourceUpdateSubresourceUP(
    D3D10DDI_HDEVICE hDevice,
    D3D10DDI_HRESOURCE hDstResource,
    UINT DstSubresource,
    const D3D10_DDI_BOX* pDstBox,
    const void* pSysMemUP,
    UINT RowPitch,
    UINT DepthPitch,
    UINT CopyFlags )
{
    LOG_DLL_ENTRY;
}

} // namespace DDI
} // namespace UMD
} // namespace Crystal
