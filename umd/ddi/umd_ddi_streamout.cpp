#include "pch.h"

namespace Crystal
{
namespace UMD
{
namespace DDI
{

////////////////////////////////////////////////////////////////////////////////
VOID WINAPI SoSetTargets(
    D3D10DDI_HDEVICE hDevice,
    UINT NumBuffers,
    UINT ClearTargets,
    const D3D10DDI_HRESOURCE* phResource,
    const UINT* pOffsets )
{
    LOG_DLL_ENTRY;
}

} // namespace DDI
} // namespace UMD
} // namespace Crystal
