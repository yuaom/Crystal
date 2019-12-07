#include "pch.h"

namespace Crystal
{
namespace Autogen
{

////////////////////////////////////////////////////////////////////////////////
VOID WINAPI DefaultConstantBufferUpdateSubresourceUP(
    D3D10DDI_HDEVICE hDevice,
    D3D10DDI_HRESOURCE hResource,
    UINT arg1,
    const D3D10_DDI_BOX* pBox,
    const void* arg2,
    UINT arg3,
    UINT arg4,
    UINT CopyFlags )
{
    LOG_DLL_ENTRY;
}

////////////////////////////////////////////////////////////////////////////////
VOID WINAPI VsSetConstantBuffers(
    D3D10DDI_HDEVICE hDevice,
    UINT StartSlot,
    UINT NumBuffers,
    const D3D10DDI_HRESOURCE* hResource,
    const UINT* pFirstConstant,
    const UINT* pNumConstants )
{
    LOG_DLL_ENTRY;
}

////////////////////////////////////////////////////////////////////////////////
VOID WINAPI PsSetShaderResources(
    D3D10DDI_HDEVICE hDevice,
    UINT StartSlot,
    UINT NumViews,
    const D3D10DDI_HSHADERRESOURCEVIEW* hShaderresourceview )
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
VOID WINAPI PsSetSamplers(
    D3D10DDI_HDEVICE hDevice,
    UINT StartSlot,
    UINT NumSamplers,
    const D3D10DDI_HSAMPLER* hSampler )
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
VOID WINAPI DrawIndexed(
    D3D10DDI_HDEVICE hDevice,
    UINT arg1,
    UINT arg2,
    INT arg3 )
{
    LOG_DLL_ENTRY;
}

////////////////////////////////////////////////////////////////////////////////
VOID WINAPI Draw(
    D3D10DDI_HDEVICE hDevice,
    UINT arg1,
    UINT arg2 )
{
    LOG_DLL_ENTRY;
}

////////////////////////////////////////////////////////////////////////////////
VOID WINAPI DynamicIABufferMapNoOverwrite(
    D3D10DDI_HDEVICE hDevice,
    D3D10DDI_HRESOURCE hResource,
    UINT arg1,
    D3D10_DDI_MAP map,
    UINT arg2,
    D3D10DDI_MAPPED_SUBRESOURCE* pSubresource )
{
    LOG_DLL_ENTRY;
}

////////////////////////////////////////////////////////////////////////////////
VOID WINAPI DynamicIABufferUnmap(
    D3D10DDI_HDEVICE hDevice,
    D3D10DDI_HRESOURCE hResource,
    UINT arg )
{
    LOG_DLL_ENTRY;
}

////////////////////////////////////////////////////////////////////////////////
VOID WINAPI DynamicConstantBufferMapDiscard(
    D3D10DDI_HDEVICE hDevice,
    D3D10DDI_HRESOURCE hResource,
    UINT arg1,
    D3D10_DDI_MAP map,
    UINT arg2,
    D3D10DDI_MAPPED_SUBRESOURCE* pSubresource )
{
    LOG_DLL_ENTRY;
}

////////////////////////////////////////////////////////////////////////////////
VOID WINAPI DynamicIABufferMapDiscard(
    D3D10DDI_HDEVICE hDevice,
    D3D10DDI_HRESOURCE hResource,
    UINT arg1,
    D3D10_DDI_MAP map,
    UINT arg2,
    D3D10DDI_MAPPED_SUBRESOURCE* pSubresource )
{
    LOG_DLL_ENTRY;
}

////////////////////////////////////////////////////////////////////////////////
VOID WINAPI DynamicConstantBufferUnmap(
    D3D10DDI_HDEVICE hDevice,
    D3D10DDI_HRESOURCE hResource,
    UINT arg )
{
    LOG_DLL_ENTRY;
}

////////////////////////////////////////////////////////////////////////////////
VOID WINAPI PsSetConstantBuffers(
    D3D10DDI_HDEVICE hDevice,
    UINT StartSlot,
    UINT NumBuffers,
    const D3D10DDI_HRESOURCE* hResource,
    const UINT* pFirstConstant,
    const UINT* pNumConstants )
{
    LOG_DLL_ENTRY;
}

////////////////////////////////////////////////////////////////////////////////
VOID WINAPI IaSetInputLayout(
    D3D10DDI_HDEVICE hDevice,
    D3D10DDI_HELEMENTLAYOUT hElementlayout )
{
    LOG_DLL_ENTRY;
}

////////////////////////////////////////////////////////////////////////////////
VOID WINAPI IaSetVertexBuffers(
    D3D10DDI_HDEVICE hDevice,
    UINT StartSlot,
    UINT NumBuffers,
    const D3D10DDI_HRESOURCE* hResource,
    const UINT* arg1,
    const UINT* arg2 )
{
    LOG_DLL_ENTRY;
}

////////////////////////////////////////////////////////////////////////////////
VOID WINAPI IaSetIndexBuffer(
    D3D10DDI_HDEVICE hDevice,
    D3D10DDI_HRESOURCE hResource,
    DXGI_FORMAT format,
    UINT arg )
{
    LOG_DLL_ENTRY;
}

////////////////////////////////////////////////////////////////////////////////
VOID WINAPI DrawIndexedInstanced(
    D3D10DDI_HDEVICE hDevice,
    UINT arg1,
    UINT arg2,
    UINT arg3,
    INT arg4,
    UINT arg5 )
{
    LOG_DLL_ENTRY;
}

////////////////////////////////////////////////////////////////////////////////
VOID WINAPI DrawInstanced(
    D3D10DDI_HDEVICE hDevice,
    UINT arg1,
    UINT arg2,
    UINT arg3,
    UINT arg4 )
{
    LOG_DLL_ENTRY;
}

////////////////////////////////////////////////////////////////////////////////
VOID WINAPI DynamicResourceMapDiscard(
    D3D10DDI_HDEVICE hDevice,
    D3D10DDI_HRESOURCE hResource,
    UINT arg1,
    D3D10_DDI_MAP map,
    UINT arg2,
    D3D10DDI_MAPPED_SUBRESOURCE* pSubresource )
{
    LOG_DLL_ENTRY;
}

////////////////////////////////////////////////////////////////////////////////
VOID WINAPI DynamicResourceUnmap(
    D3D10DDI_HDEVICE hDevice,
    D3D10DDI_HRESOURCE hResource,
    UINT arg )
{
    LOG_DLL_ENTRY;
}

////////////////////////////////////////////////////////////////////////////////
VOID WINAPI GsSetConstantBuffers(
    D3D10DDI_HDEVICE hDevice,
    UINT StartSlot,
    UINT NumBuffers,
    const D3D10DDI_HRESOURCE* hResource,
    const UINT* pFirstConstant,
    const UINT* pNumConstants )
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
VOID WINAPI IaSetTopology(
    D3D10DDI_HDEVICE hDevice,
    D3D10_DDI_PRIMITIVE_TOPOLOGY topology )
{
    LOG_DLL_ENTRY;
}

////////////////////////////////////////////////////////////////////////////////
VOID WINAPI StagingResourceMap(
    D3D10DDI_HDEVICE hDevice,
    D3D10DDI_HRESOURCE hResource,
    UINT arg1,
    D3D10_DDI_MAP map,
    UINT arg2,
    D3D10DDI_MAPPED_SUBRESOURCE* pSubresource )
{
    LOG_DLL_ENTRY;
}

////////////////////////////////////////////////////////////////////////////////
VOID WINAPI StagingResourceUnmap(
    D3D10DDI_HDEVICE hDevice,
    D3D10DDI_HRESOURCE hResource,
    UINT arg )
{
    LOG_DLL_ENTRY;
}

////////////////////////////////////////////////////////////////////////////////
VOID WINAPI VsSetShaderResources(
    D3D10DDI_HDEVICE hDevice,
    UINT StartSlot,
    UINT NumViews,
    const D3D10DDI_HSHADERRESOURCEVIEW* hShaderresourceview )
{
    LOG_DLL_ENTRY;
}

////////////////////////////////////////////////////////////////////////////////
VOID WINAPI VsSetSamplers(
    D3D10DDI_HDEVICE hDevice,
    UINT StartSlot,
    UINT NumSamplers,
    const D3D10DDI_HSAMPLER* hSampler )
{
    LOG_DLL_ENTRY;
}

////////////////////////////////////////////////////////////////////////////////
VOID WINAPI GsSetShaderResources(
    D3D10DDI_HDEVICE hDevice,
    UINT StartSlot,
    UINT NumViews,
    const D3D10DDI_HSHADERRESOURCEVIEW* hShaderresourceview )
{
    LOG_DLL_ENTRY;
}

////////////////////////////////////////////////////////////////////////////////
VOID WINAPI GsSetSamplers(
    D3D10DDI_HDEVICE hDevice,
    UINT StartSlot,
    UINT NumSamplers,
    const D3D10DDI_HSAMPLER* hSampler )
{
    LOG_DLL_ENTRY;
}

////////////////////////////////////////////////////////////////////////////////
VOID WINAPI SetRenderTargets(
    D3D10DDI_HDEVICE hDevice,
    const D3D10DDI_HRENDERTARGETVIEW* hRendertargetview,
    UINT NumRTVs,
    UINT ClearSlots,
    D3D10DDI_HDEPTHSTENCILVIEW hDepthstencilview,
    const D3D11DDI_HUNORDEREDACCESSVIEW* hUnorderedaccessview,
    const UINT* arg,
    UINT UAVStartSlot,
    UINT NumUAVs,
    UINT UAVRangeStart,
    UINT UAVRangeSize )
{
    LOG_DLL_ENTRY;
}

////////////////////////////////////////////////////////////////////////////////
VOID WINAPI ShaderResourceViewReadAfterWriteHazard(
    D3D10DDI_HDEVICE hDevice,
    D3D10DDI_HSHADERRESOURCEVIEW hShaderresourceview,
    D3D10DDI_HRESOURCE hResource )
{
    LOG_DLL_ENTRY;
}

////////////////////////////////////////////////////////////////////////////////
VOID WINAPI ResourceReadAfterWriteHazard(
    D3D10DDI_HDEVICE hDevice,
    D3D10DDI_HRESOURCE hResource )
{
    LOG_DLL_ENTRY;
}

////////////////////////////////////////////////////////////////////////////////
VOID WINAPI SetBlendState(
    D3D10DDI_HDEVICE hDevice,
    D3D10DDI_HBLENDSTATE hBlendstate,
    const FLOAT arg1[4],
    UINT arg2 )
{
    LOG_DLL_ENTRY;
}

////////////////////////////////////////////////////////////////////////////////
VOID WINAPI SetDepthStencilState(
    D3D10DDI_HDEVICE hDevice,
    D3D10DDI_HDEPTHSTENCILSTATE hDepthstencilstate,
    UINT arg )
{
    LOG_DLL_ENTRY;
}

////////////////////////////////////////////////////////////////////////////////
VOID WINAPI SetRasterizerState(
    D3D10DDI_HDEVICE hDevice,
    D3D10DDI_HRASTERIZERSTATE hRasterizerstate )
{
    LOG_DLL_ENTRY;
}

////////////////////////////////////////////////////////////////////////////////
VOID WINAPI QueryEnd(
    D3D10DDI_HDEVICE hDevice,
    D3D10DDI_HQUERY hQuery )
{
    LOG_DLL_ENTRY;
}

////////////////////////////////////////////////////////////////////////////////
VOID WINAPI QueryBegin(
    D3D10DDI_HDEVICE hDevice,
    D3D10DDI_HQUERY hQuery )
{
    LOG_DLL_ENTRY;
}

////////////////////////////////////////////////////////////////////////////////
VOID WINAPI ResourceCopyRegion(
    D3D10DDI_HDEVICE hDevice,
    D3D10DDI_HRESOURCE hResource1,
    UINT arg1,
    UINT arg2,
    UINT arg3,
    UINT arg4,
    D3D10DDI_HRESOURCE hResource2,
    UINT arg5,
    const D3D10_DDI_BOX* pBox,
    UINT CopyFlags )
{
    LOG_DLL_ENTRY;
}

////////////////////////////////////////////////////////////////////////////////
VOID WINAPI ResourceUpdateSubresourceUP(
    D3D10DDI_HDEVICE hDevice,
    D3D10DDI_HRESOURCE hResource,
    UINT arg1,
    const D3D10_DDI_BOX* pBox,
    const void* arg2,
    UINT arg3,
    UINT arg4,
    UINT CopyFlags )
{
    LOG_DLL_ENTRY;
}

////////////////////////////////////////////////////////////////////////////////
VOID WINAPI SoSetTargets(
    D3D10DDI_HDEVICE hDevice,
    UINT NumBuffers,
    UINT ClearTargets,
    const D3D10DDI_HRESOURCE* hResource,
    const UINT* arg )
{
    LOG_DLL_ENTRY;
}

////////////////////////////////////////////////////////////////////////////////
VOID WINAPI DrawAuto(
    D3D10DDI_HDEVICE hDevice )
{
    LOG_DLL_ENTRY;
}

////////////////////////////////////////////////////////////////////////////////
VOID WINAPI SetViewports(
    D3D10DDI_HDEVICE hDevice,
    UINT NumViewports,
    UINT ClearViewports,
    const D3D10_DDI_VIEWPORT* pViewport )
{
    LOG_DLL_ENTRY;
}

////////////////////////////////////////////////////////////////////////////////
VOID WINAPI SetScissorRects(
    D3D10DDI_HDEVICE hDevice,
    UINT NumRects,
    UINT ClearRects,
    const D3D10_DDI_RECT* pRect )
{
    LOG_DLL_ENTRY;
}

////////////////////////////////////////////////////////////////////////////////
VOID WINAPI ClearRenderTargetView(
    D3D10DDI_HDEVICE hDevice,
    D3D10DDI_HRENDERTARGETVIEW hRendertargetview,
    FLOAT arg[4] )
{
    LOG_DLL_ENTRY;
}

////////////////////////////////////////////////////////////////////////////////
VOID WINAPI ClearDepthStencilView(
    D3D10DDI_HDEVICE hDevice,
    D3D10DDI_HDEPTHSTENCILVIEW hDepthstencilview,
    UINT arg1,
    FLOAT arg2,
    UINT8 arg3 )
{
    LOG_DLL_ENTRY;
}

////////////////////////////////////////////////////////////////////////////////
VOID WINAPI SetPredication(
    D3D10DDI_HDEVICE hDevice,
    D3D10DDI_HQUERY hQuery,
    BOOL arg )
{
    LOG_DLL_ENTRY;
}

////////////////////////////////////////////////////////////////////////////////
VOID WINAPI QueryGetData(
    D3D10DDI_HDEVICE hDevice,
    D3D10DDI_HQUERY hQuery,
    void* arg1,
    UINT DataSize,
    UINT arg2 )
{
    LOG_DLL_ENTRY;
}

////////////////////////////////////////////////////////////////////////////////
BOOL WINAPI Flush(
    D3D10DDI_HDEVICE hDevice,
    UINT FlushFlags )
{
    LOG_DLL_ENTRY;
    return FALSE;
}

////////////////////////////////////////////////////////////////////////////////
VOID WINAPI GenMips(
    D3D10DDI_HDEVICE hDevice,
    D3D10DDI_HSHADERRESOURCEVIEW hShaderresourceview )
{
    LOG_DLL_ENTRY;
}

////////////////////////////////////////////////////////////////////////////////
VOID WINAPI ResourceCopy(
    D3D10DDI_HDEVICE hDevice,
    D3D10DDI_HRESOURCE hResource1,
    D3D10DDI_HRESOURCE hResource2 )
{
    LOG_DLL_ENTRY;
}

////////////////////////////////////////////////////////////////////////////////
VOID WINAPI ResourceResolveSubresource(
    D3D10DDI_HDEVICE hDevice,
    D3D10DDI_HRESOURCE hResource1,
    UINT arg1,
    D3D10DDI_HRESOURCE hResource2,
    UINT arg2,
    DXGI_FORMAT format )
{
    LOG_DLL_ENTRY;
}

////////////////////////////////////////////////////////////////////////////////
VOID WINAPI ResourceMap(
    D3D10DDI_HDEVICE hDevice,
    D3D10DDI_HRESOURCE hResource,
    UINT arg1,
    D3D10_DDI_MAP map,
    UINT arg2,
    D3D10DDI_MAPPED_SUBRESOURCE* pSubresource )
{
    LOG_DLL_ENTRY;
}

////////////////////////////////////////////////////////////////////////////////
VOID WINAPI ResourceUnmap(
    D3D10DDI_HDEVICE hDevice,
    D3D10DDI_HRESOURCE hResource,
    UINT arg )
{
    LOG_DLL_ENTRY;
}

////////////////////////////////////////////////////////////////////////////////
BOOL WINAPI ResourceIsStagingBusy(
    D3D10DDI_HDEVICE hDevice,
    D3D10DDI_HRESOURCE hResource )
{
    LOG_DLL_ENTRY;
    return FALSE;
}

////////////////////////////////////////////////////////////////////////////////
VOID WINAPI RelocateDeviceFuncs(
    D3D10DDI_HDEVICE hDevice,
    struct D3D11_1DDI_DEVICEFUNCS* pFuncs )
{
    LOG_DLL_ENTRY;
}

////////////////////////////////////////////////////////////////////////////////
SIZE_T WINAPI CalcPrivateResourceSize(
    D3D10DDI_HDEVICE hDevice,
    const D3D11DDIARG_CREATERESOURCE* pCreateresource )
{
    LOG_DLL_ENTRY;
    return 0;
}

////////////////////////////////////////////////////////////////////////////////
SIZE_T WINAPI CalcPrivateOpenedResourceSize(
    D3D10DDI_HDEVICE hDevice,
    const D3D10DDIARG_OPENRESOURCE* pOpenresource )
{
    LOG_DLL_ENTRY;
    return 0;
}

////////////////////////////////////////////////////////////////////////////////
VOID WINAPI CreateResource(
    D3D10DDI_HDEVICE hDevice,
    const D3D11DDIARG_CREATERESOURCE* pCreateresource,
    D3D10DDI_HRESOURCE hResource,
    D3D10DDI_HRTRESOURCE hRtresource )
{
    LOG_DLL_ENTRY;
}

////////////////////////////////////////////////////////////////////////////////
VOID WINAPI OpenResource(
    D3D10DDI_HDEVICE hDevice,
    const D3D10DDIARG_OPENRESOURCE* pOpenresource,
    D3D10DDI_HRESOURCE hResource,
    D3D10DDI_HRTRESOURCE hRtresource )
{
    LOG_DLL_ENTRY;
}

////////////////////////////////////////////////////////////////////////////////
VOID WINAPI DestroyResource(
    D3D10DDI_HDEVICE hDevice,
    D3D10DDI_HRESOURCE hResource )
{
    LOG_DLL_ENTRY;
}

////////////////////////////////////////////////////////////////////////////////
SIZE_T WINAPI CalcPrivateShaderResourceViewSize(
    D3D10DDI_HDEVICE hDevice,
    const D3D11DDIARG_CREATESHADERRESOURCEVIEW* pCreateshaderresourceview )
{
    LOG_DLL_ENTRY;
    return 0;
}

////////////////////////////////////////////////////////////////////////////////
VOID WINAPI CreateShaderResourceView(
    D3D10DDI_HDEVICE hDevice,
    const D3D11DDIARG_CREATESHADERRESOURCEVIEW* pCreateshaderresourceview,
    D3D10DDI_HSHADERRESOURCEVIEW hShaderresourceview,
    D3D10DDI_HRTSHADERRESOURCEVIEW hRtshaderresourceview )
{
    LOG_DLL_ENTRY;
}

////////////////////////////////////////////////////////////////////////////////
VOID WINAPI DestroyShaderResourceView(
    D3D10DDI_HDEVICE hDevice,
    D3D10DDI_HSHADERRESOURCEVIEW hShaderresourceview )
{
    LOG_DLL_ENTRY;
}

////////////////////////////////////////////////////////////////////////////////
SIZE_T WINAPI CalcPrivateRenderTargetViewSize(
    D3D10DDI_HDEVICE hDevice,
    const D3D10DDIARG_CREATERENDERTARGETVIEW* pCreaterendertargetview )
{
    LOG_DLL_ENTRY;
    return 0;
}

////////////////////////////////////////////////////////////////////////////////
VOID WINAPI CreateRenderTargetView(
    D3D10DDI_HDEVICE hDevice,
    const D3D10DDIARG_CREATERENDERTARGETVIEW* pCreaterendertargetview,
    D3D10DDI_HRENDERTARGETVIEW hRendertargetview,
    D3D10DDI_HRTRENDERTARGETVIEW hRtrendertargetview )
{
    LOG_DLL_ENTRY;
}

////////////////////////////////////////////////////////////////////////////////
VOID WINAPI DestroyRenderTargetView(
    D3D10DDI_HDEVICE hDevice,
    D3D10DDI_HRENDERTARGETVIEW hRendertargetview )
{
    LOG_DLL_ENTRY;
}

////////////////////////////////////////////////////////////////////////////////
SIZE_T WINAPI CalcPrivateDepthStencilViewSize(
    D3D10DDI_HDEVICE hDevice,
    const D3D11DDIARG_CREATEDEPTHSTENCILVIEW* pCreatedepthstencilview )
{
    LOG_DLL_ENTRY;
    return 0;
}

////////////////////////////////////////////////////////////////////////////////
VOID WINAPI CreateDepthStencilView(
    D3D10DDI_HDEVICE hDevice,
    const D3D11DDIARG_CREATEDEPTHSTENCILVIEW* pCreatedepthstencilview,
    D3D10DDI_HDEPTHSTENCILVIEW hDepthstencilview,
    D3D10DDI_HRTDEPTHSTENCILVIEW hRtdepthstencilview )
{
    LOG_DLL_ENTRY;
}

////////////////////////////////////////////////////////////////////////////////
VOID WINAPI DestroyDepthStencilView(
    D3D10DDI_HDEVICE hDevice,
    D3D10DDI_HDEPTHSTENCILVIEW hDepthstencilview )
{
    LOG_DLL_ENTRY;
}

////////////////////////////////////////////////////////////////////////////////
SIZE_T WINAPI CalcPrivateElementLayoutSize(
    D3D10DDI_HDEVICE hDevice,
    const D3D10DDIARG_CREATEELEMENTLAYOUT* pCreateelementlayout )
{
    LOG_DLL_ENTRY;
    return 0;
}

////////////////////////////////////////////////////////////////////////////////
VOID WINAPI CreateElementLayout(
    D3D10DDI_HDEVICE hDevice,
    const D3D10DDIARG_CREATEELEMENTLAYOUT* pCreateelementlayout,
    D3D10DDI_HELEMENTLAYOUT hElementlayout,
    D3D10DDI_HRTELEMENTLAYOUT hRtelementlayout )
{
    LOG_DLL_ENTRY;
}

////////////////////////////////////////////////////////////////////////////////
VOID WINAPI DestroyElementLayout(
    D3D10DDI_HDEVICE hDevice,
    D3D10DDI_HELEMENTLAYOUT hElementlayout )
{
    LOG_DLL_ENTRY;
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
VOID WINAPI CreateBlendState(
    D3D10DDI_HDEVICE hDevice,
    const D3D11_1_DDI_BLEND_DESC* pBlendDesc,
    D3D10DDI_HBLENDSTATE hBlendstate,
    D3D10DDI_HRTBLENDSTATE hRtblendstate )
{
    LOG_DLL_ENTRY;
}

////////////////////////////////////////////////////////////////////////////////
VOID WINAPI DestroyBlendState(
    D3D10DDI_HDEVICE hDevice,
    D3D10DDI_HBLENDSTATE hBlendstate )
{
    LOG_DLL_ENTRY;
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
VOID WINAPI CreateDepthStencilState(
    D3D10DDI_HDEVICE hDevice,
    const D3D10_DDI_DEPTH_STENCIL_DESC* pDepthStencilDesc,
    D3D10DDI_HDEPTHSTENCILSTATE hDepthstencilstate,
    D3D10DDI_HRTDEPTHSTENCILSTATE hRtdepthstencilstate )
{
    LOG_DLL_ENTRY;
}

////////////////////////////////////////////////////////////////////////////////
VOID WINAPI DestroyDepthStencilState(
    D3D10DDI_HDEVICE hDevice,
    D3D10DDI_HDEPTHSTENCILSTATE hDepthstencilstate )
{
    LOG_DLL_ENTRY;
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
VOID WINAPI CreateRasterizerState(
    D3D10DDI_HDEVICE hDevice,
    const D3D11_1_DDI_RASTERIZER_DESC* pRasterizerDesc,
    D3D10DDI_HRASTERIZERSTATE hRasterizerstate,
    D3D10DDI_HRTRASTERIZERSTATE hRtrasterizerstate )
{
    LOG_DLL_ENTRY;
}

////////////////////////////////////////////////////////////////////////////////
VOID WINAPI DestroyRasterizerState(
    D3D10DDI_HDEVICE hDevice,
    D3D10DDI_HRASTERIZERSTATE hRasterizerstate )
{
    LOG_DLL_ENTRY;
}

////////////////////////////////////////////////////////////////////////////////
SIZE_T WINAPI CalcPrivateShaderSize(
    D3D10DDI_HDEVICE hDevice,
    const UINT* pShaderCode,
    const D3D11_1DDIARG_STAGE_IO_SIGNATURES* pIOSignatures )
{
    LOG_DLL_ENTRY;
    return 0;
}

////////////////////////////////////////////////////////////////////////////////
VOID WINAPI CreateVertexShader(
    D3D10DDI_HDEVICE hDevice,
    const UINT* pShaderCode,
    D3D10DDI_HSHADER hShader,
    D3D10DDI_HRTSHADER hRtshader,
    const D3D11_1DDIARG_STAGE_IO_SIGNATURES* pIOSignatures )
{
    LOG_DLL_ENTRY;
}

////////////////////////////////////////////////////////////////////////////////
VOID WINAPI CreateGeometryShader(
    D3D10DDI_HDEVICE hDevice,
    const UINT* pShaderCode,
    D3D10DDI_HSHADER hShader,
    D3D10DDI_HRTSHADER hRtshader,
    const D3D11_1DDIARG_STAGE_IO_SIGNATURES* pIOSignatures )
{
    LOG_DLL_ENTRY;
}

////////////////////////////////////////////////////////////////////////////////
VOID WINAPI CreatePixelShader(
    D3D10DDI_HDEVICE hDevice,
    const UINT* pShaderCode,
    D3D10DDI_HSHADER hShader,
    D3D10DDI_HRTSHADER hRtshader,
    const D3D11_1DDIARG_STAGE_IO_SIGNATURES* pIOSignatures )
{
    LOG_DLL_ENTRY;
}

////////////////////////////////////////////////////////////////////////////////
SIZE_T WINAPI CalcPrivateGeometryShaderWithStreamOutput(
    D3D10DDI_HDEVICE hDevice,
    const D3D11DDIARG_CREATEGEOMETRYSHADERWITHSTREAMOUTPUT* pCreategeometryshaderwithstreamoutput,
    const D3D11_1DDIARG_STAGE_IO_SIGNATURES* pIOSignatures )
{
    LOG_DLL_ENTRY;
    return 0;
}

////////////////////////////////////////////////////////////////////////////////
VOID WINAPI CreateGeometryShaderWithStreamOutput(
    D3D10DDI_HDEVICE hDevice,
    const D3D11DDIARG_CREATEGEOMETRYSHADERWITHSTREAMOUTPUT* pCreategeometryshaderwithstreamoutput,
    D3D10DDI_HSHADER hShader,
    D3D10DDI_HRTSHADER hRtshader,
    const D3D11_1DDIARG_STAGE_IO_SIGNATURES* pIOSignatures )
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
SIZE_T WINAPI CalcPrivateSamplerSize(
    D3D10DDI_HDEVICE hDevice,
    const D3D10_DDI_SAMPLER_DESC* pSamplerDesc )
{
    LOG_DLL_ENTRY;
    return 0;
}

////////////////////////////////////////////////////////////////////////////////
VOID WINAPI CreateSampler(
    D3D10DDI_HDEVICE hDevice,
    const D3D10_DDI_SAMPLER_DESC* pSamplerDesc,
    D3D10DDI_HSAMPLER hSampler,
    D3D10DDI_HRTSAMPLER hRtsampler )
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
SIZE_T WINAPI CalcPrivateQuerySize(
    D3D10DDI_HDEVICE hDevice,
    const D3D10DDIARG_CREATEQUERY* pCreatequery )
{
    LOG_DLL_ENTRY;
    return 0;
}

////////////////////////////////////////////////////////////////////////////////
VOID WINAPI CreateQuery(
    D3D10DDI_HDEVICE hDevice,
    const D3D10DDIARG_CREATEQUERY* pCreatequery,
    D3D10DDI_HQUERY hQuery,
    D3D10DDI_HRTQUERY hRtquery )
{
    LOG_DLL_ENTRY;
}

////////////////////////////////////////////////////////////////////////////////
VOID WINAPI DestroyQuery(
    D3D10DDI_HDEVICE hDevice,
    D3D10DDI_HQUERY hQuery )
{
    LOG_DLL_ENTRY;
}

////////////////////////////////////////////////////////////////////////////////
VOID WINAPI CheckFormatSupport(
    D3D10DDI_HDEVICE hDevice,
    DXGI_FORMAT format,
    UINT* arg )
{
    LOG_DLL_ENTRY;
}

////////////////////////////////////////////////////////////////////////////////
VOID WINAPI CheckMultisampleQualityLevels(
    D3D10DDI_HDEVICE hDevice,
    DXGI_FORMAT format,
    UINT arg1,
    UINT* arg2 )
{
    LOG_DLL_ENTRY;
}

////////////////////////////////////////////////////////////////////////////////
VOID WINAPI CheckCounterInfo(
    D3D10DDI_HDEVICE hDevice,
    D3D10DDI_COUNTER_INFO* pCounterInfo )
{
    LOG_DLL_ENTRY;
}

////////////////////////////////////////////////////////////////////////////////
VOID WINAPI CheckCounter(
    D3D10DDI_HDEVICE hDevice,
    D3D10DDI_QUERY query,
    D3D10DDI_COUNTER_TYPE* pCounterType,
    UINT* arg1,
    LPSTR arg2,
    UINT* pNameLength,
    LPSTR arg3,
    UINT* pUnitsLength,
    LPSTR arg4,
    UINT* pDescriptionLength )
{
    LOG_DLL_ENTRY;
}

////////////////////////////////////////////////////////////////////////////////
VOID WINAPI DestroyDevice(
    D3D10DDI_HDEVICE hDevice )
{
    LOG_DLL_ENTRY;
}

////////////////////////////////////////////////////////////////////////////////
VOID WINAPI SetTextFilterSize(
    D3D10DDI_HDEVICE hDevice,
    UINT arg1,
    UINT arg2 )
{
    LOG_DLL_ENTRY;
}

////////////////////////////////////////////////////////////////////////////////
VOID WINAPI ResourceConvert(
    D3D10DDI_HDEVICE hDevice,
    D3D10DDI_HRESOURCE hResource1,
    D3D10DDI_HRESOURCE hResource2 )
{
    LOG_DLL_ENTRY;
}

////////////////////////////////////////////////////////////////////////////////
VOID WINAPI ResourceConvertRegion(
    D3D10DDI_HDEVICE hDevice,
    D3D10DDI_HRESOURCE hResource1,
    UINT arg1,
    UINT arg2,
    UINT arg3,
    UINT arg4,
    D3D10DDI_HRESOURCE hResource2,
    UINT arg5,
    const D3D10_DDI_BOX* pBox,
    UINT CopyFlags )
{
    LOG_DLL_ENTRY;
}

////////////////////////////////////////////////////////////////////////////////
VOID WINAPI DrawIndexedInstancedIndirect(
    D3D10DDI_HDEVICE hDevice,
    D3D10DDI_HRESOURCE hResource,
    UINT arg )
{
    LOG_DLL_ENTRY;
}

////////////////////////////////////////////////////////////////////////////////
VOID WINAPI DrawInstancedIndirect(
    D3D10DDI_HDEVICE hDevice,
    D3D10DDI_HRESOURCE hResource,
    UINT arg )
{
    LOG_DLL_ENTRY;
}

////////////////////////////////////////////////////////////////////////////////
VOID WINAPI CommandListExecute(
    D3D10DDI_HDEVICE hDevice,
    D3D11DDI_HCOMMANDLIST hCommandlist )
{
    LOG_DLL_ENTRY;
}

////////////////////////////////////////////////////////////////////////////////
VOID WINAPI HsSetShaderResources(
    D3D10DDI_HDEVICE hDevice,
    UINT StartSlot,
    UINT NumViews,
    const D3D10DDI_HSHADERRESOURCEVIEW* hShaderresourceview )
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
VOID WINAPI HsSetSamplers(
    D3D10DDI_HDEVICE hDevice,
    UINT StartSlot,
    UINT NumSamplers,
    const D3D10DDI_HSAMPLER* hSampler )
{
    LOG_DLL_ENTRY;
}

////////////////////////////////////////////////////////////////////////////////
VOID WINAPI HsSetConstantBuffers(
    D3D10DDI_HDEVICE hDevice,
    UINT StartSlot,
    UINT NumBuffers,
    const D3D10DDI_HRESOURCE* hResource,
    const UINT* pFirstConstant,
    const UINT* pNumConstants )
{
    LOG_DLL_ENTRY;
}

////////////////////////////////////////////////////////////////////////////////
VOID WINAPI DsSetShaderResources(
    D3D10DDI_HDEVICE hDevice,
    UINT StartSlot,
    UINT NumViews,
    const D3D10DDI_HSHADERRESOURCEVIEW* hShaderresourceview )
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
VOID WINAPI DsSetSamplers(
    D3D10DDI_HDEVICE hDevice,
    UINT StartSlot,
    UINT NumSamplers,
    const D3D10DDI_HSAMPLER* hSampler )
{
    LOG_DLL_ENTRY;
}

////////////////////////////////////////////////////////////////////////////////
VOID WINAPI DsSetConstantBuffers(
    D3D10DDI_HDEVICE hDevice,
    UINT StartSlot,
    UINT NumBuffers,
    const D3D10DDI_HRESOURCE* hResource,
    const UINT* pFirstConstant,
    const UINT* pNumConstants )
{
    LOG_DLL_ENTRY;
}

////////////////////////////////////////////////////////////////////////////////
VOID WINAPI CreateHullShader(
    D3D10DDI_HDEVICE hDevice,
    const UINT* pShaderCode,
    D3D10DDI_HSHADER hShader,
    D3D10DDI_HRTSHADER hRtshader,
    const D3D11_1DDIARG_TESSELLATION_IO_SIGNATURES* pIOSignatures )
{
    LOG_DLL_ENTRY;
}

////////////////////////////////////////////////////////////////////////////////
VOID WINAPI CreateDomainShader(
    D3D10DDI_HDEVICE hDevice,
    const UINT* pShaderCode,
    D3D10DDI_HSHADER hShader,
    D3D10DDI_HRTSHADER hRtshader,
    const D3D11_1DDIARG_TESSELLATION_IO_SIGNATURES* pIOSignatures )
{
    LOG_DLL_ENTRY;
}

////////////////////////////////////////////////////////////////////////////////
VOID WINAPI CheckDeferredContextHandleSizes(
    D3D10DDI_HDEVICE hDevice,
    UINT* pHSizes,
    D3D11DDI_HANDLESIZE* hAndlesize )
{
    LOG_DLL_ENTRY;
}

////////////////////////////////////////////////////////////////////////////////
SIZE_T WINAPI CalcDeferredContextHandleSize(
    D3D10DDI_HDEVICE hDevice,
    D3D11DDI_HANDLETYPE hAndletype,
    void* arg )
{
    LOG_DLL_ENTRY;
    return 0;
}

////////////////////////////////////////////////////////////////////////////////
SIZE_T WINAPI CalcPrivateDeferredContextSize(
    D3D10DDI_HDEVICE hDevice,
    const D3D11DDIARG_CALCPRIVATEDEFERREDCONTEXTSIZE* pCalcprivatedeferredcontextsize )
{
    LOG_DLL_ENTRY;
    return 0;
}

////////////////////////////////////////////////////////////////////////////////
VOID WINAPI CreateDeferredContext(
    D3D10DDI_HDEVICE hDevice,
    const D3D11DDIARG_CREATEDEFERREDCONTEXT* pCreatedeferredcontext )
{
    LOG_DLL_ENTRY;
}

////////////////////////////////////////////////////////////////////////////////
VOID WINAPI AbandonCommandList(
    D3D10DDI_HDEVICE hDevice )
{
    LOG_DLL_ENTRY;
}

////////////////////////////////////////////////////////////////////////////////
SIZE_T WINAPI CalcPrivateCommandListSize(
    D3D10DDI_HDEVICE hDevice,
    const D3D11DDIARG_CREATECOMMANDLIST* pCreatecommandlist )
{
    LOG_DLL_ENTRY;
    return 0;
}

////////////////////////////////////////////////////////////////////////////////
VOID WINAPI CreateCommandList(
    D3D10DDI_HDEVICE hDevice,
    const D3D11DDIARG_CREATECOMMANDLIST* pCreatecommandlist,
    D3D11DDI_HCOMMANDLIST hCommandlist,
    D3D11DDI_HRTCOMMANDLIST hRtcommandlist )
{
    LOG_DLL_ENTRY;
}

////////////////////////////////////////////////////////////////////////////////
VOID WINAPI DestroyCommandList(
    D3D10DDI_HDEVICE hDevice,
    D3D11DDI_HCOMMANDLIST hCommandlist )
{
    LOG_DLL_ENTRY;
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
VOID WINAPI PsSetShaderWithIfaces(
    D3D10DDI_HDEVICE hDevice,
    D3D10DDI_HSHADER hShader,
    UINT NumClassInstances,
    const UINT* arg,
    const D3D11DDIARG_POINTERDATA* pPointerdata )
{
    LOG_DLL_ENTRY;
}

////////////////////////////////////////////////////////////////////////////////
VOID WINAPI VsSetShaderWithIfaces(
    D3D10DDI_HDEVICE hDevice,
    D3D10DDI_HSHADER hShader,
    UINT NumClassInstances,
    const UINT* arg,
    const D3D11DDIARG_POINTERDATA* pPointerdata )
{
    LOG_DLL_ENTRY;
}

////////////////////////////////////////////////////////////////////////////////
VOID WINAPI GsSetShaderWithIfaces(
    D3D10DDI_HDEVICE hDevice,
    D3D10DDI_HSHADER hShader,
    UINT NumClassInstances,
    const UINT* arg,
    const D3D11DDIARG_POINTERDATA* pPointerdata )
{
    LOG_DLL_ENTRY;
}

////////////////////////////////////////////////////////////////////////////////
VOID WINAPI HsSetShaderWithIfaces(
    D3D10DDI_HDEVICE hDevice,
    D3D10DDI_HSHADER hShader,
    UINT NumClassInstances,
    const UINT* arg,
    const D3D11DDIARG_POINTERDATA* pPointerdata )
{
    LOG_DLL_ENTRY;
}

////////////////////////////////////////////////////////////////////////////////
VOID WINAPI DsSetShaderWithIfaces(
    D3D10DDI_HDEVICE hDevice,
    D3D10DDI_HSHADER hShader,
    UINT NumClassInstances,
    const UINT* arg,
    const D3D11DDIARG_POINTERDATA* pPointerdata )
{
    LOG_DLL_ENTRY;
}

////////////////////////////////////////////////////////////////////////////////
VOID WINAPI CsSetShaderWithIfaces(
    D3D10DDI_HDEVICE hDevice,
    D3D10DDI_HSHADER hShader,
    UINT NumClassInstances,
    const UINT* arg,
    const D3D11DDIARG_POINTERDATA* pPointerdata )
{
    LOG_DLL_ENTRY;
}

////////////////////////////////////////////////////////////////////////////////
VOID WINAPI CreateComputeShader(
    D3D10DDI_HDEVICE hDevice,
    const UINT* pShaderCode,
    D3D10DDI_HSHADER hShader,
    D3D10DDI_HRTSHADER hRtshader )
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
VOID WINAPI CsSetShaderResources(
    D3D10DDI_HDEVICE hDevice,
    UINT StartSlot,
    UINT NumViews,
    const D3D10DDI_HSHADERRESOURCEVIEW* hShaderresourceview )
{
    LOG_DLL_ENTRY;
}

////////////////////////////////////////////////////////////////////////////////
VOID WINAPI CsSetSamplers(
    D3D10DDI_HDEVICE hDevice,
    UINT StartSlot,
    UINT NumSamplers,
    const D3D10DDI_HSAMPLER* hSampler )
{
    LOG_DLL_ENTRY;
}

////////////////////////////////////////////////////////////////////////////////
VOID WINAPI CsSetConstantBuffers(
    D3D10DDI_HDEVICE hDevice,
    UINT StartSlot,
    UINT NumBuffers,
    const D3D10DDI_HRESOURCE* hResource,
    const UINT* pFirstConstant,
    const UINT* pNumConstants )
{
    LOG_DLL_ENTRY;
}

////////////////////////////////////////////////////////////////////////////////
SIZE_T WINAPI CalcPrivateUnorderedAccessViewSize(
    D3D10DDI_HDEVICE hDevice,
    const D3D11DDIARG_CREATEUNORDEREDACCESSVIEW* pCreateunorderedaccessview )
{
    LOG_DLL_ENTRY;
    return 0;
}

////////////////////////////////////////////////////////////////////////////////
VOID WINAPI CreateUnorderedAccessView(
    D3D10DDI_HDEVICE hDevice,
    const D3D11DDIARG_CREATEUNORDEREDACCESSVIEW* pCreateunorderedaccessview,
    D3D11DDI_HUNORDEREDACCESSVIEW hUnorderedaccessview,
    D3D11DDI_HRTUNORDEREDACCESSVIEW hRtunorderedaccessview )
{
    LOG_DLL_ENTRY;
}

////////////////////////////////////////////////////////////////////////////////
VOID WINAPI DestroyUnorderedAccessView(
    D3D10DDI_HDEVICE hDevice,
    D3D11DDI_HUNORDEREDACCESSVIEW hUnorderedaccessview )
{
    LOG_DLL_ENTRY;
}

////////////////////////////////////////////////////////////////////////////////
VOID WINAPI ClearUnorderedAccessViewUint(
    D3D10DDI_HDEVICE hDevice,
    D3D11DDI_HUNORDEREDACCESSVIEW hUnorderedaccessview,
    const UINT arg[4] )
{
    LOG_DLL_ENTRY;
}

////////////////////////////////////////////////////////////////////////////////
VOID WINAPI ClearUnorderedAccessViewFloat(
    D3D10DDI_HDEVICE hDevice,
    D3D11DDI_HUNORDEREDACCESSVIEW hUnorderedaccessview,
    const FLOAT arg[4] )
{
    LOG_DLL_ENTRY;
}

////////////////////////////////////////////////////////////////////////////////
VOID WINAPI CsSetUnorderedAccessViews(
    D3D10DDI_HDEVICE hDevice,
    UINT StartSlot,
    UINT NumViews,
    const D3D11DDI_HUNORDEREDACCESSVIEW* hUnorderedaccessview,
    const UINT* arg )
{
    LOG_DLL_ENTRY;
}

////////////////////////////////////////////////////////////////////////////////
VOID WINAPI Dispatch(
    D3D10DDI_HDEVICE hDevice,
    UINT arg1,
    UINT arg2,
    UINT arg3 )
{
    LOG_DLL_ENTRY;
}

////////////////////////////////////////////////////////////////////////////////
VOID WINAPI DispatchIndirect(
    D3D10DDI_HDEVICE hDevice,
    D3D10DDI_HRESOURCE hResource,
    UINT arg )
{
    LOG_DLL_ENTRY;
}

////////////////////////////////////////////////////////////////////////////////
VOID WINAPI SetResourceMinLOD(
    D3D10DDI_HDEVICE hDevice,
    D3D10DDI_HRESOURCE hResource,
    FLOAT arg )
{
    LOG_DLL_ENTRY;
}

////////////////////////////////////////////////////////////////////////////////
VOID WINAPI CopyStructureCount(
    D3D10DDI_HDEVICE hDevice,
    D3D10DDI_HRESOURCE hResource,
    UINT arg,
    D3D11DDI_HUNORDEREDACCESSVIEW hUnorderedaccessview )
{
    LOG_DLL_ENTRY;
}

////////////////////////////////////////////////////////////////////////////////
VOID WINAPI RecycleCommandList(
    D3D10DDI_HDEVICE hDevice,
    D3D11DDI_HCOMMANDLIST hCommandlist )
{
    LOG_DLL_ENTRY;
}

////////////////////////////////////////////////////////////////////////////////
HRESULT WINAPI RecycleCreateCommandList(
    D3D10DDI_HDEVICE hDevice,
    const D3D11DDIARG_CREATECOMMANDLIST* pCreatecommandlist,
    D3D11DDI_HCOMMANDLIST hCommandlist,
    D3D11DDI_HRTCOMMANDLIST hRtcommandlist )
{
    LOG_DLL_ENTRY;
    return E_FAIL;
}

////////////////////////////////////////////////////////////////////////////////
HRESULT WINAPI RecycleCreateDeferredContext(
    D3D10DDI_HDEVICE hDevice,
    const D3D11DDIARG_CREATEDEFERREDCONTEXT* pCreatedeferredcontext )
{
    LOG_DLL_ENTRY;
    return E_FAIL;
}

////////////////////////////////////////////////////////////////////////////////
VOID WINAPI RecycleDestroyCommandList(
    D3D10DDI_HDEVICE hDevice,
    D3D11DDI_HCOMMANDLIST hCommandlist )
{
    LOG_DLL_ENTRY;
}

////////////////////////////////////////////////////////////////////////////////
VOID WINAPI Discard(
    D3D10DDI_HDEVICE hDevice,
    D3D11DDI_HANDLETYPE HandleType,
    void* hResourceOrView,
    const D3D10_DDI_RECT* pRect,
    UINT NumRects )
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

////////////////////////////////////////////////////////////////////////////////
VOID WINAPI DynamicConstantBufferMapNoOverwrite(
    D3D10DDI_HDEVICE hDevice,
    D3D10DDI_HRESOURCE hResource,
    UINT arg1,
    D3D10_DDI_MAP map,
    UINT arg2,
    D3D10DDI_MAPPED_SUBRESOURCE* pSubresource )
{
    LOG_DLL_ENTRY;
}

////////////////////////////////////////////////////////////////////////////////
VOID WINAPI CheckDirectFlipSupport(
    D3D10DDI_HDEVICE hDevice,
    D3D10DDI_HRESOURCE hResource1,
    D3D10DDI_HRESOURCE hResource2,
    UINT CheckDirectFlipFlags,
    BOOL* pSupported )
{
    LOG_DLL_ENTRY;
}

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

void FillDdiTable( D3D11_1DDI_DEVICEFUNCS* pTable )
{
    pTable->pfnDefaultConstantBufferUpdateSubresourceUP = DefaultConstantBufferUpdateSubresourceUP;
    pTable->pfnVsSetConstantBuffers = VsSetConstantBuffers;
    pTable->pfnPsSetShaderResources = PsSetShaderResources;
    pTable->pfnPsSetShader = PsSetShader;
    pTable->pfnPsSetSamplers = PsSetSamplers;
    pTable->pfnVsSetShader = VsSetShader;
    pTable->pfnDrawIndexed = DrawIndexed;
    pTable->pfnDraw = Draw;
    pTable->pfnDynamicIABufferMapNoOverwrite = DynamicIABufferMapNoOverwrite;
    pTable->pfnDynamicIABufferUnmap = DynamicIABufferUnmap;
    pTable->pfnDynamicConstantBufferMapDiscard = DynamicConstantBufferMapDiscard;
    pTable->pfnDynamicIABufferMapDiscard = DynamicIABufferMapDiscard;
    pTable->pfnDynamicConstantBufferUnmap = DynamicConstantBufferUnmap;
    pTable->pfnPsSetConstantBuffers = PsSetConstantBuffers;
    pTable->pfnIaSetInputLayout = IaSetInputLayout;
    pTable->pfnIaSetVertexBuffers = IaSetVertexBuffers;
    pTable->pfnIaSetIndexBuffer = IaSetIndexBuffer;
    pTable->pfnDrawIndexedInstanced = DrawIndexedInstanced;
    pTable->pfnDrawInstanced = DrawInstanced;
    pTable->pfnDynamicResourceMapDiscard = DynamicResourceMapDiscard;
    pTable->pfnDynamicResourceUnmap = DynamicResourceUnmap;
    pTable->pfnGsSetConstantBuffers = GsSetConstantBuffers;
    pTable->pfnGsSetShader = GsSetShader;
    pTable->pfnIaSetTopology = IaSetTopology;
    pTable->pfnStagingResourceMap = StagingResourceMap;
    pTable->pfnStagingResourceUnmap = StagingResourceUnmap;
    pTable->pfnVsSetShaderResources = VsSetShaderResources;
    pTable->pfnVsSetSamplers = VsSetSamplers;
    pTable->pfnGsSetShaderResources = GsSetShaderResources;
    pTable->pfnGsSetSamplers = GsSetSamplers;
    pTable->pfnSetRenderTargets = SetRenderTargets;
    pTable->pfnShaderResourceViewReadAfterWriteHazard = ShaderResourceViewReadAfterWriteHazard;
    pTable->pfnResourceReadAfterWriteHazard = ResourceReadAfterWriteHazard;
    pTable->pfnSetBlendState = SetBlendState;
    pTable->pfnSetDepthStencilState = SetDepthStencilState;
    pTable->pfnSetRasterizerState = SetRasterizerState;
    pTable->pfnQueryEnd = QueryEnd;
    pTable->pfnQueryBegin = QueryBegin;
    pTable->pfnResourceCopyRegion = ResourceCopyRegion;
    pTable->pfnResourceUpdateSubresourceUP = ResourceUpdateSubresourceUP;
    pTable->pfnSoSetTargets = SoSetTargets;
    pTable->pfnDrawAuto = DrawAuto;
    pTable->pfnSetViewports = SetViewports;
    pTable->pfnSetScissorRects = SetScissorRects;
    pTable->pfnClearRenderTargetView = ClearRenderTargetView;
    pTable->pfnClearDepthStencilView = ClearDepthStencilView;
    pTable->pfnSetPredication = SetPredication;
    pTable->pfnQueryGetData = QueryGetData;
    pTable->pfnFlush = Flush;
    pTable->pfnGenMips = GenMips;
    pTable->pfnResourceCopy = ResourceCopy;
    pTable->pfnResourceResolveSubresource = ResourceResolveSubresource;
    pTable->pfnResourceMap = ResourceMap;
    pTable->pfnResourceUnmap = ResourceUnmap;
    pTable->pfnResourceIsStagingBusy = ResourceIsStagingBusy;
    pTable->pfnRelocateDeviceFuncs = RelocateDeviceFuncs;
    pTable->pfnCalcPrivateResourceSize = CalcPrivateResourceSize;
    pTable->pfnCalcPrivateOpenedResourceSize = CalcPrivateOpenedResourceSize;
    pTable->pfnCreateResource = CreateResource;
    pTable->pfnOpenResource = OpenResource;
    pTable->pfnDestroyResource = DestroyResource;
    pTable->pfnCalcPrivateShaderResourceViewSize = CalcPrivateShaderResourceViewSize;
    pTable->pfnCreateShaderResourceView = CreateShaderResourceView;
    pTable->pfnDestroyShaderResourceView = DestroyShaderResourceView;
    pTable->pfnCalcPrivateRenderTargetViewSize = CalcPrivateRenderTargetViewSize;
    pTable->pfnCreateRenderTargetView = CreateRenderTargetView;
    pTable->pfnDestroyRenderTargetView = DestroyRenderTargetView;
    pTable->pfnCalcPrivateDepthStencilViewSize = CalcPrivateDepthStencilViewSize;
    pTable->pfnCreateDepthStencilView = CreateDepthStencilView;
    pTable->pfnDestroyDepthStencilView = DestroyDepthStencilView;
    pTable->pfnCalcPrivateElementLayoutSize = CalcPrivateElementLayoutSize;
    pTable->pfnCreateElementLayout = CreateElementLayout;
    pTable->pfnDestroyElementLayout = DestroyElementLayout;
    pTable->pfnCalcPrivateBlendStateSize = CalcPrivateBlendStateSize;
    pTable->pfnCreateBlendState = CreateBlendState;
    pTable->pfnDestroyBlendState = DestroyBlendState;
    pTable->pfnCalcPrivateDepthStencilStateSize = CalcPrivateDepthStencilStateSize;
    pTable->pfnCreateDepthStencilState = CreateDepthStencilState;
    pTable->pfnDestroyDepthStencilState = DestroyDepthStencilState;
    pTable->pfnCalcPrivateRasterizerStateSize = CalcPrivateRasterizerStateSize;
    pTable->pfnCreateRasterizerState = CreateRasterizerState;
    pTable->pfnDestroyRasterizerState = DestroyRasterizerState;
    pTable->pfnCalcPrivateShaderSize = CalcPrivateShaderSize;
    pTable->pfnCreateVertexShader = CreateVertexShader;
    pTable->pfnCreateGeometryShader = CreateGeometryShader;
    pTable->pfnCreatePixelShader = CreatePixelShader;
    pTable->pfnCalcPrivateGeometryShaderWithStreamOutput = CalcPrivateGeometryShaderWithStreamOutput;
    pTable->pfnCreateGeometryShaderWithStreamOutput = CreateGeometryShaderWithStreamOutput;
    pTable->pfnDestroyShader = DestroyShader;
    pTable->pfnCalcPrivateSamplerSize = CalcPrivateSamplerSize;
    pTable->pfnCreateSampler = CreateSampler;
    pTable->pfnDestroySampler = DestroySampler;
    pTable->pfnCalcPrivateQuerySize = CalcPrivateQuerySize;
    pTable->pfnCreateQuery = CreateQuery;
    pTable->pfnDestroyQuery = DestroyQuery;
    pTable->pfnCheckFormatSupport = CheckFormatSupport;
    pTable->pfnCheckMultisampleQualityLevels = CheckMultisampleQualityLevels;
    pTable->pfnCheckCounterInfo = CheckCounterInfo;
    pTable->pfnCheckCounter = CheckCounter;
    pTable->pfnDestroyDevice = DestroyDevice;
    pTable->pfnSetTextFilterSize = SetTextFilterSize;
    pTable->pfnResourceConvert = ResourceConvert;
    pTable->pfnResourceConvertRegion = ResourceConvertRegion;
    pTable->pfnDrawIndexedInstancedIndirect = DrawIndexedInstancedIndirect;
    pTable->pfnDrawInstancedIndirect = DrawInstancedIndirect;
    pTable->pfnCommandListExecute = CommandListExecute;
    pTable->pfnHsSetShaderResources = HsSetShaderResources;
    pTable->pfnHsSetShader = HsSetShader;
    pTable->pfnHsSetSamplers = HsSetSamplers;
    pTable->pfnHsSetConstantBuffers = HsSetConstantBuffers;
    pTable->pfnDsSetShaderResources = DsSetShaderResources;
    pTable->pfnDsSetShader = DsSetShader;
    pTable->pfnDsSetSamplers = DsSetSamplers;
    pTable->pfnDsSetConstantBuffers = DsSetConstantBuffers;
    pTable->pfnCreateHullShader = CreateHullShader;
    pTable->pfnCreateDomainShader = CreateDomainShader;
    pTable->pfnCheckDeferredContextHandleSizes = CheckDeferredContextHandleSizes;
    pTable->pfnCalcDeferredContextHandleSize = CalcDeferredContextHandleSize;
    pTable->pfnCalcPrivateDeferredContextSize = CalcPrivateDeferredContextSize;
    pTable->pfnCreateDeferredContext = CreateDeferredContext;
    pTable->pfnAbandonCommandList = AbandonCommandList;
    pTable->pfnCalcPrivateCommandListSize = CalcPrivateCommandListSize;
    pTable->pfnCreateCommandList = CreateCommandList;
    pTable->pfnDestroyCommandList = DestroyCommandList;
    pTable->pfnCalcPrivateTessellationShaderSize = CalcPrivateTessellationShaderSize;
    pTable->pfnPsSetShaderWithIfaces = PsSetShaderWithIfaces;
    pTable->pfnVsSetShaderWithIfaces = VsSetShaderWithIfaces;
    pTable->pfnGsSetShaderWithIfaces = GsSetShaderWithIfaces;
    pTable->pfnHsSetShaderWithIfaces = HsSetShaderWithIfaces;
    pTable->pfnDsSetShaderWithIfaces = DsSetShaderWithIfaces;
    pTable->pfnCsSetShaderWithIfaces = CsSetShaderWithIfaces;
    pTable->pfnCreateComputeShader = CreateComputeShader;
    pTable->pfnCsSetShader = CsSetShader;
    pTable->pfnCsSetShaderResources = CsSetShaderResources;
    pTable->pfnCsSetSamplers = CsSetSamplers;
    pTable->pfnCsSetConstantBuffers = CsSetConstantBuffers;
    pTable->pfnCalcPrivateUnorderedAccessViewSize = CalcPrivateUnorderedAccessViewSize;
    pTable->pfnCreateUnorderedAccessView = CreateUnorderedAccessView;
    pTable->pfnDestroyUnorderedAccessView = DestroyUnorderedAccessView;
    pTable->pfnClearUnorderedAccessViewUint = ClearUnorderedAccessViewUint;
    pTable->pfnClearUnorderedAccessViewFloat = ClearUnorderedAccessViewFloat;
    pTable->pfnCsSetUnorderedAccessViews = CsSetUnorderedAccessViews;
    pTable->pfnDispatch = Dispatch;
    pTable->pfnDispatchIndirect = DispatchIndirect;
    pTable->pfnSetResourceMinLOD = SetResourceMinLOD;
    pTable->pfnCopyStructureCount = CopyStructureCount;
    pTable->pfnRecycleCommandList = RecycleCommandList;
    pTable->pfnRecycleCreateCommandList = RecycleCreateCommandList;
    pTable->pfnRecycleCreateDeferredContext = RecycleCreateDeferredContext;
    pTable->pfnRecycleDestroyCommandList = RecycleDestroyCommandList;
    pTable->pfnDiscard = Discard;
    pTable->pfnAssignDebugBinary = AssignDebugBinary;
    pTable->pfnDynamicConstantBufferMapNoOverwrite = DynamicConstantBufferMapNoOverwrite;
    pTable->pfnCheckDirectFlipSupport = CheckDirectFlipSupport;
    pTable->pfnClearView = ClearView;
}

} // namespace Autogen
} // namespace Crystal
