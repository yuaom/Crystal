#include "pch.h"

namespace Crystal
{
namespace UMD
{
namespace DDI
{

////////////////////////////////////////////////////////////////////////////////
VOID WINAPI CreateBlendState(
    D3D10DDI_HDEVICE hDevice,
    const D3D11_1_DDI_BLEND_DESC* pBlendDesc,
    D3D10DDI_HBLENDSTATE hBlendState,
    D3D10DDI_HRTBLENDSTATE hRTBlendState )
{
    LOG_DLL_ENTRY;
}

////////////////////////////////////////////////////////////////////////////////
VOID WINAPI DestroyBlendState(
    D3D10DDI_HDEVICE hDevice,
    D3D10DDI_HBLENDSTATE hBlendState )
{
    LOG_DLL_ENTRY;
}

////////////////////////////////////////////////////////////////////////////////
VOID WINAPI SetBlendState(
    D3D10DDI_HDEVICE hDevice,
    D3D10DDI_HBLENDSTATE hState,
    const FLOAT pBlendFactor[4],
    UINT SampleMask )
{
    LOG_DLL_ENTRY;
}

} // namespace DDI
} // namespace UMD
} // namespace Crystal
