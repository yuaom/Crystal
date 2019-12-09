#include "pch.h"

namespace Crystal
{
namespace UMD
{
namespace DDI
{

////////////////////////////////////////////////////////////////////////////////
VOID WINAPI SetViewports(
    D3D10DDI_HDEVICE hDevice,
    UINT NumViewports,
    UINT ClearViewports,
    const D3D10_DDI_VIEWPORT* pViewports )
{
    LOG_DLL_ENTRY;
}

} // namespace DDI
} // namespace UMD
} // namespace Crystal
