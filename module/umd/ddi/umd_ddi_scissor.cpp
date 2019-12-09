#include "pch.h"

namespace Crystal
{
namespace UMD
{
namespace DDI
{

////////////////////////////////////////////////////////////////////////////////
VOID WINAPI SetScissorRects(
    D3D10DDI_HDEVICE hDevice,
    UINT NumRects,
    UINT ClearRects,
    const D3D10_DDI_RECT* pRects )
{
    LOG_DLL_ENTRY;
}

} // namespace DDI
} // namespace UMD
} // namespace Crystal
