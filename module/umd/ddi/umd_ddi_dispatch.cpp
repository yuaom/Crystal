#include "pch.h"

namespace Crystal
{
namespace UMD
{
namespace DDI
{

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

} // namespace DDI
} // namespace UMD
} // namespace Crystal
