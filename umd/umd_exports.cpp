#include "pch.h"
#include "umd_exports.h"
#include "umd_adapter.h"

////////////////////////////////////////////////////////////////////////////////
EXTERN_C HRESULT APIENTRY OpenAdapter10( D3D10DDIARG_OPENADAPTER* arg1 )
{
    LOG_DLL_ENTRY;
    assert( 0 );
    return E_NOTIMPL;
}

////////////////////////////////////////////////////////////////////////////////
EXTERN_C HRESULT APIENTRY OpenAdapter10_2( D3D10DDIARG_OPENADAPTER* pOpenAdapter )
{
    LOG_DLL_ENTRY;

    Crystal::UMD::Adapter::Create( pOpenAdapter );

    return S_OK;
}