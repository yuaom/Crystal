
namespace Crystal
{
namespace UMD
{
namespace DDI
{

#pragma region DDI Entry-points
VOID WINAPI DefaultConstantBufferUpdateSubresourceUP( D3D10DDI_HDEVICE, D3D10DDI_HRESOURCE, UINT, const D3D10_DDI_BOX*, const void*, UINT, UINT, UINT );
VOID WINAPI ResourceUpdateSubresourceUP( D3D10DDI_HDEVICE, D3D10DDI_HRESOURCE, UINT, const D3D10_DDI_BOX*, const void*, UINT, UINT, UINT );
VOID WINAPI VsSetConstantBuffers( D3D10DDI_HDEVICE, UINT, UINT, const D3D10DDI_HRESOURCE*, const UINT*, const UINT* );
VOID WINAPI HsSetConstantBuffers( D3D10DDI_HDEVICE, UINT, UINT, const D3D10DDI_HRESOURCE*, const UINT*, const UINT* );
VOID WINAPI DsSetConstantBuffers( D3D10DDI_HDEVICE, UINT, UINT, const D3D10DDI_HRESOURCE*, const UINT*, const UINT* );
VOID WINAPI GsSetConstantBuffers( D3D10DDI_HDEVICE, UINT, UINT, const D3D10DDI_HRESOURCE*, const UINT*, const UINT* );
VOID WINAPI PsSetConstantBuffers( D3D10DDI_HDEVICE, UINT, UINT, const D3D10DDI_HRESOURCE*, const UINT*, const UINT* );
VOID WINAPI CsSetConstantBuffers( D3D10DDI_HDEVICE, UINT, UINT, const D3D10DDI_HRESOURCE*, const UINT*, const UINT* );
VOID WINAPI CreateShaderResourceView( D3D10DDI_HDEVICE, const D3D11DDIARG_CREATESHADERRESOURCEVIEW*, D3D10DDI_HSHADERRESOURCEVIEW, D3D10DDI_HRTSHADERRESOURCEVIEW );
VOID WINAPI DestroyShaderResourceView( D3D10DDI_HDEVICE, D3D10DDI_HSHADERRESOURCEVIEW );
VOID WINAPI VsSetShaderResources( D3D10DDI_HDEVICE, UINT, UINT, const D3D10DDI_HSHADERRESOURCEVIEW* );
VOID WINAPI HsSetShaderResources( D3D10DDI_HDEVICE, UINT, UINT, const D3D10DDI_HSHADERRESOURCEVIEW* );
VOID WINAPI DsSetShaderResources( D3D10DDI_HDEVICE, UINT, UINT, const D3D10DDI_HSHADERRESOURCEVIEW* );
VOID WINAPI GsSetShaderResources( D3D10DDI_HDEVICE, UINT, UINT, const D3D10DDI_HSHADERRESOURCEVIEW* );
VOID WINAPI PsSetShaderResources( D3D10DDI_HDEVICE, UINT, UINT, const D3D10DDI_HSHADERRESOURCEVIEW* );
VOID WINAPI CsSetShaderResources( D3D10DDI_HDEVICE, UINT, UINT, const D3D10DDI_HSHADERRESOURCEVIEW* );
VOID WINAPI ShaderResourceViewReadAfterWriteHazard( D3D10DDI_HDEVICE, D3D10DDI_HSHADERRESOURCEVIEW, D3D10DDI_HRESOURCE );
VOID WINAPI CreateVertexShader( D3D10DDI_HDEVICE, const UINT*, D3D10DDI_HSHADER, D3D10DDI_HRTSHADER, const D3D11_1DDIARG_STAGE_IO_SIGNATURES* );
VOID WINAPI CreateHullShader( D3D10DDI_HDEVICE, const UINT*, D3D10DDI_HSHADER, D3D10DDI_HRTSHADER, const D3D11_1DDIARG_TESSELLATION_IO_SIGNATURES* );
VOID WINAPI CreateDomainShader( D3D10DDI_HDEVICE, const UINT*, D3D10DDI_HSHADER, D3D10DDI_HRTSHADER, const D3D11_1DDIARG_TESSELLATION_IO_SIGNATURES* );
VOID WINAPI CreateGeometryShader( D3D10DDI_HDEVICE, const UINT*, D3D10DDI_HSHADER, D3D10DDI_HRTSHADER, const D3D11_1DDIARG_STAGE_IO_SIGNATURES* );
VOID WINAPI CreateGeometryShaderWithStreamOutput( D3D10DDI_HDEVICE, const D3D11DDIARG_CREATEGEOMETRYSHADERWITHSTREAMOUTPUT*, D3D10DDI_HSHADER, D3D10DDI_HRTSHADER, const D3D11_1DDIARG_STAGE_IO_SIGNATURES* );
VOID WINAPI CreatePixelShader( D3D10DDI_HDEVICE, const UINT*, D3D10DDI_HSHADER, D3D10DDI_HRTSHADER, const D3D11_1DDIARG_STAGE_IO_SIGNATURES* );
VOID WINAPI CreateComputeShader( D3D10DDI_HDEVICE, const UINT*, D3D10DDI_HSHADER, D3D10DDI_HRTSHADER );
VOID WINAPI DestroyShader( D3D10DDI_HDEVICE, D3D10DDI_HSHADER );
VOID WINAPI VsSetShader( D3D10DDI_HDEVICE, D3D10DDI_HSHADER );
VOID WINAPI VsSetShaderWithIfaces( D3D10DDI_HDEVICE, D3D10DDI_HSHADER, UINT, const UINT*, const D3D11DDIARG_POINTERDATA* );
VOID WINAPI HsSetShader( D3D10DDI_HDEVICE, D3D10DDI_HSHADER );
VOID WINAPI HsSetShaderWithIfaces( D3D10DDI_HDEVICE, D3D10DDI_HSHADER, UINT, const UINT*, const D3D11DDIARG_POINTERDATA* );
VOID WINAPI DsSetShader( D3D10DDI_HDEVICE, D3D10DDI_HSHADER );
VOID WINAPI DsSetShaderWithIfaces( D3D10DDI_HDEVICE, D3D10DDI_HSHADER, UINT, const UINT*, const D3D11DDIARG_POINTERDATA* );
VOID WINAPI GsSetShader( D3D10DDI_HDEVICE, D3D10DDI_HSHADER );
VOID WINAPI GsSetShaderWithIfaces( D3D10DDI_HDEVICE, D3D10DDI_HSHADER, UINT, const UINT*, const D3D11DDIARG_POINTERDATA* );
VOID WINAPI PsSetShader( D3D10DDI_HDEVICE, D3D10DDI_HSHADER );
VOID WINAPI PsSetShaderWithIfaces( D3D10DDI_HDEVICE, D3D10DDI_HSHADER, UINT, const UINT*, const D3D11DDIARG_POINTERDATA* );
VOID WINAPI CsSetShader( D3D10DDI_HDEVICE, D3D10DDI_HSHADER );
VOID WINAPI CsSetShaderWithIfaces( D3D10DDI_HDEVICE, D3D10DDI_HSHADER, UINT, const UINT*, const D3D11DDIARG_POINTERDATA* );
VOID WINAPI AssignDebugBinary( D3D10DDI_HDEVICE, D3D10DDI_HSHADER, UINT, const void* );
VOID WINAPI CreateSampler( D3D10DDI_HDEVICE, const D3D10_DDI_SAMPLER_DESC*, D3D10DDI_HSAMPLER, D3D10DDI_HRTSAMPLER );
VOID WINAPI DestroySampler( D3D10DDI_HDEVICE, D3D10DDI_HSAMPLER );
VOID WINAPI VsSetSamplers( D3D10DDI_HDEVICE, UINT, UINT, const D3D10DDI_HSAMPLER* );
VOID WINAPI HsSetSamplers( D3D10DDI_HDEVICE, UINT, UINT, const D3D10DDI_HSAMPLER* );
VOID WINAPI DsSetSamplers( D3D10DDI_HDEVICE, UINT, UINT, const D3D10DDI_HSAMPLER* );
VOID WINAPI GsSetSamplers( D3D10DDI_HDEVICE, UINT, UINT, const D3D10DDI_HSAMPLER* );
VOID WINAPI PsSetSamplers( D3D10DDI_HDEVICE, UINT, UINT, const D3D10DDI_HSAMPLER* );
VOID WINAPI CsSetSamplers( D3D10DDI_HDEVICE, UINT, UINT, const D3D10DDI_HSAMPLER* );
VOID WINAPI Draw( D3D10DDI_HDEVICE, UINT, UINT );
VOID WINAPI DrawAuto( D3D10DDI_HDEVICE );
VOID WINAPI DrawIndexed( D3D10DDI_HDEVICE, UINT, UINT, INT );
VOID WINAPI DrawIndexedInstanced( D3D10DDI_HDEVICE, UINT, UINT, UINT, INT, UINT );
VOID WINAPI DrawIndexedInstancedIndirect( D3D10DDI_HDEVICE, D3D10DDI_HRESOURCE, UINT );
VOID WINAPI DrawInstanced( D3D10DDI_HDEVICE, UINT, UINT, UINT, UINT );
VOID WINAPI DrawInstancedIndirect( D3D10DDI_HDEVICE, D3D10DDI_HRESOURCE, UINT );
VOID WINAPI DynamicConstantBufferMapDiscard( D3D10DDI_HDEVICE, D3D10DDI_HRESOURCE, UINT, D3D10_DDI_MAP, UINT, D3D10DDI_MAPPED_SUBRESOURCE* );
VOID WINAPI DynamicConstantBufferMapNoOverwrite( D3D10DDI_HDEVICE, D3D10DDI_HRESOURCE, UINT, D3D10_DDI_MAP, UINT, D3D10DDI_MAPPED_SUBRESOURCE* );
VOID WINAPI DynamicIABufferMapDiscard( D3D10DDI_HDEVICE, D3D10DDI_HRESOURCE, UINT, D3D10_DDI_MAP, UINT, D3D10DDI_MAPPED_SUBRESOURCE* );
VOID WINAPI DynamicIABufferMapNoOverwrite( D3D10DDI_HDEVICE, D3D10DDI_HRESOURCE, UINT, D3D10_DDI_MAP, UINT, D3D10DDI_MAPPED_SUBRESOURCE* );
VOID WINAPI DynamicResourceMapDiscard( D3D10DDI_HDEVICE, D3D10DDI_HRESOURCE, UINT, D3D10_DDI_MAP, UINT, D3D10DDI_MAPPED_SUBRESOURCE* );
VOID WINAPI DynamicConstantBufferUnmap( D3D10DDI_HDEVICE, D3D10DDI_HRESOURCE, UINT );
VOID WINAPI DynamicIABufferUnmap( D3D10DDI_HDEVICE, D3D10DDI_HRESOURCE, UINT );
VOID WINAPI DynamicResourceUnmap( D3D10DDI_HDEVICE, D3D10DDI_HRESOURCE, UINT );
VOID WINAPI ResourceMap( D3D10DDI_HDEVICE, D3D10DDI_HRESOURCE, UINT, D3D10_DDI_MAP, UINT, D3D10DDI_MAPPED_SUBRESOURCE* );
VOID WINAPI ResourceUnmap( D3D10DDI_HDEVICE, D3D10DDI_HRESOURCE, UINT );
VOID WINAPI StagingResourceMap( D3D10DDI_HDEVICE, D3D10DDI_HRESOURCE, UINT, D3D10_DDI_MAP, UINT, D3D10DDI_MAPPED_SUBRESOURCE* );
VOID WINAPI StagingResourceUnmap( D3D10DDI_HDEVICE, D3D10DDI_HRESOURCE, UINT );
VOID WINAPI CreateElementLayout( D3D10DDI_HDEVICE, const D3D10DDIARG_CREATEELEMENTLAYOUT*, D3D10DDI_HELEMENTLAYOUT, D3D10DDI_HRTELEMENTLAYOUT );
VOID WINAPI DestroyElementLayout( D3D10DDI_HDEVICE, D3D10DDI_HELEMENTLAYOUT );
VOID WINAPI IaSetIndexBuffer( D3D10DDI_HDEVICE, D3D10DDI_HRESOURCE, DXGI_FORMAT, UINT );
VOID WINAPI IaSetInputLayout( D3D10DDI_HDEVICE, D3D10DDI_HELEMENTLAYOUT );
VOID WINAPI IaSetTopology( D3D10DDI_HDEVICE, D3D10_DDI_PRIMITIVE_TOPOLOGY );
VOID WINAPI IaSetVertexBuffers( D3D10DDI_HDEVICE, UINT, UINT, const D3D10DDI_HRESOURCE*, const UINT*, const UINT* );
VOID WINAPI CreateRenderTargetView( D3D10DDI_HDEVICE, const D3D10DDIARG_CREATERENDERTARGETVIEW*, D3D10DDI_HRENDERTARGETVIEW, D3D10DDI_HRTRENDERTARGETVIEW );
VOID WINAPI DestroyRenderTargetView( D3D10DDI_HDEVICE, D3D10DDI_HRENDERTARGETVIEW );
VOID WINAPI SetRenderTargets( D3D10DDI_HDEVICE, const D3D10DDI_HRENDERTARGETVIEW*, UINT, UINT, D3D10DDI_HDEPTHSTENCILVIEW, const D3D11DDI_HUNORDEREDACCESSVIEW*, const UINT*, UINT, UINT, UINT, UINT );
VOID WINAPI DestroyDevice( D3D10DDI_HDEVICE );
VOID WINAPI CheckDirectFlipSupport( D3D10DDI_HDEVICE, D3D10DDI_HRESOURCE, D3D10DDI_HRESOURCE, UINT, BOOL* );
VOID WINAPI CheckFormatSupport( D3D10DDI_HDEVICE, DXGI_FORMAT, UINT* );
VOID WINAPI CheckMultisampleQualityLevels( D3D10DDI_HDEVICE, DXGI_FORMAT, UINT, UINT* );
BOOL WINAPI Flush( D3D10DDI_HDEVICE, UINT );
VOID WINAPI RelocateDeviceFuncs( D3D10DDI_HDEVICE, struct D3D11_1DDI_DEVICEFUNCS* );
BOOL WINAPI ResourceIsStagingBusy( D3D10DDI_HDEVICE, D3D10DDI_HRESOURCE );
VOID WINAPI ResourceReadAfterWriteHazard( D3D10DDI_HDEVICE, D3D10DDI_HRESOURCE );
VOID WINAPI SetTextFilterSize( D3D10DDI_HDEVICE, UINT, UINT );
VOID WINAPI CreateBlendState( D3D10DDI_HDEVICE, const D3D11_1_DDI_BLEND_DESC*, D3D10DDI_HBLENDSTATE, D3D10DDI_HRTBLENDSTATE );
VOID WINAPI DestroyBlendState( D3D10DDI_HDEVICE, D3D10DDI_HBLENDSTATE );
VOID WINAPI SetBlendState( D3D10DDI_HDEVICE, D3D10DDI_HBLENDSTATE, const FLOAT[4], UINT );
VOID WINAPI CreateDepthStencilState( D3D10DDI_HDEVICE, const D3D10_DDI_DEPTH_STENCIL_DESC*, D3D10DDI_HDEPTHSTENCILSTATE, D3D10DDI_HRTDEPTHSTENCILSTATE );
VOID WINAPI DestroyDepthStencilState( D3D10DDI_HDEVICE, D3D10DDI_HDEPTHSTENCILSTATE );
VOID WINAPI SetDepthStencilState( D3D10DDI_HDEVICE, D3D10DDI_HDEPTHSTENCILSTATE, UINT );
VOID WINAPI CreateRasterizerState( D3D10DDI_HDEVICE, const D3D11_1_DDI_RASTERIZER_DESC*, D3D10DDI_HRASTERIZERSTATE, D3D10DDI_HRTRASTERIZERSTATE );
VOID WINAPI DestroyRasterizerState( D3D10DDI_HDEVICE, D3D10DDI_HRASTERIZERSTATE );
VOID WINAPI SetRasterizerState( D3D10DDI_HDEVICE, D3D10DDI_HRASTERIZERSTATE );
VOID WINAPI CreateQuery( D3D10DDI_HDEVICE, const D3D10DDIARG_CREATEQUERY*, D3D10DDI_HQUERY, D3D10DDI_HRTQUERY );
VOID WINAPI DestroyQuery( D3D10DDI_HDEVICE, D3D10DDI_HQUERY );
VOID WINAPI QueryBegin( D3D10DDI_HDEVICE, D3D10DDI_HQUERY );
VOID WINAPI QueryEnd( D3D10DDI_HDEVICE, D3D10DDI_HQUERY );
VOID WINAPI QueryGetData( D3D10DDI_HDEVICE, D3D10DDI_HQUERY, void*, UINT, UINT );
VOID WINAPI SetPredication( D3D10DDI_HDEVICE, D3D10DDI_HQUERY, BOOL );
VOID WINAPI CopyStructureCount( D3D10DDI_HDEVICE, D3D10DDI_HRESOURCE, UINT, D3D11DDI_HUNORDEREDACCESSVIEW );
VOID WINAPI ResourceCopy( D3D10DDI_HDEVICE, D3D10DDI_HRESOURCE, D3D10DDI_HRESOURCE );
VOID WINAPI ResourceCopyRegion( D3D10DDI_HDEVICE, D3D10DDI_HRESOURCE, UINT, UINT, UINT, UINT, D3D10DDI_HRESOURCE, UINT, const D3D10_DDI_BOX*, UINT );
VOID WINAPI SoSetTargets( D3D10DDI_HDEVICE, UINT, UINT, const D3D10DDI_HRESOURCE*, const UINT* );
VOID WINAPI SetViewports( D3D10DDI_HDEVICE, UINT, UINT, const D3D10_DDI_VIEWPORT* );
VOID WINAPI SetScissorRects( D3D10DDI_HDEVICE, UINT, UINT, const D3D10_DDI_RECT* );
VOID WINAPI ClearDepthStencilView( D3D10DDI_HDEVICE, D3D10DDI_HDEPTHSTENCILVIEW, UINT, FLOAT, UINT8 );
VOID WINAPI ClearRenderTargetView( D3D10DDI_HDEVICE, D3D10DDI_HRENDERTARGETVIEW, FLOAT[4] );
VOID WINAPI ClearUnorderedAccessViewFloat( D3D10DDI_HDEVICE, D3D11DDI_HUNORDEREDACCESSVIEW, const FLOAT[4] );
VOID WINAPI ClearUnorderedAccessViewUint( D3D10DDI_HDEVICE, D3D11DDI_HUNORDEREDACCESSVIEW, const UINT[4] );
VOID WINAPI ClearView( D3D10DDI_HDEVICE, D3D11DDI_HANDLETYPE, void*, const FLOAT[4], const D3D10_DDI_RECT*, UINT );
VOID WINAPI GenMips( D3D10DDI_HDEVICE, D3D10DDI_HSHADERRESOURCEVIEW );
VOID WINAPI ResourceResolveSubresource( D3D10DDI_HDEVICE, D3D10DDI_HRESOURCE, UINT, D3D10DDI_HRESOURCE, UINT, DXGI_FORMAT );
SIZE_T WINAPI CalcPrivateOpenedResourceSize( D3D10DDI_HDEVICE, const D3D10DDIARG_OPENRESOURCE* );
SIZE_T WINAPI CalcPrivateGeometryShaderWithStreamOutput( D3D10DDI_HDEVICE, const D3D11DDIARG_CREATEGEOMETRYSHADERWITHSTREAMOUTPUT*, const D3D11_1DDIARG_STAGE_IO_SIGNATURES* );
SIZE_T WINAPI CalcPrivateBlendStateSize( D3D10DDI_HDEVICE, const D3D11_1_DDI_BLEND_DESC* );
SIZE_T WINAPI CalcPrivateCommandListSize( D3D10DDI_HDEVICE, const D3D11DDIARG_CREATECOMMANDLIST* );
SIZE_T WINAPI CalcPrivateDeferredContextSize( D3D10DDI_HDEVICE, const D3D11DDIARG_CALCPRIVATEDEFERREDCONTEXTSIZE* );
SIZE_T WINAPI CalcPrivateDepthStencilStateSize( D3D10DDI_HDEVICE, const D3D10_DDI_DEPTH_STENCIL_DESC* );
SIZE_T WINAPI CalcPrivateDepthStencilViewSize( D3D10DDI_HDEVICE, const D3D11DDIARG_CREATEDEPTHSTENCILVIEW* );
SIZE_T WINAPI CalcPrivateElementLayoutSize( D3D10DDI_HDEVICE, const D3D10DDIARG_CREATEELEMENTLAYOUT* );
SIZE_T WINAPI CalcPrivateQuerySize( D3D10DDI_HDEVICE, const D3D10DDIARG_CREATEQUERY* );
SIZE_T WINAPI CalcPrivateRasterizerStateSize( D3D10DDI_HDEVICE, const D3D11_1_DDI_RASTERIZER_DESC* );
SIZE_T WINAPI CalcPrivateRenderTargetViewSize( D3D10DDI_HDEVICE, const D3D10DDIARG_CREATERENDERTARGETVIEW* );
SIZE_T WINAPI CalcPrivateResourceSize( D3D10DDI_HDEVICE, const D3D11DDIARG_CREATERESOURCE* );
SIZE_T WINAPI CalcPrivateSamplerSize( D3D10DDI_HDEVICE, const D3D10_DDI_SAMPLER_DESC* );
SIZE_T WINAPI CalcPrivateShaderResourceViewSize( D3D10DDI_HDEVICE, const D3D11DDIARG_CREATESHADERRESOURCEVIEW* );
SIZE_T WINAPI CalcPrivateShaderSize( D3D10DDI_HDEVICE, const UINT*, const D3D11_1DDIARG_STAGE_IO_SIGNATURES* );
SIZE_T WINAPI CalcPrivateTessellationShaderSize( D3D10DDI_HDEVICE, const UINT*, const D3D11_1DDIARG_TESSELLATION_IO_SIGNATURES* );
SIZE_T WINAPI CalcPrivateUnorderedAccessViewSize( D3D10DDI_HDEVICE, const D3D11DDIARG_CREATEUNORDEREDACCESSVIEW* );
VOID WINAPI CreateResource( D3D10DDI_HDEVICE, const D3D11DDIARG_CREATERESOURCE*, D3D10DDI_HRESOURCE, D3D10DDI_HRTRESOURCE );
VOID WINAPI DestroyResource( D3D10DDI_HDEVICE, D3D10DDI_HRESOURCE );
VOID WINAPI OpenResource( D3D10DDI_HDEVICE, const D3D10DDIARG_OPENRESOURCE*, D3D10DDI_HRESOURCE, D3D10DDI_HRTRESOURCE );
VOID WINAPI Discard( D3D10DDI_HDEVICE, D3D11DDI_HANDLETYPE, void*, const D3D10_DDI_RECT*, UINT );
VOID WINAPI SetResourceMinLOD( D3D10DDI_HDEVICE, D3D10DDI_HRESOURCE, FLOAT );
VOID WINAPI CreateDepthStencilView( D3D10DDI_HDEVICE, const D3D11DDIARG_CREATEDEPTHSTENCILVIEW*, D3D10DDI_HDEPTHSTENCILVIEW, D3D10DDI_HRTDEPTHSTENCILVIEW );
VOID WINAPI DestroyDepthStencilView( D3D10DDI_HDEVICE, D3D10DDI_HDEPTHSTENCILVIEW );
VOID WINAPI CheckCounter( D3D10DDI_HDEVICE, D3D10DDI_QUERY, D3D10DDI_COUNTER_TYPE*, UINT*, LPSTR, UINT*, LPSTR, UINT*, LPSTR, UINT* );
VOID WINAPI CheckCounterInfo( D3D10DDI_HDEVICE, D3D10DDI_COUNTER_INFO* );
VOID WINAPI ResourceConvert( D3D10DDI_HDEVICE, D3D10DDI_HRESOURCE, D3D10DDI_HRESOURCE );
VOID WINAPI ResourceConvertRegion( D3D10DDI_HDEVICE, D3D10DDI_HRESOURCE, UINT, UINT, UINT, UINT, D3D10DDI_HRESOURCE, UINT, const D3D10_DDI_BOX*, UINT );
VOID WINAPI CreateCommandList( D3D10DDI_HDEVICE, const D3D11DDIARG_CREATECOMMANDLIST*, D3D11DDI_HCOMMANDLIST, D3D11DDI_HRTCOMMANDLIST );
HRESULT WINAPI RecycleCreateCommandList( D3D10DDI_HDEVICE, const D3D11DDIARG_CREATECOMMANDLIST*, D3D11DDI_HCOMMANDLIST, D3D11DDI_HRTCOMMANDLIST );
VOID WINAPI DestroyCommandList( D3D10DDI_HDEVICE, D3D11DDI_HCOMMANDLIST );
VOID WINAPI RecycleDestroyCommandList( D3D10DDI_HDEVICE, D3D11DDI_HCOMMANDLIST );
VOID WINAPI AbandonCommandList( D3D10DDI_HDEVICE );
VOID WINAPI CommandListExecute( D3D10DDI_HDEVICE, D3D11DDI_HCOMMANDLIST );
VOID WINAPI RecycleCommandList( D3D10DDI_HDEVICE, D3D11DDI_HCOMMANDLIST );
VOID WINAPI CreateDeferredContext( D3D10DDI_HDEVICE, const D3D11DDIARG_CREATEDEFERREDCONTEXT* );
HRESULT WINAPI RecycleCreateDeferredContext( D3D10DDI_HDEVICE, const D3D11DDIARG_CREATEDEFERREDCONTEXT* );
SIZE_T WINAPI CalcDeferredContextHandleSize( D3D10DDI_HDEVICE, D3D11DDI_HANDLETYPE, void* );
VOID WINAPI CheckDeferredContextHandleSizes( D3D10DDI_HDEVICE, UINT*, D3D11DDI_HANDLESIZE* );
VOID WINAPI CreateUnorderedAccessView( D3D10DDI_HDEVICE, const D3D11DDIARG_CREATEUNORDEREDACCESSVIEW*, D3D11DDI_HUNORDEREDACCESSVIEW, D3D11DDI_HRTUNORDEREDACCESSVIEW );
VOID WINAPI DestroyUnorderedAccessView( D3D10DDI_HDEVICE, D3D11DDI_HUNORDEREDACCESSVIEW );
VOID WINAPI CsSetUnorderedAccessViews( D3D10DDI_HDEVICE, UINT, UINT, const D3D11DDI_HUNORDEREDACCESSVIEW*, const UINT* );
VOID WINAPI Dispatch( D3D10DDI_HDEVICE, UINT, UINT, UINT );
VOID WINAPI DispatchIndirect( D3D10DDI_HDEVICE, D3D10DDI_HRESOURCE, UINT );
#pragma endregion

void FillDdiTable( D3D11_1DDI_DEVICEFUNCS* pTable );

} // namespace DDI
} // namespace UMD
} // namespace Crystal
