#include "pch.h"

namespace Crystal
{
namespace UMD
{
namespace DDI
{

////////////////////////////////////////////////////////////////////////////////
HRESULT WINAPI OfferResources1(
    DXGI_DDI_ARG_OFFERRESOURCES1* pOfferresources1 )
{
    LOG_DLL_ENTRY;
    return E_FAIL;
}

////////////////////////////////////////////////////////////////////////////////
HRESULT WINAPI QueryResourceResidency(
    DXGI_DDI_ARG_QUERYRESOURCERESIDENCY* pQueryresourceresidency )
{
    LOG_DLL_ENTRY;
    return E_FAIL;
}

////////////////////////////////////////////////////////////////////////////////
HRESULT WINAPI ReclaimResources(
    DXGI_DDI_ARG_RECLAIMRESOURCES* pReclaimresources )
{
    LOG_DLL_ENTRY;
    return E_FAIL;
}

////////////////////////////////////////////////////////////////////////////////
HRESULT WINAPI ReclaimResources1(
    DXGI_DDI_ARG_RECLAIMRESOURCES1* pReclaimresources1 )
{
    LOG_DLL_ENTRY;
    return E_FAIL;
}

////////////////////////////////////////////////////////////////////////////////
HRESULT WINAPI ResolveSharedResource(
    DXGI_DDI_ARG_RESOLVESHAREDRESOURCE* pResolvesharedresource )
{
    LOG_DLL_ENTRY;
    return E_FAIL;
}

////////////////////////////////////////////////////////////////////////////////
HRESULT WINAPI RotateResourceIdentities(
    DXGI_DDI_ARG_ROTATE_RESOURCE_IDENTITIES* pRotateResourceIdentities )
{
    // LOG_DLL_ENTRY;
    return S_OK;
}

////////////////////////////////////////////////////////////////////////////////
HRESULT WINAPI SetResourcePriority(
    DXGI_DDI_ARG_SETRESOURCEPRIORITY* pSetresourcepriority )
{
    LOG_DLL_ENTRY;
    return E_FAIL;
}

////////////////////////////////////////////////////////////////////////////////
HRESULT WINAPI TrimResidencySet(
    DXGI_DDI_ARG_TRIMRESIDENCYSET* pTrimresidencyset )
{
    LOG_DLL_ENTRY;
    return E_FAIL;
}

} // namespace DDI
} // namespace UMD
} // namespace Crystal
