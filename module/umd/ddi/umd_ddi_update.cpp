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

////////////////////////////////////////////////////////////////////////////////
VOID WINAPI UpdateTileMappings(
    D3D10DDI_HDEVICE hDevice,
    D3D10DDI_HRESOURCE hTiledResource,
    UINT NumTiledResourceRegions,
    const D3DWDDM1_3DDI_TILED_RESOURCE_COORDINATE* pTiledResourceRegionStartCoords,
    const D3DWDDM1_3DDI_TILE_REGION_SIZE* pTiledResourceRegionSizes,
    D3D10DDI_HRESOURCE hTilePool,
    UINT NumRanges,
    const UINT* pRangeFlags,
    const UINT* pTilePoolStartOffsets,
    const UINT* pRangeTileCounts,
    UINT Flags )
{
    LOG_DLL_ENTRY;
}

////////////////////////////////////////////////////////////////////////////////
VOID WINAPI UpdateTiles(
    D3D10DDI_HDEVICE hDevice,
    D3D10DDI_HRESOURCE hDestTiledResource,
    const D3DWDDM1_3DDI_TILED_RESOURCE_COORDINATE* pDestTileRegionStartCoord,
    const D3DWDDM1_3DDI_TILE_REGION_SIZE* pDestTileRegionSize,
    const void* pSourceTileData,
    UINT Flags )
{
    LOG_DLL_ENTRY;
}

} // namespace DDI
} // namespace UMD
} // namespace Crystal
