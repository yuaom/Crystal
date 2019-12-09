#include "pch.h"

namespace Crystal
{
namespace UMD
{
namespace DDI
{

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
VOID WINAPI DrawAuto(
    D3D10DDI_HDEVICE hDevice )
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

} // namespace DDI
} // namespace UMD
} // namespace Crystal
