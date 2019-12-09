filemap = {
    # CalcSizes
    "CalcPrivate.*": "umd_ddi_calcprivate.cpp",

    # Resource Op
    "Clear.*": "umd_ddi_clear.cpp",
    ".*Resolve.*": "umd_ddi_resolve.cpp",
    ".*Copy.*": "umd_ddi_copy.cpp",
    "GenMips": "umd_ddi_genmips.cpp",
    "ResourceConvert.*": "umd_ddi_convert.cpp",

    # SO
    "SoSetTargets": "umd_ddi_streamout.cpp",

    # OM
    ".*BlendState": "umd_ddi_blend.cpp",
    ".*DepthStencilState": "umd_ddi_depthstencil.cpp",
    ".*RasterizerState": "umd_ddi_raster.cpp",
    "SetViewports": "umd_ddi_viewports.cpp",
    "SetScissorRects": "umd_ddi_scissor.cpp",

    # Render
    "Draw.*": "umd_ddi_draw.cpp",
    "Dispatch.*": "umd_ddi_dispatch.cpp",

    # Views
    "[V|H|D|G|P|C]sSetConstantBuffers$": "umd_ddi_cbv.cpp",
    "[V|H|D|G|P|C]sSetShaderResources$": "umd_ddi_srv.cpp",
    ".*ShaderResourceView": "umd_ddi_srv.cpp",
    "[V|H|D|G|P|C]sSetUnorderedAccessViews$": "umd_ddi_uav.cpp",
    ".*UnorderedAccessView": "umd_ddi_uav.cpp",
    ".*DepthStencilView": "umd_ddi_dsv.cpp",
    "SetRenderTargets": "umd_ddi_rtv.cpp",
    ".*RenderTargetView": "umd_ddi_rtv.cpp",

    # Samplers
    "[V|H|D|G|P|C]sSetSamplers$": "umd_ddi_samplers.cpp",
    ".*Sampler": "umd_ddi_samplers.cpp",

    # Shader
    "[V|H|D|G|P|C]sSetShader[WithIfaces]*": "umd_ddi_shader.cpp",
    ".*Shader": "umd_ddi_shader.cpp",
    "AssignDebugBinary": "umd_ddi_shader.cpp",

    # Resource
    ".*Resource$": "umd_ddi_resource.cpp",
    "SetResourceMinLOD": "umd_ddi_resource.cpp",
    "Discard": "umd_ddi_resource.cpp",

    # Map/Update
    ".*Update.*": "umd_ddi_update.cpp",
    ".*Map$": "umd_ddi_map.cpp",
    ".*Unmap$": "umd_ddi_map.cpp",

    # Queries
    "SetPredication|Query.*": "umd_ddi_query.cpp",
    ".*Query": "umd_ddi_query.cpp",

    # Counters
    ".*Counter.*": "umd_ddi_counters.cpp",

    # IA
    "Ia.*": "umd_ddi_input.cpp",
    ".*ElementLayout": "umd_ddi_input.cpp",

    # Dynamic
    "Dynamic.*": "umd_ddi_dynamic.cpp",

    # General Device
    ".*Device": "umd_ddi_device.cpp",
    "Flush": "umd_ddi_device.cpp",
    "ResourceIsStagingBusy": "umd_ddi_device.cpp",
    "RelocateDeviceFuncs": "umd_ddi_device.cpp",
    ".*WriteHazard": "umd_ddi_device.cpp",
    "CheckFormatSupport": "umd_ddi_device.cpp",
    "CheckMultisampleQualityLevels": "umd_ddi_device.cpp",
    "SetTextFilterSize": "umd_ddi_device.cpp",
    "CheckDirectFlipSupport": "umd_ddi_device.cpp",

    # Command list
    "CommandList.*": "umd_ddi_commandlist.cpp",
    ".*CommandList$": "umd_ddi_commandlist.cpp",

    # Deferred Contexts
    ".*DeferredContext.*": "umd_ddi_deferredcontext.cpp",
}
