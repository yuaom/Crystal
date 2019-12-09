#include "pch.h"

namespace Crystal
{
namespace UMD
{
namespace DDI
{

////////////////////////////////////////////////////////////////////////////////
VOID WINAPI CreateVertexShader(
    D3D10DDI_HDEVICE hDevice,
    const UINT* pShaderCode,
    D3D10DDI_HSHADER hShader,
    D3D10DDI_HRTSHADER hRTShader,
    const D3D11_1DDIARG_STAGE_IO_SIGNATURES* pSignatures )
{
    LOG_DLL_ENTRY;
}

////////////////////////////////////////////////////////////////////////////////
VOID WINAPI CreateHullShader(
    D3D10DDI_HDEVICE hDevice,
    const UINT* pShaderCode,
    D3D10DDI_HSHADER hShader,
    D3D10DDI_HRTSHADER hRTShader,
    const D3D11_1DDIARG_TESSELLATION_IO_SIGNATURES* pSignatures )
{
    LOG_DLL_ENTRY;
}

////////////////////////////////////////////////////////////////////////////////
VOID WINAPI CreateDomainShader(
    D3D10DDI_HDEVICE hDevice,
    const UINT* pShaderCode,
    D3D10DDI_HSHADER hShader,
    D3D10DDI_HRTSHADER hRTShader,
    const D3D11_1DDIARG_TESSELLATION_IO_SIGNATURES* pSignatures )
{
    LOG_DLL_ENTRY;
}

////////////////////////////////////////////////////////////////////////////////
VOID WINAPI CreateGeometryShader(
    D3D10DDI_HDEVICE hDevice,
    const UINT* pShaderCode,
    D3D10DDI_HSHADER hShader,
    D3D10DDI_HRTSHADER hRTShader,
    const D3D11_1DDIARG_STAGE_IO_SIGNATURES* pSignatures )
{
    LOG_DLL_ENTRY;
}

////////////////////////////////////////////////////////////////////////////////
VOID WINAPI CreateGeometryShaderWithStreamOutput(
    D3D10DDI_HDEVICE hDevice,
    const D3D11DDIARG_CREATEGEOMETRYSHADERWITHSTREAMOUTPUT* pOutput,
    D3D10DDI_HSHADER hShader,
    D3D10DDI_HRTSHADER hRTShader,
    const D3D11_1DDIARG_STAGE_IO_SIGNATURES* pSignatures )
{
    LOG_DLL_ENTRY;
}

////////////////////////////////////////////////////////////////////////////////
VOID WINAPI CreatePixelShader(
    D3D10DDI_HDEVICE hDevice,
    const UINT* pShaderCode,
    D3D10DDI_HSHADER hShader,
    D3D10DDI_HRTSHADER hRTShader,
    const D3D11_1DDIARG_STAGE_IO_SIGNATURES* pSignatures )
{
    LOG_DLL_ENTRY;
}

////////////////////////////////////////////////////////////////////////////////
VOID WINAPI CreateComputeShader(
    D3D10DDI_HDEVICE hDevice,
    const UINT* pShaderCode,
    D3D10DDI_HSHADER hShader,
    D3D10DDI_HRTSHADER hRTShader )
{
    LOG_DLL_ENTRY;
}

////////////////////////////////////////////////////////////////////////////////
VOID WINAPI DestroyShader(
    D3D10DDI_HDEVICE hDevice,
    D3D10DDI_HSHADER hShader )
{
    LOG_DLL_ENTRY;
}

////////////////////////////////////////////////////////////////////////////////
VOID WINAPI VsSetShader(
    D3D10DDI_HDEVICE hDevice,
    D3D10DDI_HSHADER hShader )
{
    LOG_DLL_ENTRY;
}

////////////////////////////////////////////////////////////////////////////////
VOID WINAPI VsSetShaderWithIfaces(
    D3D10DDI_HDEVICE hDevice,
    D3D10DDI_HSHADER hShader,
    UINT NumClassInstances,
    const UINT* pPointerData,
    const D3D11DDIARG_POINTERDATA* pIfaces )
{
    LOG_DLL_ENTRY;
}

////////////////////////////////////////////////////////////////////////////////
VOID WINAPI HsSetShader(
    D3D10DDI_HDEVICE hDevice,
    D3D10DDI_HSHADER hShader )
{
    LOG_DLL_ENTRY;
}

////////////////////////////////////////////////////////////////////////////////
VOID WINAPI HsSetShaderWithIfaces(
    D3D10DDI_HDEVICE hDevice,
    D3D10DDI_HSHADER hShader,
    UINT NumClassInstances,
    const UINT* pPointerData,
    const D3D11DDIARG_POINTERDATA* pIfaces )
{
    LOG_DLL_ENTRY;
}

////////////////////////////////////////////////////////////////////////////////
VOID WINAPI DsSetShader(
    D3D10DDI_HDEVICE hDevice,
    D3D10DDI_HSHADER hShader )
{
    LOG_DLL_ENTRY;
}

////////////////////////////////////////////////////////////////////////////////
VOID WINAPI DsSetShaderWithIfaces(
    D3D10DDI_HDEVICE hDevice,
    D3D10DDI_HSHADER hShader,
    UINT NumClassInstances,
    const UINT* pPointerData,
    const D3D11DDIARG_POINTERDATA* pIfaces )
{
    LOG_DLL_ENTRY;
}

////////////////////////////////////////////////////////////////////////////////
VOID WINAPI GsSetShader(
    D3D10DDI_HDEVICE hDevice,
    D3D10DDI_HSHADER hShader )
{
    LOG_DLL_ENTRY;
}

////////////////////////////////////////////////////////////////////////////////
VOID WINAPI GsSetShaderWithIfaces(
    D3D10DDI_HDEVICE hDevice,
    D3D10DDI_HSHADER hShader,
    UINT NumClassInstances,
    const UINT* pPointerData,
    const D3D11DDIARG_POINTERDATA* pIfaces )
{
    LOG_DLL_ENTRY;
}

////////////////////////////////////////////////////////////////////////////////
VOID WINAPI PsSetShader(
    D3D10DDI_HDEVICE hDevice,
    D3D10DDI_HSHADER hShader )
{
    LOG_DLL_ENTRY;
}

////////////////////////////////////////////////////////////////////////////////
VOID WINAPI PsSetShaderWithIfaces(
    D3D10DDI_HDEVICE hDevice,
    D3D10DDI_HSHADER hShader,
    UINT NumClassInstances,
    const UINT* pPointerData,
    const D3D11DDIARG_POINTERDATA* pIfaces )
{
    LOG_DLL_ENTRY;
}

////////////////////////////////////////////////////////////////////////////////
VOID WINAPI CsSetShader(
    D3D10DDI_HDEVICE hDevice,
    D3D10DDI_HSHADER hShader )
{
    LOG_DLL_ENTRY;
}

////////////////////////////////////////////////////////////////////////////////
VOID WINAPI CsSetShaderWithIfaces(
    D3D10DDI_HDEVICE hDevice,
    D3D10DDI_HSHADER hShader,
    UINT NumClassInstances,
    const UINT* pPointerData,
    const D3D11DDIARG_POINTERDATA* pIfaces )
{
    LOG_DLL_ENTRY;
}

////////////////////////////////////////////////////////////////////////////////
VOID WINAPI AssignDebugBinary(
    D3D10DDI_HDEVICE hDevice,
    D3D10DDI_HSHADER hShader,
    UINT uBinarySize,
    const void* pBinary )
{
    LOG_DLL_ENTRY;
}

} // namespace DDI
} // namespace UMD
} // namespace Crystal
