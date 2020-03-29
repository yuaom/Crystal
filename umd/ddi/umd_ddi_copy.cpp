#include "pch.h"

namespace Crystal
{
namespace UMD
{
namespace DDI
{

////////////////////////////////////////////////////////////////////////////////
VOID WINAPI CopyStructureCount(
    D3D10DDI_HDEVICE hDevice,
    D3D10DDI_HRESOURCE hDstBuffer,
    UINT DstAlignedByteOffset,
    D3D11DDI_HUNORDEREDACCESSVIEW hSrcView )
{
    LOG_DLL_ENTRY;
}

////////////////////////////////////////////////////////////////////////////////
VOID WINAPI CopyTileMappings(
    D3D10DDI_HDEVICE hDevice,
    D3D10DDI_HRESOURCE hDestTiledResource,
    const D3DWDDM1_3DDI_TILED_RESOURCE_COORDINATE* pDestRegionStartCoord,
    D3D10DDI_HRESOURCE hSourceTiledResource,
    const D3DWDDM1_3DDI_TILED_RESOURCE_COORDINATE* pSourceRegionStartCoord,
    const D3DWDDM1_3DDI_TILE_REGION_SIZE* pTileRegionSize,
    UINT Flags )
{
    LOG_DLL_ENTRY;
}

////////////////////////////////////////////////////////////////////////////////
VOID WINAPI CopyTiles(
    D3D10DDI_HDEVICE hDevice,
    D3D10DDI_HRESOURCE hTiledResource,
    const D3DWDDM1_3DDI_TILED_RESOURCE_COORDINATE* pTileRegionStartCoord,
    const D3DWDDM1_3DDI_TILE_REGION_SIZE* pTileRegionSize,
    D3D10DDI_HRESOURCE hBuffer,
    UINT64 BufferStartOffsetInBytes,
    UINT Flags )
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

} // namespace DDI
} // namespace UMD
} // namespace Crystal
