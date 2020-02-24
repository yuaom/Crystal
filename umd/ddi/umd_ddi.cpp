#include "pch.h"
#include "umd_ddi.h"

namespace Crystal
{
namespace UMD
{
namespace DDI
{
    
void FillDdiTable( D3DWDDM1_3DDI_DEVICEFUNCS* pTable )
{
    pTable->pfnDefaultConstantBufferUpdateSubresourceUP = DefaultConstantBufferUpdateSubresourceUP;
    pTable->pfnResourceUpdateSubresourceUP = ResourceUpdateSubresourceUP;
    pTable->pfnUpdateTileMappings = UpdateTileMappings;
    pTable->pfnUpdateTiles = UpdateTiles;
    pTable->pfnVsSetConstantBuffers = VsSetConstantBuffers;
    pTable->pfnHsSetConstantBuffers = HsSetConstantBuffers;
    pTable->pfnDsSetConstantBuffers = DsSetConstantBuffers;
    pTable->pfnGsSetConstantBuffers = GsSetConstantBuffers;
    pTable->pfnPsSetConstantBuffers = PsSetConstantBuffers;
    pTable->pfnCsSetConstantBuffers = CsSetConstantBuffers;
    pTable->pfnCreateShaderResourceView = CreateShaderResourceView;
    pTable->pfnDestroyShaderResourceView = DestroyShaderResourceView;
    pTable->pfnVsSetShaderResources = VsSetShaderResources;
    pTable->pfnHsSetShaderResources = HsSetShaderResources;
    pTable->pfnDsSetShaderResources = DsSetShaderResources;
    pTable->pfnGsSetShaderResources = GsSetShaderResources;
    pTable->pfnPsSetShaderResources = PsSetShaderResources;
    pTable->pfnCsSetShaderResources = CsSetShaderResources;
    pTable->pfnShaderResourceViewReadAfterWriteHazard = ShaderResourceViewReadAfterWriteHazard;
    pTable->pfnCreateVertexShader = CreateVertexShader;
    pTable->pfnCreateHullShader = CreateHullShader;
    pTable->pfnCreateDomainShader = CreateDomainShader;
    pTable->pfnCreateGeometryShader = CreateGeometryShader;
    pTable->pfnCreateGeometryShaderWithStreamOutput = CreateGeometryShaderWithStreamOutput;
    pTable->pfnCreatePixelShader = CreatePixelShader;
    pTable->pfnCreateComputeShader = CreateComputeShader;
    pTable->pfnDestroyShader = DestroyShader;
    pTable->pfnVsSetShader = VsSetShader;
    pTable->pfnVsSetShaderWithIfaces = VsSetShaderWithIfaces;
    pTable->pfnHsSetShader = HsSetShader;
    pTable->pfnHsSetShaderWithIfaces = HsSetShaderWithIfaces;
    pTable->pfnDsSetShader = DsSetShader;
    pTable->pfnDsSetShaderWithIfaces = DsSetShaderWithIfaces;
    pTable->pfnGsSetShader = GsSetShader;
    pTable->pfnGsSetShaderWithIfaces = GsSetShaderWithIfaces;
    pTable->pfnPsSetShader = PsSetShader;
    pTable->pfnPsSetShaderWithIfaces = PsSetShaderWithIfaces;
    pTable->pfnCsSetShader = CsSetShader;
    pTable->pfnCsSetShaderWithIfaces = CsSetShaderWithIfaces;
    pTable->pfnAssignDebugBinary = AssignDebugBinary;
    pTable->pfnCreateSampler = CreateSampler;
    pTable->pfnDestroySampler = DestroySampler;
    pTable->pfnVsSetSamplers = VsSetSamplers;
    pTable->pfnHsSetSamplers = HsSetSamplers;
    pTable->pfnDsSetSamplers = DsSetSamplers;
    pTable->pfnGsSetSamplers = GsSetSamplers;
    pTable->pfnPsSetSamplers = PsSetSamplers;
    pTable->pfnCsSetSamplers = CsSetSamplers;
    pTable->pfnDraw = Draw;
    pTable->pfnDrawAuto = DrawAuto;
    pTable->pfnDrawIndexed = DrawIndexed;
    pTable->pfnDrawIndexedInstanced = DrawIndexedInstanced;
    pTable->pfnDrawIndexedInstancedIndirect = DrawIndexedInstancedIndirect;
    pTable->pfnDrawInstanced = DrawInstanced;
    pTable->pfnDrawInstancedIndirect = DrawInstancedIndirect;
    pTable->pfnDynamicConstantBufferMapDiscard = DynamicConstantBufferMapDiscard;
    pTable->pfnDynamicConstantBufferMapNoOverwrite = DynamicConstantBufferMapNoOverwrite;
    pTable->pfnDynamicIABufferMapDiscard = DynamicIABufferMapDiscard;
    pTable->pfnDynamicIABufferMapNoOverwrite = DynamicIABufferMapNoOverwrite;
    pTable->pfnDynamicResourceMapDiscard = DynamicResourceMapDiscard;
    pTable->pfnDynamicConstantBufferUnmap = DynamicConstantBufferUnmap;
    pTable->pfnDynamicIABufferUnmap = DynamicIABufferUnmap;
    pTable->pfnDynamicResourceUnmap = DynamicResourceUnmap;
    pTable->pfnResourceMap = ResourceMap;
    pTable->pfnResourceUnmap = ResourceUnmap;
    pTable->pfnStagingResourceMap = StagingResourceMap;
    pTable->pfnStagingResourceUnmap = StagingResourceUnmap;
    pTable->pfnCreateElementLayout = CreateElementLayout;
    pTable->pfnDestroyElementLayout = DestroyElementLayout;
    pTable->pfnIaSetIndexBuffer = IaSetIndexBuffer;
    pTable->pfnIaSetInputLayout = IaSetInputLayout;
    pTable->pfnIaSetTopology = IaSetTopology;
    pTable->pfnIaSetVertexBuffers = IaSetVertexBuffers;
    pTable->pfnCreateRenderTargetView = CreateRenderTargetView;
    pTable->pfnDestroyRenderTargetView = DestroyRenderTargetView;
    pTable->pfnSetRenderTargets = SetRenderTargets;
    pTable->pfnDestroyDevice = DestroyDevice;
    pTable->pfnCheckDirectFlipSupport = CheckDirectFlipSupport;
    pTable->pfnCheckFormatSupport = CheckFormatSupport;
    pTable->pfnCheckMultisampleQualityLevels = CheckMultisampleQualityLevels;
    pTable->pfnFlush = Flush;
    pTable->pfnGetMipPacking = GetMipPacking;
    pTable->pfnRelocateDeviceFuncs = RelocateDeviceFuncs;
    pTable->pfnResourceIsStagingBusy = ResourceIsStagingBusy;
    pTable->pfnResourceReadAfterWriteHazard = ResourceReadAfterWriteHazard;
    pTable->pfnSetMarker = SetMarker;
    pTable->pfnSetMarkerMode = SetMarkerMode;
    pTable->pfnSetTextFilterSize = SetTextFilterSize;
    pTable->pfnCreateBlendState = CreateBlendState;
    pTable->pfnDestroyBlendState = DestroyBlendState;
    pTable->pfnSetBlendState = SetBlendState;
    pTable->pfnCreateDepthStencilState = CreateDepthStencilState;
    pTable->pfnDestroyDepthStencilState = DestroyDepthStencilState;
    pTable->pfnSetDepthStencilState = SetDepthStencilState;
    pTable->pfnCreateRasterizerState = CreateRasterizerState;
    pTable->pfnDestroyRasterizerState = DestroyRasterizerState;
    pTable->pfnSetRasterizerState = SetRasterizerState;
    pTable->pfnCreateQuery = CreateQuery;
    pTable->pfnDestroyQuery = DestroyQuery;
    pTable->pfnQueryBegin = QueryBegin;
    pTable->pfnQueryEnd = QueryEnd;
    pTable->pfnQueryGetData = QueryGetData;
    pTable->pfnSetPredication = SetPredication;
    pTable->pfnCopyStructureCount = CopyStructureCount;
    pTable->pfnCopyTileMappings = CopyTileMappings;
    pTable->pfnCopyTiles = CopyTiles;
    pTable->pfnResourceCopy = ResourceCopy;
    pTable->pfnResourceCopyRegion = ResourceCopyRegion;
    pTable->pfnSoSetTargets = SoSetTargets;
    pTable->pfnSetViewports = SetViewports;
    pTable->pfnSetScissorRects = SetScissorRects;
    pTable->pfnClearDepthStencilView = ClearDepthStencilView;
    pTable->pfnClearRenderTargetView = ClearRenderTargetView;
    pTable->pfnClearUnorderedAccessViewFloat = ClearUnorderedAccessViewFloat;
    pTable->pfnClearUnorderedAccessViewUint = ClearUnorderedAccessViewUint;
    pTable->pfnClearView = ClearView;
    pTable->pfnGenMips = GenMips;
    pTable->pfnResourceResolveSubresource = ResourceResolveSubresource;
    pTable->pfnCalcPrivateOpenedResourceSize = CalcPrivateOpenedResourceSize;
    pTable->pfnCalcPrivateGeometryShaderWithStreamOutput = CalcPrivateGeometryShaderWithStreamOutput;
    pTable->pfnCalcPrivateBlendStateSize = CalcPrivateBlendStateSize;
    pTable->pfnCalcPrivateCommandListSize = CalcPrivateCommandListSize;
    pTable->pfnCalcPrivateDeferredContextSize = CalcPrivateDeferredContextSize;
    pTable->pfnCalcPrivateDepthStencilStateSize = CalcPrivateDepthStencilStateSize;
    pTable->pfnCalcPrivateDepthStencilViewSize = CalcPrivateDepthStencilViewSize;
    pTable->pfnCalcPrivateElementLayoutSize = CalcPrivateElementLayoutSize;
    pTable->pfnCalcPrivateQuerySize = CalcPrivateQuerySize;
    pTable->pfnCalcPrivateRasterizerStateSize = CalcPrivateRasterizerStateSize;
    pTable->pfnCalcPrivateRenderTargetViewSize = CalcPrivateRenderTargetViewSize;
    pTable->pfnCalcPrivateResourceSize = CalcPrivateResourceSize;
    pTable->pfnCalcPrivateSamplerSize = CalcPrivateSamplerSize;
    pTable->pfnCalcPrivateShaderResourceViewSize = CalcPrivateShaderResourceViewSize;
    pTable->pfnCalcPrivateShaderSize = CalcPrivateShaderSize;
    pTable->pfnCalcPrivateTessellationShaderSize = CalcPrivateTessellationShaderSize;
    pTable->pfnCalcPrivateUnorderedAccessViewSize = CalcPrivateUnorderedAccessViewSize;
    pTable->pfnCreateResource = CreateResource;
    pTable->pfnDestroyResource = DestroyResource;
    pTable->pfnOpenResource = OpenResource;
    pTable->pfnDiscard = Discard;
    pTable->pfnSetResourceMinLOD = SetResourceMinLOD;
    pTable->pfnCreateDepthStencilView = CreateDepthStencilView;
    pTable->pfnDestroyDepthStencilView = DestroyDepthStencilView;
    pTable->pfnCheckCounter = CheckCounter;
    pTable->pfnCheckCounterInfo = CheckCounterInfo;
    pTable->pfnResourceConvert = ResourceConvert;
    pTable->pfnResourceConvertRegion = ResourceConvertRegion;
    pTable->pfnCreateCommandList = CreateCommandList;
    pTable->pfnRecycleCreateCommandList = RecycleCreateCommandList;
    pTable->pfnDestroyCommandList = DestroyCommandList;
    pTable->pfnRecycleDestroyCommandList = RecycleDestroyCommandList;
    pTable->pfnAbandonCommandList = AbandonCommandList;
    pTable->pfnCommandListExecute = CommandListExecute;
    pTable->pfnRecycleCommandList = RecycleCommandList;
    pTable->pfnCreateDeferredContext = CreateDeferredContext;
    pTable->pfnRecycleCreateDeferredContext = RecycleCreateDeferredContext;
    pTable->pfnCalcDeferredContextHandleSize = CalcDeferredContextHandleSize;
    pTable->pfnCheckDeferredContextHandleSizes = CheckDeferredContextHandleSizes;
    pTable->pfnCreateUnorderedAccessView = CreateUnorderedAccessView;
    pTable->pfnDestroyUnorderedAccessView = DestroyUnorderedAccessView;
    pTable->pfnCsSetUnorderedAccessViews = CsSetUnorderedAccessViews;
    pTable->pfnDispatch = Dispatch;
    pTable->pfnDispatchIndirect = DispatchIndirect;
    pTable->pfnResizeTilePool = ResizeTilePool;
    pTable->pfnTiledResourceBarrier = TiledResourceBarrier;
}

} // namespace DDI
} // namespace UMD
} // namespace Crystal
#include "pch.h"
#include "umd_ddi.h"

namespace Crystal
{
namespace UMD
{
namespace DDI
{
    
void FillDdiTable( DXGI1_6_1_DDI_BASE_FUNCTIONS* pTable )
{
    pTable->pfnCheckPresentDurationSupport = CheckPresentDurationSupport;
    pTable->pfnPresent = Present;
    pTable->pfnPresent1 = Present1;
    pTable->pfnPresentMultiplaneOverlay = PresentMultiplaneOverlay;
    pTable->pfnPresentMultiplaneOverlay1 = PresentMultiplaneOverlay1;
    pTable->pfnSetDisplayMode = SetDisplayMode;
    pTable->pfnCheckMultiplaneOverlayColorSpaceSupport = CheckMultiplaneOverlayColorSpaceSupport;
    pTable->pfnGetGammaCaps = GetGammaCaps;
    pTable->pfnGetMultiplaneOverlayCaps = GetMultiplaneOverlayCaps;
    pTable->pfnGetMultiplaneOverlayGroupCaps = GetMultiplaneOverlayGroupCaps;
    pTable->pfnOfferResources1 = OfferResources1;
    pTable->pfnQueryResourceResidency = QueryResourceResidency;
    pTable->pfnReclaimResources = ReclaimResources;
    pTable->pfnReclaimResources1 = ReclaimResources1;
    pTable->pfnResolveSharedResource = ResolveSharedResource;
    pTable->pfnRotateResourceIdentities = RotateResourceIdentities;
    pTable->pfnSetResourcePriority = SetResourcePriority;
    pTable->pfnTrimResidencySet = TrimResidencySet;
    pTable->pfnBlt = Blt;
    pTable->pfnBlt1 = Blt1;
}

} // namespace DDI
} // namespace UMD
} // namespace Crystal
