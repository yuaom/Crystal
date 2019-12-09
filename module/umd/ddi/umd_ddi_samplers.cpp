#include "pch.h"

namespace Crystal
{
namespace UMD
{
namespace DDI
{

////////////////////////////////////////////////////////////////////////////////
VOID WINAPI PsSetSamplers(
    D3D10DDI_HDEVICE hDevice,
    UINT Offset,
    UINT NumSamplers,
    const D3D10DDI_HSAMPLER* phSamplers )
{
    LOG_DLL_ENTRY;
}
////////////////////////////////////////////////////////////////////////////////
VOID WINAPI VsSetSamplers(
    D3D10DDI_HDEVICE hDevice,
    UINT Offset,
    UINT NumSamplers,
    const D3D10DDI_HSAMPLER* phSamplers )
{
    LOG_DLL_ENTRY;
}
////////////////////////////////////////////////////////////////////////////////
VOID WINAPI GsSetSamplers(
    D3D10DDI_HDEVICE hDevice,
    UINT Offset,
    UINT NumSamplers,
    const D3D10DDI_HSAMPLER* phSamplers )
{
    LOG_DLL_ENTRY;
}
////////////////////////////////////////////////////////////////////////////////
VOID WINAPI CreateSampler(
    D3D10DDI_HDEVICE hDevice,
    const D3D10_DDI_SAMPLER_DESC* pSamplerDesc,
    D3D10DDI_HSAMPLER hSampler,
    D3D10DDI_HRTSAMPLER hRTSampler )
{
    LOG_DLL_ENTRY;
}
////////////////////////////////////////////////////////////////////////////////
VOID WINAPI DestroySampler(
    D3D10DDI_HDEVICE hDevice,
    D3D10DDI_HSAMPLER hSampler )
{
    LOG_DLL_ENTRY;
}
////////////////////////////////////////////////////////////////////////////////
VOID WINAPI HsSetSamplers(
    D3D10DDI_HDEVICE hDevice,
    UINT Offset,
    UINT NumSamplers,
    const D3D10DDI_HSAMPLER* phSamplers )
{
    LOG_DLL_ENTRY;
}
////////////////////////////////////////////////////////////////////////////////
VOID WINAPI DsSetSamplers(
    D3D10DDI_HDEVICE hDevice,
    UINT Offset,
    UINT NumSamplers,
    const D3D10DDI_HSAMPLER* phSamplers )
{
    LOG_DLL_ENTRY;
}
////////////////////////////////////////////////////////////////////////////////
VOID WINAPI CsSetSamplers(
    D3D10DDI_HDEVICE hDevice,
    UINT Offset,
    UINT NumSamplers,
    const D3D10DDI_HSAMPLER* phSamplers )
{
    LOG_DLL_ENTRY;
}

} // namespace DDI
} // namespace UMD
} // namespace Crystal
