#include "pch.h"

namespace Crystal
{
namespace UMD
{
namespace DDI
{

////////////////////////////////////////////////////////////////////////////////
VOID WINAPI ResourceCopyRegion(
    D3D10DDI_HDEVICE hDevice,
    D3D10DDI_HRESOURCE hDstResource,
    UINT DstSubresource,
    UINT DstX,
    UINT DstY,
    UINT DstZ,
    D3D10DDI_HRESOURCE hSrcResource,
    UINT SrcSubresource,
    const D3D10_DDI_BOX* pSrcBox,
    UINT CopyFlags )
{
    LOG_DLL_ENTRY;
}
////////////////////////////////////////////////////////////////////////////////
VOID WINAPI ResourceCopy(
    D3D10DDI_HDEVICE hDevice,
    D3D10DDI_HRESOURCE hDstResource,
    D3D10DDI_HRESOURCE hSrcResource )
{
    LOG_DLL_ENTRY;
}
////////////////////////////////////////////////////////////////////////////////
VOID WINAPI CopyStructureCount(
    D3D10DDI_HDEVICE hDevice,
    D3D10DDI_HRESOURCE hDstBuffer,
    UINT DstAlignedByteOffset,
    D3D11DDI_HUNORDEREDACCESSVIEW hSrcView )
{
    LOG_DLL_ENTRY;
}

} // namespace DDI
} // namespace UMD
} // namespace Crystal
