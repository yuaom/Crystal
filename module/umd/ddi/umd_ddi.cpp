#include "pch.h"

namespace Crystal
{
namespace Autogen
{

////////////////////////////////////////////////////////////////////////////////
VOID WINAPI DefaultConstantBufferUpdateSubresourceUP(
    D3D10DDI_HDEVICE hDevice,
    D3D10DDI_HRESOURCE hDstResource,
    UINT DstSubresource,
    const D3D10_DDI_BOX* pDstBox,
    const void* pSysMemUP,
    UINT RowPitch,
    UINT DepthPitch,
    UINT CopyFlags )
{
    LOG_DLL_ENTRY;
}

////////////////////////////////////////////////////////////////////////////////
VOID WINAPI VsSetConstantBuffers(
    D3D10DDI_HDEVICE hDevice,
    UINT StartSlot,
    UINT NumBuffers,
    const D3D10DDI_HRESOURCE* phBuffers,
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
    const D3D10DDI_HSHADERRESOURCEVIEW* phShaderResourceViews )
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
    UINT Offset,
    UINT NumSamplers,
    const D3D10DDI_HSAMPLER* phSamplers )
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
    UINT StartIndexLocation,
    UINT BaseVertexLocation,
    INT IndexCount )
{
    LOG_DLL_ENTRY;
}

////////////////////////////////////////////////////////////////////////////////
VOID WINAPI Draw(
    D3D10DDI_HDEVICE hDevice,
    UINT VertexCount,
    UINT StartVertexLocation )
{
    LOG_DLL_ENTRY;
}

////////////////////////////////////////////////////////////////////////////////
VOID WINAPI DynamicIABufferMapNoOverwrite(
    D3D10DDI_HDEVICE hDevice,
    D3D10DDI_HRESOURCE hResource,
    UINT Subresource,
    D3D10_DDI_MAP DDIMap,
    UINT Flags,
    D3D10DDI_MAPPED_SUBRESOURCE* pMappedSubResource )
{
    LOG_DLL_ENTRY;
}

////////////////////////////////////////////////////////////////////////////////
VOID WINAPI DynamicIABufferUnmap(
    D3D10DDI_HDEVICE hDevice,
    D3D10DDI_HRESOURCE hResource,
    UINT Subresource )
{
    LOG_DLL_ENTRY;
}

////////////////////////////////////////////////////////////////////////////////
VOID WINAPI DynamicConstantBufferMapDiscard(
    D3D10DDI_HDEVICE hDevice,
    D3D10DDI_HRESOURCE hResource,
    UINT Subresource,
    D3D10_DDI_MAP DDIMap,
    UINT Flags,
    D3D10DDI_MAPPED_SUBRESOURCE* pMappedSubResource )
{
    LOG_DLL_ENTRY;
}

////////////////////////////////////////////////////////////////////////////////
VOID WINAPI DynamicIABufferMapDiscard(
    D3D10DDI_HDEVICE hDevice,
    D3D10DDI_HRESOURCE hResource,
    UINT Subresource,
    D3D10_DDI_MAP DDIMap,
    UINT Flags,
    D3D10DDI_MAPPED_SUBRESOURCE* pMappedSubResource )
{
    LOG_DLL_ENTRY;
}

////////////////////////////////////////////////////////////////////////////////
VOID WINAPI DynamicConstantBufferUnmap(
    D3D10DDI_HDEVICE hDevice,
    D3D10DDI_HRESOURCE hResource,
    UINT Subresource )
{
    LOG_DLL_ENTRY;
}

////////////////////////////////////////////////////////////////////////////////
VOID WINAPI PsSetConstantBuffers(
    D3D10DDI_HDEVICE hDevice,
    UINT StartSlot,
    UINT NumBuffers,
    const D3D10DDI_HRESOURCE* phBuffers,
    const UINT* pFirstConstant,
    const UINT* pNumConstants )
{
    LOG_DLL_ENTRY;
}

////////////////////////////////////////////////////////////////////////////////
VOID WINAPI IaSetInputLayout(
    D3D10DDI_HDEVICE hDevice,
    D3D10DDI_HELEMENTLAYOUT hInputLayout )
{
    LOG_DLL_ENTRY;
}

////////////////////////////////////////////////////////////////////////////////
VOID WINAPI IaSetVertexBuffers(
    D3D10DDI_HDEVICE hDevice,
    UINT StartSlot,
    UINT NumBuffers,
    const D3D10DDI_HRESOURCE* phBuffers,
    const UINT* pStrides,
    const UINT* pOffsets )
{
    LOG_DLL_ENTRY;
}

////////////////////////////////////////////////////////////////////////////////
VOID WINAPI IaSetIndexBuffer(
    D3D10DDI_HDEVICE hDevice,
    D3D10DDI_HRESOURCE hBuffer,
    DXGI_FORMAT Format,
    UINT Offset )
{
    LOG_DLL_ENTRY;
}

////////////////////////////////////////////////////////////////////////////////
VOID WINAPI DrawIndexedInstanced(
    D3D10DDI_HDEVICE hDevice,
    UINT IndexCountPerInstance,
    UINT InstanceCount,
    UINT StartIndexLocation,
    INT BaseVertexLocation,
    UINT StartInstanceLocation )
{
    LOG_DLL_ENTRY;
}

////////////////////////////////////////////////////////////////////////////////
VOID WINAPI DrawInstanced(
    D3D10DDI_HDEVICE hDevice,
    UINT VertexCountPerInstance,
    UINT InstanceCount,
    UINT StartVertexLocation,
    UINT StartInstanceLocation )
{
    LOG_DLL_ENTRY;
}

////////////////////////////////////////////////////////////////////////////////
VOID WINAPI DynamicResourceMapDiscard(
    D3D10DDI_HDEVICE hDevice,
    D3D10DDI_HRESOURCE hResource,
    UINT Subresource,
    D3D10_DDI_MAP DDIMap,
    UINT Flags,
    D3D10DDI_MAPPED_SUBRESOURCE* pMappedSubResource )
{
    LOG_DLL_ENTRY;
}

////////////////////////////////////////////////////////////////////////////////
VOID WINAPI DynamicResourceUnmap(
    D3D10DDI_HDEVICE hDevice,
    D3D10DDI_HRESOURCE hResource,
    UINT Subresource )
{
    LOG_DLL_ENTRY;
}

////////////////////////////////////////////////////////////////////////////////
VOID WINAPI GsSetConstantBuffers(
    D3D10DDI_HDEVICE hDevice,
    UINT StartSlot,
    UINT NumBuffers,
    const D3D10DDI_HRESOURCE* phBuffers,
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
    D3D10_DDI_PRIMITIVE_TOPOLOGY PrimitiveTopology )
{
    LOG_DLL_ENTRY;
}

////////////////////////////////////////////////////////////////////////////////
VOID WINAPI StagingResourceMap(
    D3D10DDI_HDEVICE hDevice,
    D3D10DDI_HRESOURCE hResource,
    UINT Subresource,
    D3D10_DDI_MAP DDIMap,
    UINT Flags,
    D3D10DDI_MAPPED_SUBRESOURCE* pMappedSubResource )
{
    LOG_DLL_ENTRY;
}

////////////////////////////////////////////////////////////////////////////////
VOID WINAPI StagingResourceUnmap(
    D3D10DDI_HDEVICE hDevice,
    D3D10DDI_HRESOURCE hResource,
    UINT Subresource )
{
    LOG_DLL_ENTRY;
}

////////////////////////////////////////////////////////////////////////////////
VOID WINAPI VsSetShaderResources(
    D3D10DDI_HDEVICE hDevice,
    UINT StartSlot,
    UINT NumViews,
    const D3D10DDI_HSHADERRESOURCEVIEW* phShaderResourceViews )
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
VOID WINAPI GsSetShaderResources(
    D3D10DDI_HDEVICE hDevice,
    UINT StartSlot,
    UINT NumViews,
    const D3D10DDI_HSHADERRESOURCEVIEW* phShaderResourceViews )
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
VOID WINAPI SetRenderTargets(
    D3D10DDI_HDEVICE hDevice,
    const D3D10DDI_HRENDERTARGETVIEW* phRenderTargetView,
    UINT NumRTVs,
    UINT RTVNumbertoUnbind,
    D3D10DDI_HDEPTHSTENCILVIEW hDepthStencilView,
    const D3D11DDI_HUNORDEREDACCESSVIEW* phUnorderedAccessView,
    const UINT* pUAVInitialCounts,
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
    D3D10DDI_HSHADERRESOURCEVIEW hResource,
    D3D10DDI_HRESOURCE hShaderResourceView )
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
    D3D10DDI_HBLENDSTATE hState,
    const FLOAT pBlendFactor[4],
    UINT SampleMask )
{
    LOG_DLL_ENTRY;
}

////////////////////////////////////////////////////////////////////////////////
VOID WINAPI SetDepthStencilState(
    D3D10DDI_HDEVICE hDevice,
    D3D10DDI_HDEPTHSTENCILSTATE hState,
    UINT StencilRef )
{
    LOG_DLL_ENTRY;
}

////////////////////////////////////////////////////////////////////////////////
VOID WINAPI SetRasterizerState(
    D3D10DDI_HDEVICE hDevice,
    D3D10DDI_HRASTERIZERSTATE hRasterizerState )
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
    D3D10DDI_HRESOURCE hDstResource,
    UINT DstSubresource,
    UINT DstX,
    UINT DstY,
    UINT DstZ,
    D3D10DDI_HRESOURCE hSrcResource,
    UINT SrcSubresource,
    const D3D10_DDI_BOX* pSrcBox,
    UINT CopyFlags )
{
    LOG_DLL_ENTRY;
}

////////////////////////////////////////////////////////////////////////////////
VOID WINAPI ResourceUpdateSubresourceUP(
    D3D10DDI_HDEVICE hDevice,
    D3D10DDI_HRESOURCE hDstResource,
    UINT DstSubresource,
    const D3D10_DDI_BOX* pDstBox,
    const void* pSysMemUP,
    UINT RowPitch,
    UINT DepthPitch,
    UINT CopyFlags )
{
    LOG_DLL_ENTRY;
}

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
    const D3D10_DDI_VIEWPORT* pViewports )
{
    LOG_DLL_ENTRY;
}

////////////////////////////////////////////////////////////////////////////////
VOID WINAPI SetScissorRects(
    D3D10DDI_HDEVICE hDevice,
    UINT NumRects,
    UINT ClearRects,
    const D3D10_DDI_RECT* pRects )
{
    LOG_DLL_ENTRY;
}

////////////////////////////////////////////////////////////////////////////////
VOID WINAPI ClearRenderTargetView(
    D3D10DDI_HDEVICE hDevice,
    D3D10DDI_HRENDERTARGETVIEW pColorRGBA,
    FLOAT hRenderTargetView[4] )
{
    LOG_DLL_ENTRY;
}

////////////////////////////////////////////////////////////////////////////////
VOID WINAPI ClearDepthStencilView(
    D3D10DDI_HDEVICE hDevice,
    D3D10DDI_HDEPTHSTENCILVIEW hDepthStencilView,
    UINT Stencil,
    FLOAT Depth,
    UINT8 Flags )
{
    LOG_DLL_ENTRY;
}

////////////////////////////////////////////////////////////////////////////////
VOID WINAPI SetPredication(
    D3D10DDI_HDEVICE hDevice,
    D3D10DDI_HQUERY hQuery,
    BOOL PredicateValue )
{
    LOG_DLL_ENTRY;
}

////////////////////////////////////////////////////////////////////////////////
VOID WINAPI QueryGetData(
    D3D10DDI_HDEVICE hDevice,
    D3D10DDI_HQUERY hQuery,
    void* pData,
    UINT DataSize,
    UINT Flags )
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
    D3D10DDI_HSHADERRESOURCEVIEW hShaderResourceView )
{
    LOG_DLL_ENTRY;
}

////////////////////////////////////////////////////////////////////////////////
VOID WINAPI ResourceCopy(
    D3D10DDI_HDEVICE hDevice,
    D3D10DDI_HRESOURCE hDstResource,
    D3D10DDI_HRESOURCE hSrcResource )
{
    LOG_DLL_ENTRY;
}

////////////////////////////////////////////////////////////////////////////////
VOID WINAPI ResourceResolveSubresource(
    D3D10DDI_HDEVICE hDevice,
    D3D10DDI_HRESOURCE hDstResource,
    UINT DstSubresource,
    D3D10DDI_HRESOURCE hSrcResource,
    UINT SrcSubresource,
    DXGI_FORMAT ResolveFormat )
{
    LOG_DLL_ENTRY;
}

////////////////////////////////////////////////////////////////////////////////
VOID WINAPI ResourceMap(
    D3D10DDI_HDEVICE hDevice,
    D3D10DDI_HRESOURCE hResource,
    UINT Subresource,
    D3D10_DDI_MAP DDIMap,
    UINT Flags,
    D3D10DDI_MAPPED_SUBRESOURCE* pMappedSubResource )
{
    LOG_DLL_ENTRY;
}

////////////////////////////////////////////////////////////////////////////////
VOID WINAPI ResourceUnmap(
    D3D10DDI_HDEVICE hDevice,
    D3D10DDI_HRESOURCE hResource,
    UINT Subresource )
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
    struct D3D11_1DDI_DEVICEFUNCS* pDeviceFunctions )
{
    LOG_DLL_ENTRY;
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
SIZE_T WINAPI CalcPrivateOpenedResourceSize(
    D3D10DDI_HDEVICE hDevice,
    const D3D10DDIARG_OPENRESOURCE* pOpenResource )
{
    LOG_DLL_ENTRY;
    return 0;
}

////////////////////////////////////////////////////////////////////////////////
VOID WINAPI CreateResource(
    D3D10DDI_HDEVICE hDevice,
    const D3D11DDIARG_CREATERESOURCE* pCreateResource,
    D3D10DDI_HRESOURCE hResource,
    D3D10DDI_HRTRESOURCE hRTResource )
{
    LOG_DLL_ENTRY;
}

////////////////////////////////////////////////////////////////////////////////
VOID WINAPI OpenResource(
    D3D10DDI_HDEVICE hDevice,
    const D3D10DDIARG_OPENRESOURCE* pOpenResource,
    D3D10DDI_HRESOURCE hResource,
    D3D10DDI_HRTRESOURCE hRTResource )
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
    const D3D11DDIARG_CREATESHADERRESOURCEVIEW* pCreateShaderResourceView )
{
    LOG_DLL_ENTRY;
    return 0;
}

////////////////////////////////////////////////////////////////////////////////
VOID WINAPI CreateShaderResourceView(
    D3D10DDI_HDEVICE hDevice,
    const D3D11DDIARG_CREATESHADERRESOURCEVIEW* pCreateShaderResourceView,
    D3D10DDI_HSHADERRESOURCEVIEW hShaderResourceView,
    D3D10DDI_HRTSHADERRESOURCEVIEW hRTShaderResourceView )
{
    LOG_DLL_ENTRY;
}

////////////////////////////////////////////////////////////////////////////////
VOID WINAPI DestroyShaderResourceView(
    D3D10DDI_HDEVICE hDevice,
    D3D10DDI_HSHADERRESOURCEVIEW hShaderResourceView )
{
    LOG_DLL_ENTRY;
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
VOID WINAPI CreateRenderTargetView(
    D3D10DDI_HDEVICE hDevice,
    const D3D10DDIARG_CREATERENDERTARGETVIEW* pCreateRenderTargetView,
    D3D10DDI_HRENDERTARGETVIEW hRenderTargetView,
    D3D10DDI_HRTRENDERTARGETVIEW hRTRenderTargetView )
{
    LOG_DLL_ENTRY;
}

////////////////////////////////////////////////////////////////////////////////
VOID WINAPI DestroyRenderTargetView(
    D3D10DDI_HDEVICE hDevice,
    D3D10DDI_HRENDERTARGETVIEW hRenderTargetView )
{
    LOG_DLL_ENTRY;
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
VOID WINAPI CreateDepthStencilView(
    D3D10DDI_HDEVICE hDevice,
    const D3D11DDIARG_CREATEDEPTHSTENCILVIEW* pCreateDepthStencilView,
    D3D10DDI_HDEPTHSTENCILVIEW hDepthStencilView,
    D3D10DDI_HRTDEPTHSTENCILVIEW hRTDepthStencilView )
{
    LOG_DLL_ENTRY;
}

////////////////////////////////////////////////////////////////////////////////
VOID WINAPI DestroyDepthStencilView(
    D3D10DDI_HDEVICE hDevice,
    D3D10DDI_HDEPTHSTENCILVIEW hDepthStencilView )
{
    LOG_DLL_ENTRY;
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
VOID WINAPI CreateElementLayout(
    D3D10DDI_HDEVICE hDevice,
    const D3D10DDIARG_CREATEELEMENTLAYOUT* pCreateElementLayout,
    D3D10DDI_HELEMENTLAYOUT hElementLayout,
    D3D10DDI_HRTELEMENTLAYOUT hRTElementLayout )
{
    LOG_DLL_ENTRY;
}

////////////////////////////////////////////////////////////////////////////////
VOID WINAPI DestroyElementLayout(
    D3D10DDI_HDEVICE hDevice,
    D3D10DDI_HELEMENTLAYOUT hElementLayout )
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
    D3D10DDI_HDEPTHSTENCILSTATE hDepthStencilState,
    D3D10DDI_HRTDEPTHSTENCILSTATE hRTDepthStencilState )
{
    LOG_DLL_ENTRY;
}

////////////////////////////////////////////////////////////////////////////////
VOID WINAPI DestroyDepthStencilState(
    D3D10DDI_HDEVICE hDevice,
    D3D10DDI_HDEPTHSTENCILSTATE hDepthStencilState )
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
    D3D10DDI_HRASTERIZERSTATE hRasterizerState,
    D3D10DDI_HRTRASTERIZERSTATE hRTRasterizerState )
{
    LOG_DLL_ENTRY;
}

////////////////////////////////////////////////////////////////////////////////
VOID WINAPI DestroyRasterizerState(
    D3D10DDI_HDEVICE hDevice,
    D3D10DDI_HRASTERIZERSTATE hRasterizerState )
{
    LOG_DLL_ENTRY;
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
SIZE_T WINAPI CalcPrivateGeometryShaderWithStreamOutput(
    D3D10DDI_HDEVICE hDevice,
    const D3D11DDIARG_CREATEGEOMETRYSHADERWITHSTREAMOUTPUT* pOutput,
    const D3D11_1DDIARG_STAGE_IO_SIGNATURES* pSignatures )
{
    LOG_DLL_ENTRY;
    return 0;
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
SIZE_T WINAPI CalcPrivateQuerySize(
    D3D10DDI_HDEVICE hDevice,
    const D3D10DDIARG_CREATEQUERY* pCreateQuery )
{
    LOG_DLL_ENTRY;
    return 0;
}

////////////////////////////////////////////////////////////////////////////////
VOID WINAPI CreateQuery(
    D3D10DDI_HDEVICE hDevice,
    const D3D10DDIARG_CREATEQUERY* pCreateQuery,
    D3D10DDI_HQUERY hQuery,
    D3D10DDI_HRTQUERY hRTQuery )
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
    DXGI_FORMAT Format,
    UINT* pFormatCaps )
{
    LOG_DLL_ENTRY;
}

////////////////////////////////////////////////////////////////////////////////
VOID WINAPI CheckMultisampleQualityLevels(
    D3D10DDI_HDEVICE hDevice,
    DXGI_FORMAT Format,
    UINT SampleCount,
    UINT* pNumQualityLevels )
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
    D3D10DDI_QUERY Query,
    D3D10DDI_COUNTER_TYPE* pCounterType,
    UINT* pDescription,
    LPSTR pActiveCounters,
    UINT* pNameLength,
    LPSTR pName,
    UINT* pUnitsLength,
    LPSTR pUnits,
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
    UINT Width,
    UINT Height )
{
    LOG_DLL_ENTRY;
}

////////////////////////////////////////////////////////////////////////////////
VOID WINAPI ResourceConvert(
    D3D10DDI_HDEVICE hDevice,
    D3D10DDI_HRESOURCE hDstResource,
    D3D10DDI_HRESOURCE hSrcResource )
{
    LOG_DLL_ENTRY;
}

////////////////////////////////////////////////////////////////////////////////
VOID WINAPI ResourceConvertRegion(
    D3D10DDI_HDEVICE hDevice,
    D3D10DDI_HRESOURCE hDstResource,
    UINT DstSubresource,
    UINT DstX,
    UINT DstY,
    UINT DstZ,
    D3D10DDI_HRESOURCE hSrcResource,
    UINT SrcSubresource,
    const D3D10_DDI_BOX* pSrcBox,
    UINT CopyFlags )
{
    LOG_DLL_ENTRY;
}

////////////////////////////////////////////////////////////////////////////////
VOID WINAPI DrawIndexedInstancedIndirect(
    D3D10DDI_HDEVICE hDevice,
    D3D10DDI_HRESOURCE hBufferForArgs,
    UINT AlignedByteOffsetForArgs )
{
    LOG_DLL_ENTRY;
}

////////////////////////////////////////////////////////////////////////////////
VOID WINAPI DrawInstancedIndirect(
    D3D10DDI_HDEVICE hDevice,
    D3D10DDI_HRESOURCE hBufferForArgs,
    UINT AlignedByteOffsetForArgs )
{
    LOG_DLL_ENTRY;
}

////////////////////////////////////////////////////////////////////////////////
VOID WINAPI CommandListExecute(
    D3D10DDI_HDEVICE hDevice,
    D3D11DDI_HCOMMANDLIST hCommandList )
{
    LOG_DLL_ENTRY;
}

////////////////////////////////////////////////////////////////////////////////
VOID WINAPI HsSetShaderResources(
    D3D10DDI_HDEVICE hDevice,
    UINT StartSlot,
    UINT NumViews,
    const D3D10DDI_HSHADERRESOURCEVIEW* phShaderResourceViews )
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
    UINT Offset,
    UINT NumSamplers,
    const D3D10DDI_HSAMPLER* phSamplers )
{
    LOG_DLL_ENTRY;
}

////////////////////////////////////////////////////////////////////////////////
VOID WINAPI HsSetConstantBuffers(
    D3D10DDI_HDEVICE hDevice,
    UINT StartSlot,
    UINT NumBuffers,
    const D3D10DDI_HRESOURCE* phBuffers,
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
    const D3D10DDI_HSHADERRESOURCEVIEW* phShaderResourceViews )
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
    UINT Offset,
    UINT NumSamplers,
    const D3D10DDI_HSAMPLER* phSamplers )
{
    LOG_DLL_ENTRY;
}

////////////////////////////////////////////////////////////////////////////////
VOID WINAPI DsSetConstantBuffers(
    D3D10DDI_HDEVICE hDevice,
    UINT StartSlot,
    UINT NumBuffers,
    const D3D10DDI_HRESOURCE* phBuffers,
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
VOID WINAPI CheckDeferredContextHandleSizes(
    D3D10DDI_HDEVICE hDevice,
    UINT* pHSizes,
    D3D11DDI_HANDLESIZE* pHandleSize )
{
    LOG_DLL_ENTRY;
}

////////////////////////////////////////////////////////////////////////////////
SIZE_T WINAPI CalcDeferredContextHandleSize(
    D3D10DDI_HDEVICE hDevice,
    D3D11DDI_HANDLETYPE HandleType,
    void* pICObject )
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
VOID WINAPI CreateDeferredContext(
    D3D10DDI_HDEVICE hDevice,
    const D3D11DDIARG_CREATEDEFERREDCONTEXT* pCreateDeferredContext )
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
    const D3D11DDIARG_CREATECOMMANDLIST* pCreateCommandList )
{
    LOG_DLL_ENTRY;
    return 0;
}

////////////////////////////////////////////////////////////////////////////////
VOID WINAPI CreateCommandList(
    D3D10DDI_HDEVICE hDevice,
    const D3D11DDIARG_CREATECOMMANDLIST* pCreateCommandList,
    D3D11DDI_HCOMMANDLIST hCommandList,
    D3D11DDI_HRTCOMMANDLIST hRTCommandList )
{
    LOG_DLL_ENTRY;
}

////////////////////////////////////////////////////////////////////////////////
VOID WINAPI DestroyCommandList(
    D3D10DDI_HDEVICE hDevice,
    D3D11DDI_HCOMMANDLIST hCommandList )
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
    const UINT* pPointerData,
    const D3D11DDIARG_POINTERDATA* pIfaces )
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
VOID WINAPI CreateComputeShader(
    D3D10DDI_HDEVICE hDevice,
    const UINT* pShaderCode,
    D3D10DDI_HSHADER hShader,
    D3D10DDI_HRTSHADER hRTShader )
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
    const D3D10DDI_HSHADERRESOURCEVIEW* phShaderResourceViews )
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

////////////////////////////////////////////////////////////////////////////////
VOID WINAPI CsSetConstantBuffers(
    D3D10DDI_HDEVICE hDevice,
    UINT StartSlot,
    UINT NumBuffers,
    const D3D10DDI_HRESOURCE* phBuffers,
    const UINT* pFirstConstant,
    const UINT* pNumConstants )
{
    LOG_DLL_ENTRY;
}

////////////////////////////////////////////////////////////////////////////////
SIZE_T WINAPI CalcPrivateUnorderedAccessViewSize(
    D3D10DDI_HDEVICE hDevice,
    const D3D11DDIARG_CREATEUNORDEREDACCESSVIEW* pCreateUnorderedAccessView )
{
    LOG_DLL_ENTRY;
    return 0;
}

////////////////////////////////////////////////////////////////////////////////
VOID WINAPI CreateUnorderedAccessView(
    D3D10DDI_HDEVICE hDevice,
    const D3D11DDIARG_CREATEUNORDEREDACCESSVIEW* pCreateUnorderedAccessView,
    D3D11DDI_HUNORDEREDACCESSVIEW hUnorderedAccessView,
    D3D11DDI_HRTUNORDEREDACCESSVIEW hRTUnorderedAccessView )
{
    LOG_DLL_ENTRY;
}

////////////////////////////////////////////////////////////////////////////////
VOID WINAPI DestroyUnorderedAccessView(
    D3D10DDI_HDEVICE hDevice,
    D3D11DDI_HUNORDEREDACCESSVIEW hUnorderedAccessView )
{
    LOG_DLL_ENTRY;
}

////////////////////////////////////////////////////////////////////////////////
VOID WINAPI ClearUnorderedAccessViewUint(
    D3D10DDI_HDEVICE hDevice,
    D3D11DDI_HUNORDEREDACCESSVIEW hUnorderedAccessView,
    const UINT UINT[4] )
{
    LOG_DLL_ENTRY;
}

////////////////////////////////////////////////////////////////////////////////
VOID WINAPI ClearUnorderedAccessViewFloat(
    D3D10DDI_HDEVICE hDevice,
    D3D11DDI_HUNORDEREDACCESSVIEW hUnorderedAccessView,
    const FLOAT FLOAT[4] )
{
    LOG_DLL_ENTRY;
}

////////////////////////////////////////////////////////////////////////////////
VOID WINAPI CsSetUnorderedAccessViews(
    D3D10DDI_HDEVICE hDevice,
    UINT StartSlot,
    UINT NumViews,
    const D3D11DDI_HUNORDEREDACCESSVIEW* pUAVInitialCounts,
    const UINT* phUnorderedAccessView )
{
    LOG_DLL_ENTRY;
}

////////////////////////////////////////////////////////////////////////////////
VOID WINAPI Dispatch(
    D3D10DDI_HDEVICE hDevice,
    UINT ThreadGroupCountX,
    UINT ThreadGroupCountY,
    UINT ThreadGroupCountZ )
{
    LOG_DLL_ENTRY;
}

////////////////////////////////////////////////////////////////////////////////
VOID WINAPI DispatchIndirect(
    D3D10DDI_HDEVICE hDevice,
    D3D10DDI_HRESOURCE hBufferForArgs,
    UINT AlignedByteOffsetForArgs )
{
    LOG_DLL_ENTRY;
}

////////////////////////////////////////////////////////////////////////////////
VOID WINAPI SetResourceMinLOD(
    D3D10DDI_HDEVICE hDevice,
    D3D10DDI_HRESOURCE hResource,
    FLOAT MinLOD )
{
    LOG_DLL_ENTRY;
}

////////////////////////////////////////////////////////////////////////////////
VOID WINAPI CopyStructureCount(
    D3D10DDI_HDEVICE hDevice,
    D3D10DDI_HRESOURCE hDstBuffer,
    UINT DstAlignedByteOffset,
    D3D11DDI_HUNORDEREDACCESSVIEW hSrcView )
{
    LOG_DLL_ENTRY;
}

////////////////////////////////////////////////////////////////////////////////
VOID WINAPI RecycleCommandList(
    D3D10DDI_HDEVICE hDevice,
    D3D11DDI_HCOMMANDLIST hCommandList )
{
    LOG_DLL_ENTRY;
}

////////////////////////////////////////////////////////////////////////////////
HRESULT WINAPI RecycleCreateCommandList(
    D3D10DDI_HDEVICE hDevice,
    const D3D11DDIARG_CREATECOMMANDLIST* pCreateCommandList,
    D3D11DDI_HCOMMANDLIST hCommandList,
    D3D11DDI_HRTCOMMANDLIST hRTCommandList )
{
    LOG_DLL_ENTRY;
    return E_FAIL;
}

////////////////////////////////////////////////////////////////////////////////
HRESULT WINAPI RecycleCreateDeferredContext(
    D3D10DDI_HDEVICE hDevice,
    const D3D11DDIARG_CREATEDEFERREDCONTEXT* pCreateDeferredContext )
{
    LOG_DLL_ENTRY;
    return E_FAIL;
}

////////////////////////////////////////////////////////////////////////////////
VOID WINAPI RecycleDestroyCommandList(
    D3D10DDI_HDEVICE hDevice,
    D3D11DDI_HCOMMANDLIST hCommandList )
{
    LOG_DLL_ENTRY;
}

////////////////////////////////////////////////////////////////////////////////
VOID WINAPI Discard(
    D3D10DDI_HDEVICE hDevice,
    D3D11DDI_HANDLETYPE HandleType,
    void* hResourceOrView,
    const D3D10_DDI_RECT* pRects,
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
    UINT Subresource,
    D3D10_DDI_MAP DDIMap,
    UINT Flags,
    D3D10DDI_MAPPED_SUBRESOURCE* pMappedSubResource )
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
