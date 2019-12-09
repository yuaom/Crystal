#include "pch.h"
#include "umd_ddi.h"

namespace Crystal
{
namespace UMD
{
namespace DDI
{
    
void FillDdiTable( D3D11_1DDI_DEVICEFUNCS* pTable )
{
    pTable->pfnDefaultConstantBufferUpdateSubresourceUP = DefaultConstantBufferUpdateSubresourceUP;
    pTable->pfnResourceUpdateSubresourceUP = ResourceUpdateSubresourceUP;
    pTable->pfnVsSetConstantBuffers = VsSetConstantBuffers;
    pTable->pfnPsSetConstantBuffers = PsSetConstantBuffers;
    pTable->pfnGsSetConstantBuffers = GsSetConstantBuffers;
    pTable->pfnHsSetConstantBuffers = HsSetConstantBuffers;
    pTable->pfnDsSetConstantBuffers = DsSetConstantBuffers;
    pTable->pfnCsSetConstantBuffers = CsSetConstantBuffers;
    pTable->pfnPsSetShaderResources = PsSetShaderResources;
    pTable->pfnVsSetShaderResources = VsSetShaderResources;
    pTable->pfnGsSetShaderResources = GsSetShaderResources;
    pTable->pfnShaderResourceViewReadAfterWriteHazard = ShaderResourceViewReadAfterWriteHazard;
    pTable->pfnCreateShaderResourceView = CreateShaderResourceView;
    pTable->pfnDestroyShaderResourceView = DestroyShaderResourceView;
    pTable->pfnHsSetShaderResources = HsSetShaderResources;
    pTable->pfnDsSetShaderResources = DsSetShaderResources;
    pTable->pfnCsSetShaderResources = CsSetShaderResources;
    pTable->pfnPsSetShader = PsSetShader;
    pTable->pfnVsSetShader = VsSetShader;
    pTable->pfnGsSetShader = GsSetShader;
    pTable->pfnCreateVertexShader = CreateVertexShader;
    pTable->pfnCreateGeometryShader = CreateGeometryShader;
    pTable->pfnCreatePixelShader = CreatePixelShader;
    pTable->pfnCreateGeometryShaderWithStreamOutput = CreateGeometryShaderWithStreamOutput;
    pTable->pfnDestroyShader = DestroyShader;
    pTable->pfnHsSetShader = HsSetShader;
    pTable->pfnDsSetShader = DsSetShader;
    pTable->pfnCreateHullShader = CreateHullShader;
    pTable->pfnCreateDomainShader = CreateDomainShader;
    pTable->pfnPsSetShaderWithIfaces = PsSetShaderWithIfaces;
    pTable->pfnVsSetShaderWithIfaces = VsSetShaderWithIfaces;
    pTable->pfnGsSetShaderWithIfaces = GsSetShaderWithIfaces;
    pTable->pfnHsSetShaderWithIfaces = HsSetShaderWithIfaces;
    pTable->pfnDsSetShaderWithIfaces = DsSetShaderWithIfaces;
    pTable->pfnCsSetShaderWithIfaces = CsSetShaderWithIfaces;
    pTable->pfnCreateComputeShader = CreateComputeShader;
    pTable->pfnCsSetShader = CsSetShader;
    pTable->pfnAssignDebugBinary = AssignDebugBinary;
    pTable->pfnPsSetSamplers = PsSetSamplers;
    pTable->pfnVsSetSamplers = VsSetSamplers;
    pTable->pfnGsSetSamplers = GsSetSamplers;
    pTable->pfnCreateSampler = CreateSampler;
    pTable->pfnDestroySampler = DestroySampler;
    pTable->pfnHsSetSamplers = HsSetSamplers;
    pTable->pfnDsSetSamplers = DsSetSamplers;
    pTable->pfnCsSetSamplers = CsSetSamplers;
    pTable->pfnDrawIndexed = DrawIndexed;
    pTable->pfnDraw = Draw;
    pTable->pfnDrawIndexedInstanced = DrawIndexedInstanced;
    pTable->pfnDrawInstanced = DrawInstanced;
    pTable->pfnDrawAuto = DrawAuto;
    pTable->pfnDrawIndexedInstancedIndirect = DrawIndexedInstancedIndirect;
    pTable->pfnDrawInstancedIndirect = DrawInstancedIndirect;
    pTable->pfnDynamicIABufferMapNoOverwrite = DynamicIABufferMapNoOverwrite;
    pTable->pfnDynamicConstantBufferMapDiscard = DynamicConstantBufferMapDiscard;
    pTable->pfnDynamicIABufferMapDiscard = DynamicIABufferMapDiscard;
    pTable->pfnDynamicResourceMapDiscard = DynamicResourceMapDiscard;
    pTable->pfnDynamicConstantBufferMapNoOverwrite = DynamicConstantBufferMapNoOverwrite;
    pTable->pfnDynamicIABufferUnmap = DynamicIABufferUnmap;
    pTable->pfnDynamicConstantBufferUnmap = DynamicConstantBufferUnmap;
    pTable->pfnDynamicResourceUnmap = DynamicResourceUnmap;
    pTable->pfnStagingResourceMap = StagingResourceMap;
    pTable->pfnStagingResourceUnmap = StagingResourceUnmap;
    pTable->pfnResourceMap = ResourceMap;
    pTable->pfnResourceUnmap = ResourceUnmap;
    pTable->pfnIaSetInputLayout = IaSetInputLayout;
    pTable->pfnIaSetVertexBuffers = IaSetVertexBuffers;
    pTable->pfnIaSetIndexBuffer = IaSetIndexBuffer;
    pTable->pfnIaSetTopology = IaSetTopology;
    pTable->pfnCreateElementLayout = CreateElementLayout;
    pTable->pfnDestroyElementLayout = DestroyElementLayout;
    pTable->pfnSetRenderTargets = SetRenderTargets;
    pTable->pfnClearRenderTargetView = ClearRenderTargetView;
    pTable->pfnCreateRenderTargetView = CreateRenderTargetView;
    pTable->pfnDestroyRenderTargetView = DestroyRenderTargetView;
    pTable->pfnResourceReadAfterWriteHazard = ResourceReadAfterWriteHazard;
    pTable->pfnFlush = Flush;
    pTable->pfnResourceIsStagingBusy = ResourceIsStagingBusy;
    pTable->pfnRelocateDeviceFuncs = RelocateDeviceFuncs;
    pTable->pfnCheckFormatSupport = CheckFormatSupport;
    pTable->pfnCheckMultisampleQualityLevels = CheckMultisampleQualityLevels;
    pTable->pfnDestroyDevice = DestroyDevice;
    pTable->pfnSetTextFilterSize = SetTextFilterSize;
    pTable->pfnCheckDirectFlipSupport = CheckDirectFlipSupport;
    pTable->pfnSetBlendState = SetBlendState;
    pTable->pfnCreateBlendState = CreateBlendState;
    pTable->pfnDestroyBlendState = DestroyBlendState;
    pTable->pfnSetDepthStencilState = SetDepthStencilState;
    pTable->pfnCreateDepthStencilState = CreateDepthStencilState;
    pTable->pfnDestroyDepthStencilState = DestroyDepthStencilState;
    pTable->pfnSetRasterizerState = SetRasterizerState;
    pTable->pfnCreateRasterizerState = CreateRasterizerState;
    pTable->pfnDestroyRasterizerState = DestroyRasterizerState;
    pTable->pfnQueryEnd = QueryEnd;
    pTable->pfnQueryBegin = QueryBegin;
    pTable->pfnSetPredication = SetPredication;
    pTable->pfnQueryGetData = QueryGetData;
    pTable->pfnCreateQuery = CreateQuery;
    pTable->pfnDestroyQuery = DestroyQuery;
    pTable->pfnResourceCopyRegion = ResourceCopyRegion;
    pTable->pfnResourceCopy = ResourceCopy;
    pTable->pfnCopyStructureCount = CopyStructureCount;
    pTable->pfnSoSetTargets = SoSetTargets;
    pTable->pfnSetViewports = SetViewports;
    pTable->pfnSetScissorRects = SetScissorRects;
    pTable->pfnClearDepthStencilView = ClearDepthStencilView;
    pTable->pfnCreateDepthStencilView = CreateDepthStencilView;
    pTable->pfnDestroyDepthStencilView = DestroyDepthStencilView;
    pTable->pfnGenMips = GenMips;
    pTable->pfnResourceResolveSubresource = ResourceResolveSubresource;
    pTable->pfnCalcPrivateResourceSize = CalcPrivateResourceSize;
    pTable->pfnCalcPrivateOpenedResourceSize = CalcPrivateOpenedResourceSize;
    pTable->pfnCalcPrivateShaderResourceViewSize = CalcPrivateShaderResourceViewSize;
    pTable->pfnCalcPrivateRenderTargetViewSize = CalcPrivateRenderTargetViewSize;
    pTable->pfnCalcPrivateDepthStencilViewSize = CalcPrivateDepthStencilViewSize;
    pTable->pfnCalcPrivateElementLayoutSize = CalcPrivateElementLayoutSize;
    pTable->pfnCalcPrivateBlendStateSize = CalcPrivateBlendStateSize;
    pTable->pfnCalcPrivateDepthStencilStateSize = CalcPrivateDepthStencilStateSize;
    pTable->pfnCalcPrivateRasterizerStateSize = CalcPrivateRasterizerStateSize;
    pTable->pfnCalcPrivateShaderSize = CalcPrivateShaderSize;
    pTable->pfnCalcPrivateGeometryShaderWithStreamOutput = CalcPrivateGeometryShaderWithStreamOutput;
    pTable->pfnCalcPrivateSamplerSize = CalcPrivateSamplerSize;
    pTable->pfnCalcPrivateQuerySize = CalcPrivateQuerySize;
    pTable->pfnCalcPrivateDeferredContextSize = CalcPrivateDeferredContextSize;
    pTable->pfnCalcPrivateCommandListSize = CalcPrivateCommandListSize;
    pTable->pfnCalcPrivateTessellationShaderSize = CalcPrivateTessellationShaderSize;
    pTable->pfnCalcPrivateUnorderedAccessViewSize = CalcPrivateUnorderedAccessViewSize;
    pTable->pfnCreateResource = CreateResource;
    pTable->pfnOpenResource = OpenResource;
    pTable->pfnDestroyResource = DestroyResource;
    pTable->pfnSetResourceMinLOD = SetResourceMinLOD;
    pTable->pfnDiscard = Discard;
    pTable->pfnCheckCounterInfo = CheckCounterInfo;
    pTable->pfnCheckCounter = CheckCounter;
    pTable->pfnResourceConvert = ResourceConvert;
    pTable->pfnResourceConvertRegion = ResourceConvertRegion;
    pTable->pfnCommandListExecute = CommandListExecute;
    pTable->pfnAbandonCommandList = AbandonCommandList;
    pTable->pfnCreateCommandList = CreateCommandList;
    pTable->pfnDestroyCommandList = DestroyCommandList;
    pTable->pfnRecycleCommandList = RecycleCommandList;
    pTable->pfnRecycleCreateCommandList = RecycleCreateCommandList;
    pTable->pfnRecycleDestroyCommandList = RecycleDestroyCommandList;
    pTable->pfnCheckDeferredContextHandleSizes = CheckDeferredContextHandleSizes;
    pTable->pfnCalcDeferredContextHandleSize = CalcDeferredContextHandleSize;
    pTable->pfnCreateDeferredContext = CreateDeferredContext;
    pTable->pfnRecycleCreateDeferredContext = RecycleCreateDeferredContext;
    pTable->pfnCreateUnorderedAccessView = CreateUnorderedAccessView;
    pTable->pfnDestroyUnorderedAccessView = DestroyUnorderedAccessView;
    pTable->pfnClearUnorderedAccessViewUint = ClearUnorderedAccessViewUint;
    pTable->pfnClearUnorderedAccessViewFloat = ClearUnorderedAccessViewFloat;
    pTable->pfnCsSetUnorderedAccessViews = CsSetUnorderedAccessViews;
    pTable->pfnDispatch = Dispatch;
    pTable->pfnDispatchIndirect = DispatchIndirect;
    pTable->pfnClearView = ClearView;
}

} // namespace DDI
} // namespace UMD
} // namespace Crystal
