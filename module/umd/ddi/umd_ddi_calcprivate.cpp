#include "pch.h"

namespace Crystal
{
namespace UMD
{
namespace DDI
{

////////////////////////////////////////////////////////////////////////////////
SIZE_T WINAPI CalcPrivateOpenedResourceSize(
    D3D10DDI_HDEVICE hDevice,
    const D3D10DDIARG_OPENRESOURCE* pOpenResource )
{
    LOG_DLL_ENTRY;
    return 0;
}

////////////////////////////////////////////////////////////////////////////////
SIZE_T WINAPI CalcPrivateGeometryShaderWithStreamOutput(
    D3D10DDI_HDEVICE hDevice,
    const D3D11DDIARG_CREATEGEOMETRYSHADERWITHSTREAMOUTPUT* pOutput,
    const D3D11_1DDIARG_STAGE_IO_SIGNATURES* pSignatures )
{
    LOG_DLL_ENTRY;
    return 0;
}

////////////////////////////////////////////////////////////////////////////////
SIZE_T WINAPI CalcPrivateBlendStateSize(
    D3D10DDI_HDEVICE hDevice,
    const D3D11_1_DDI_BLEND_DESC* pBlendDesc )
{
    LOG_DLL_ENTRY;
    return 0;
}

////////////////////////////////////////////////////////////////////////////////
SIZE_T WINAPI CalcPrivateCommandListSize(
    D3D10DDI_HDEVICE hDevice,
    const D3D11DDIARG_CREATECOMMANDLIST* pCreateCommandList )
{
    LOG_DLL_ENTRY;
    return 0;
}

////////////////////////////////////////////////////////////////////////////////
SIZE_T WINAPI CalcPrivateDeferredContextSize(
    D3D10DDI_HDEVICE hDevice,
    const D3D11DDIARG_CALCPRIVATEDEFERREDCONTEXTSIZE* pCalcPrivateDeferredContextSize )
{
    LOG_DLL_ENTRY;
    return 0;
}

////////////////////////////////////////////////////////////////////////////////
SIZE_T WINAPI CalcPrivateDepthStencilStateSize(
    D3D10DDI_HDEVICE hDevice,
    const D3D10_DDI_DEPTH_STENCIL_DESC* pDepthStencilDesc )
{
    LOG_DLL_ENTRY;
    return 0;
}

////////////////////////////////////////////////////////////////////////////////
SIZE_T WINAPI CalcPrivateDepthStencilViewSize(
    D3D10DDI_HDEVICE hDevice,
    const D3D11DDIARG_CREATEDEPTHSTENCILVIEW* pCreateDepthStencilView )
{
    LOG_DLL_ENTRY;
    return 0;
}

////////////////////////////////////////////////////////////////////////////////
SIZE_T WINAPI CalcPrivateElementLayoutSize(
    D3D10DDI_HDEVICE hDevice,
    const D3D10DDIARG_CREATEELEMENTLAYOUT* pCreateElementLayout )
{
    LOG_DLL_ENTRY;
    return 0;
}

////////////////////////////////////////////////////////////////////////////////
SIZE_T WINAPI CalcPrivateQuerySize(
    D3D10DDI_HDEVICE hDevice,
    const D3D10DDIARG_CREATEQUERY* pCreateQuery )
{
    LOG_DLL_ENTRY;
    return 0;
}

////////////////////////////////////////////////////////////////////////////////
SIZE_T WINAPI CalcPrivateRasterizerStateSize(
    D3D10DDI_HDEVICE hDevice,
    const D3D11_1_DDI_RASTERIZER_DESC* pRasterizerDesc )
{
    LOG_DLL_ENTRY;
    return 0;
}

////////////////////////////////////////////////////////////////////////////////
SIZE_T WINAPI CalcPrivateRenderTargetViewSize(
    D3D10DDI_HDEVICE hDevice,
    const D3D10DDIARG_CREATERENDERTARGETVIEW* pCreateRenderTargetView )
{
    LOG_DLL_ENTRY;
    return 0;
}

////////////////////////////////////////////////////////////////////////////////
SIZE_T WINAPI CalcPrivateResourceSize(
    D3D10DDI_HDEVICE hDevice,
    const D3D11DDIARG_CREATERESOURCE* pCreateResource )
{
    LOG_DLL_ENTRY;
    return 0;
}

////////////////////////////////////////////////////////////////////////////////
SIZE_T WINAPI CalcPrivateSamplerSize(
    D3D10DDI_HDEVICE hDevice,
    const D3D10_DDI_SAMPLER_DESC* pSamplerDesc )
{
    LOG_DLL_ENTRY;
    return 0;
}

////////////////////////////////////////////////////////////////////////////////
SIZE_T WINAPI CalcPrivateShaderResourceViewSize(
    D3D10DDI_HDEVICE hDevice,
    const D3D11DDIARG_CREATESHADERRESOURCEVIEW* pCreateShaderResourceView )
{
    LOG_DLL_ENTRY;
    return 0;
}

////////////////////////////////////////////////////////////////////////////////
SIZE_T WINAPI CalcPrivateShaderSize(
    D3D10DDI_HDEVICE hDevice,
    const UINT* pShaderCode,
    const D3D11_1DDIARG_STAGE_IO_SIGNATURES* pSignatures )
{
    LOG_DLL_ENTRY;
    return 0;
}

////////////////////////////////////////////////////////////////////////////////
SIZE_T WINAPI CalcPrivateTessellationShaderSize(
    D3D10DDI_HDEVICE hDevice,
    const UINT* pShaderCode,
    const D3D11_1DDIARG_TESSELLATION_IO_SIGNATURES* pIOSignatures )
{
    LOG_DLL_ENTRY;
    return 0;
}

////////////////////////////////////////////////////////////////////////////////
SIZE_T WINAPI CalcPrivateUnorderedAccessViewSize(
    D3D10DDI_HDEVICE hDevice,
    const D3D11DDIARG_CREATEUNORDEREDACCESSVIEW* pCreateUnorderedAccessView )
{
    LOG_DLL_ENTRY;
    return 0;
}

} // namespace DDI
} // namespace UMD
} // namespace Crystal
