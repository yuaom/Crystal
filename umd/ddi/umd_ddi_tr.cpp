#include "pch.h"

namespace Crystal
{
namespace UMD
{
namespace DDI
{

////////////////////////////////////////////////////////////////////////////////
VOID WINAPI ResizeTilePool(
    D3D10DDI_HDEVICE hDevice,
    D3D10DDI_HRESOURCE hTilePool,
    UINT64 NewSizeInBytes )
{
    LOG_DLL_ENTRY;
}

////////////////////////////////////////////////////////////////////////////////
VOID WINAPI TiledResourceBarrier(
    D3D10DDI_HDEVICE hDevice,
    D3D11DDI_HANDLETYPE TiledResourceAccessBeforeBarrierHandleType,
    void* hTiledResourceAccessBeforeBarrier,
    D3D11DDI_HANDLETYPE TiledResourceAccessAfterBarrierHandleType,
    void* hTiledResourceAccessAfterBarrier )
{
    LOG_DLL_ENTRY;
}

} // namespace DDI
} // namespace UMD
} // namespace Crystal
