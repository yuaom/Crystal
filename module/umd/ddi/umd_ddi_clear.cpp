#include "pch.h"

namespace Crystal
{
namespace UMD
{
namespace DDI
{

////////////////////////////////////////////////////////////////////////////////
VOID WINAPI ClearView(
    D3D10DDI_HDEVICE hDevice,
    D3D11DDI_HANDLETYPE viewType,
    void* hView,
    const FLOAT Color[4],
    const D3D10_DDI_RECT* pRect,
    UINT NumRects )
{
    LOG_DLL_ENTRY;
}

} // namespace DDI
} // namespace UMD
} // namespace Crystal
