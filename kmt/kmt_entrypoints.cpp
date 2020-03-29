#include "pch.h"
#include "kmt_entrypoints.h"
#include "objects/kmt_adapter.h"
#include "objects/kmt_device.h"
#include "objects/kmt_context.h"
#include "objects/kmt_allocation.h"
#include "objects/kmt_display.h"

////////////////////////////////////////////////////////////////////////////////
EXTERN_C NTSTATUS APIENTRY D3DKMTCreateDevice( D3DKMT_CREATEDEVICE* pKTCreateDevice )
{
    LOG_DLL_ENTRY;

    NTSTATUS result = STATUS_SUCCESS;

    bool success = Crystal::KMT::Device::Create( pKTCreateDevice );

    if( !success )
    {
        assert( 0 );
        result = E_FAIL;
    }

    return result;
}

////////////////////////////////////////////////////////////////////////////////
EXTERN_C NTSTATUS APIENTRY D3DKMTDestroyDevice( CONST D3DKMT_DESTROYDEVICE* pKTDestroyDevice )
{
    LOG_DLL_ENTRY;

    Crystal::KMT::Device::Destroy( pKTDestroyDevice->hDevice );
    
    return STATUS_SUCCESS;
}

////////////////////////////////////////////////////////////////////////////////
EXTERN_C NTSTATUS APIENTRY D3DKMTOpenAdapterFromGdiDisplayName(
    D3DKMT_OPENADAPTERFROMGDIDISPLAYNAME* pOpenAdapterFromGdiDisplayName )
{
    LOG_DLL_ENTRY;

    using displays_t = Crystal::KMT::Displays;

    displays_t displays = displays_t();

    displays_t::find_result_itr_t display;
    if( displays.FindByName( pOpenAdapterFromGdiDisplayName->DeviceName, display ) )
    {
        auto& pKmtAdapterManger = Crystal::KMT::KmtAdapterManager::get();

        Crystal::KMT::KmtAdapter* pAdapter = pKmtAdapterManger->CreateAdapter();

        pOpenAdapterFromGdiDisplayName->hAdapter        = pAdapter->GetHandle();
        pOpenAdapterFromGdiDisplayName->AdapterLuid     = pAdapter->GetLUID();
        pOpenAdapterFromGdiDisplayName->VidPnSourceId   = display->GetVidPinSourceId();
    }

    return STATUS_SUCCESS;
}

////////////////////////////////////////////////////////////////////////////////
EXTERN_C NTSTATUS APIENTRY D3DKMTOpenAdapterFromDeviceName( 
    D3DKMT_OPENADAPTERFROMDEVICENAME* pOpenAdapterFromDeviceName )
{
    LOG_DLL_ENTRY;
    return STATUS_SUCCESS;
}

////////////////////////////////////////////////////////////////////////////////
EXTERN_C NTSTATUS APIENTRY D3DKMTQueryAdapterInfo( 
    CONST D3DKMT_QUERYADAPTERINFO* adapterInfo )
{
    LOG_DLL_ENTRY;

    NTSTATUS result = STATUS_SUCCESS;

    switch (adapterInfo->Type)
    {
    case KMTQAITYPE_UMDRIVERNAME:
    {
        D3DKMT_UMDFILENAMEINFO* pFileNameInfo = reinterpret_cast<D3DKMT_UMDFILENAMEINFO*>(adapterInfo->pPrivateDriverData);

        if (pFileNameInfo->Version == KMTUMDVERSION_DX10 ||
            pFileNameInfo->Version == KMTUMDVERSION_DX11)
        {
            wcscpy( pFileNameInfo->UmdFileName, L"CrystalUmd64.dll" );
        }
        else
        {
            result = STATUS_INVALID_PARAMETER;
        }
    }
    break;
    case KMTQAITYPE_CHECKDRIVERUPDATESTATUS:
    {
        BOOL* pUpdateStatus = reinterpret_cast<BOOL*>(adapterInfo->pPrivateDriverData);
        *pUpdateStatus = FALSE;
    }
    break;
    case KMTQAITYPE_GETSEGMENTSIZE:
    {
        MEMORYSTATUSEX mem_status;
        mem_status.dwLength = sizeof( mem_status );
        GlobalMemoryStatusEx( &mem_status );

        D3DKMT_SEGMENTSIZEINFO* psi     = reinterpret_cast<D3DKMT_SEGMENTSIZEINFO*>( adapterInfo->pPrivateDriverData );
        psi->DedicatedVideoMemorySize   = 0;
        psi->DedicatedSystemMemorySize  = 0;
        psi->SharedSystemMemorySize     = std::max<uint64_t>( mem_status.ullTotalPhys / 2, 64 * MEGABYTE );
    }
    break;
    case KMTQAITYPE_PHYSICALADAPTERCOUNT:
    {
        UINT* count = reinterpret_cast<UINT*>( adapterInfo->pPrivateDriverData );
        *count = 0;
    }
    break;
    default:
        result = STATUS_INVALID_PARAMETER;
        break;
    };

    return result;
}

////////////////////////////////////////////////////////////////////////////////
EXTERN_C NTSTATUS APIENTRY D3DKMTGetDeviceState( D3DKMT_GETDEVICESTATE* pDeviceState )
{ 
    LOG_DLL_ENTRY;

    NTSTATUS result = STATUS_SUCCESS;

    switch( pDeviceState->StateType )
    {
    case D3DKMT_DEVICESTATE_RESET:
    {
        pDeviceState->ResetState.Value = 0;
    }
    break;
    default:
        assert( 0 );
    }

    return result;
}

////////////////////////////////////////////////////////////////////////////////
EXTERN_C NTSTATUS APIENTRY D3DKMTCreateContextVirtual( D3DKMT_CREATECONTEXTVIRTUAL* pCreateContextVirtual )
{
    LOG_DLL_ENTRY;
    return STATUS_SUCCESS;
}

////////////////////////////////////////////////////////////////////////////////
EXTERN_C NTSTATUS APIENTRY D3DKMTPresent( D3DKMT_PRESENT* pPresent )
{
    LOG_DLL_ENTRY;
    NTSTATUS result = STATUS_SUCCESS;

    if( pPresent->Flags.Blt )
    {
        Crystal::KMT::Context* pContext = Crystal::KMT::Context::FromHandle( pPresent->hContext );

        // For now just synchronize the CPU/GPU, but later will
        // wait on the presentable surface
        while( pContext->m_RenderFenceCPU != pContext->m_RenderFenceGPU ) Sleep( 1 );

        Crystal::KMT::Allocation* pAllocation = Crystal::KMT::Allocation::FromHandle( pPresent->hSource );

        HDC dstDC = GetDC( pPresent->hWindow );

        void* pSrcData = reinterpret_cast<void*>( pAllocation->GetAddress() );

        D3DKMT_CREATEDCFROMMEMORY dcFromMem;
        ZeroMemory( &dcFromMem, sizeof( D3DKMT_CREATEDCFROMMEMORY ) );
        dcFromMem.pMemory       = pSrcData;
        dcFromMem.Format        = D3DDDIFMT_A8R8G8B8;
        dcFromMem.Width         = pAllocation->GetWidth();
        dcFromMem.Height        = pAllocation->GetHeight();
        dcFromMem.Pitch         = pAllocation->GetWidth() * pAllocation->GetBitsPerPixel() / 8;
        dcFromMem.hDeviceDc     = CreateDCW( L"DISPLAY", NULL, NULL, NULL );

        result = D3DKMTCreateDCFromMemory( &dcFromMem );

        if( SUCCEEDED( result ) )
        {
            RECT dstRect = { 0 };
            RECT srcRect = { 0 };

            if( pPresent->Flags.DstRectValid )
            {
                dstRect = pPresent->DstRect;
            }
            else
            {
                GetClientRect( pPresent->hWindow, &dstRect );
            }

            if( pPresent->Flags.SrcRectValid )
            {
                srcRect = pPresent->SrcRect;
            }

            BOOL success = BitBlt(
                dstDC,
                dstRect.left,
                dstRect.top,
                dstRect.right - dstRect.left,
                dstRect.bottom - dstRect.top,
                dcFromMem.hDc,
                srcRect.left,
                srcRect.top,
                SRCCOPY );

            if( !success )
            {
                result = E_FAIL;
            }
        }

        D3DKMT_DESTROYDCFROMMEMORY destroyMem;
        ZeroMemory( &destroyMem, sizeof( D3DKMT_DESTROYDCFROMMEMORY ));
        destroyMem.hBitmap  = dcFromMem.hBitmap;
        destroyMem.hDc      = dcFromMem.hDc;

        D3DKMTDestroyDCFromMemory( &destroyMem );
        ReleaseDC( pPresent->hWindow, dstDC );
    }
    
    return result;
}

////////////////////////////////////////////////////////////////////////////////
EXTERN_C NTSTATUS APIENTRY D3DKMTCreateContext( D3DKMT_CREATECONTEXT* pCreateContext ) {
    LOG_DLL_ENTRY;

    Crystal::KMT::Context::Create( pCreateContext );

    return STATUS_SUCCESS;
}

////////////////////////////////////////////////////////////////////////////////
EXTERN_C NTSTATUS APIENTRY D3DKMTAcquireKeyedMutex( _Inout_ D3DKMT_ACQUIREKEYEDMUTEX* ){ LOG_DLL_ENTRY; return STATUS_SUCCESS; }
EXTERN_C NTSTATUS APIENTRY D3DKMTCloseAdapter( _In_ CONST D3DKMT_CLOSEADAPTER* ){ LOG_DLL_ENTRY; return STATUS_SUCCESS; }
EXTERN_C NTSTATUS APIENTRY D3DKMTConfigureSharedResource( _In_ CONST D3DKMT_CONFIGURESHAREDRESOURCE* ){ LOG_DLL_ENTRY; return STATUS_SUCCESS; }
EXTERN_C NTSTATUS APIENTRY D3DKMTCreateAllocation2( _Inout_ D3DKMT_CREATEALLOCATION* ){ LOG_DLL_ENTRY; return STATUS_SUCCESS; }
EXTERN_C NTSTATUS APIENTRY D3DKMTCreateKeyedMutex( _Inout_ D3DKMT_CREATEKEYEDMUTEX* ){ LOG_DLL_ENTRY; return STATUS_SUCCESS; }
EXTERN_C NTSTATUS APIENTRY D3DKMTCreateSynchronizationObject( _Inout_ D3DKMT_CREATESYNCHRONIZATIONOBJECT* ){ LOG_DLL_ENTRY; return STATUS_SUCCESS; }
EXTERN_C NTSTATUS APIENTRY D3DKMTCreateSynchronizationObject2( _Inout_ D3DKMT_CREATESYNCHRONIZATIONOBJECT2* ){ LOG_DLL_ENTRY; return STATUS_SUCCESS; }
EXTERN_C NTSTATUS APIENTRY D3DKMTDestroyContext( _In_ CONST D3DKMT_DESTROYCONTEXT* ){ LOG_DLL_ENTRY; return STATUS_SUCCESS; }
EXTERN_C NTSTATUS APIENTRY D3DKMTDestroyKeyedMutex( _In_ CONST D3DKMT_DESTROYKEYEDMUTEX* ){ LOG_DLL_ENTRY; return STATUS_SUCCESS; }
EXTERN_C NTSTATUS APIENTRY D3DKMTDestroySynchronizationObject( _In_ CONST D3DKMT_DESTROYSYNCHRONIZATIONOBJECT* ){ LOG_DLL_ENTRY; return STATUS_SUCCESS; }
EXTERN_C NTSTATUS APIENTRY D3DKMTEscape( _In_ CONST D3DKMT_ESCAPE* ){ LOG_DLL_ENTRY; return STATUS_SUCCESS; }
EXTERN_C NTSTATUS APIENTRY D3DKMTGetContextSchedulingPriority( _Inout_ D3DKMT_GETCONTEXTSCHEDULINGPRIORITY* ){ LOG_DLL_ENTRY; return STATUS_SUCCESS; }
EXTERN_C NTSTATUS APIENTRY D3DKMTGetDisplayModeList( _Inout_ D3DKMT_GETDISPLAYMODELIST* ){ LOG_DLL_ENTRY; return STATUS_SUCCESS; }
EXTERN_C NTSTATUS APIENTRY D3DKMTGetMultisampleMethodList( _Inout_ D3DKMT_GETMULTISAMPLEMETHODLIST* ){ LOG_DLL_ENTRY; return STATUS_SUCCESS; }
EXTERN_C NTSTATUS APIENTRY D3DKMTGetRuntimeData( _Inout_ CONST D3DKMT_GETRUNTIMEDATA* ){ LOG_DLL_ENTRY; return STATUS_SUCCESS; }
EXTERN_C NTSTATUS APIENTRY D3DKMTGetSharedPrimaryHandle( _Inout_ D3DKMT_GETSHAREDPRIMARYHANDLE* ){ LOG_DLL_ENTRY; return STATUS_SUCCESS; }
EXTERN_C NTSTATUS APIENTRY D3DKMTLock( _Inout_ D3DKMT_LOCK* ){ LOG_DLL_ENTRY; return STATUS_SUCCESS; }
EXTERN_C NTSTATUS APIENTRY D3DKMTOpenKeyedMutex( _Inout_ D3DKMT_OPENKEYEDMUTEX* ){ LOG_DLL_ENTRY; return STATUS_SUCCESS; }
EXTERN_C NTSTATUS APIENTRY D3DKMTOpenResource( _Inout_ D3DKMT_OPENRESOURCE* ){ LOG_DLL_ENTRY; return STATUS_SUCCESS; }
EXTERN_C NTSTATUS APIENTRY D3DKMTOpenResource2( _Inout_ D3DKMT_OPENRESOURCE* ){ LOG_DLL_ENTRY; return STATUS_SUCCESS; }
EXTERN_C NTSTATUS APIENTRY D3DKMTOpenSynchronizationObject( _Inout_ D3DKMT_OPENSYNCHRONIZATIONOBJECT* ){ LOG_DLL_ENTRY; return STATUS_SUCCESS; }
EXTERN_C NTSTATUS APIENTRY D3DKMTQueryAllocationResidency( _In_ CONST D3DKMT_QUERYALLOCATIONRESIDENCY* ){ LOG_DLL_ENTRY; return STATUS_SUCCESS; }
EXTERN_C NTSTATUS APIENTRY D3DKMTQueryResourceInfo( _Inout_ D3DKMT_QUERYRESOURCEINFO* ){ LOG_DLL_ENTRY; return STATUS_SUCCESS; }
EXTERN_C NTSTATUS APIENTRY D3DKMTReleaseKeyedMutex( _Inout_ D3DKMT_RELEASEKEYEDMUTEX* ){ LOG_DLL_ENTRY; return STATUS_SUCCESS; }
EXTERN_C NTSTATUS APIENTRY D3DKMTSetAllocationPriority( _In_ CONST D3DKMT_SETALLOCATIONPRIORITY* ){ LOG_DLL_ENTRY; return STATUS_SUCCESS; }
EXTERN_C NTSTATUS APIENTRY D3DKMTSetContextSchedulingPriority( _In_ CONST D3DKMT_SETCONTEXTSCHEDULINGPRIORITY* ){ LOG_DLL_ENTRY; return STATUS_SUCCESS; }
EXTERN_C NTSTATUS APIENTRY D3DKMTSetDisplayMode( _Inout_ CONST D3DKMT_SETDISPLAYMODE* ){ LOG_DLL_ENTRY; return STATUS_SUCCESS; }
EXTERN_C NTSTATUS APIENTRY D3DKMTSetDisplayPrivateDriverFormat( _In_ CONST D3DKMT_SETDISPLAYPRIVATEDRIVERFORMAT* ){ LOG_DLL_ENTRY; return STATUS_SUCCESS; }
EXTERN_C NTSTATUS APIENTRY D3DKMTSetGammaRamp( _In_ CONST D3DKMT_SETGAMMARAMP* ){ LOG_DLL_ENTRY; return STATUS_SUCCESS; }
EXTERN_C NTSTATUS APIENTRY D3DKMTSetVidPnSourceOwner( _In_ CONST D3DKMT_SETVIDPNSOURCEOWNER* ){ LOG_DLL_ENTRY; return STATUS_SUCCESS; }
EXTERN_C NTSTATUS APIENTRY D3DKMTSignalSynchronizationObject( _In_ CONST D3DKMT_SIGNALSYNCHRONIZATIONOBJECT* ){ LOG_DLL_ENTRY; return STATUS_SUCCESS; }
EXTERN_C NTSTATUS APIENTRY D3DKMTSignalSynchronizationObject2( _In_ CONST D3DKMT_SIGNALSYNCHRONIZATIONOBJECT2* ){ LOG_DLL_ENTRY; return STATUS_SUCCESS; }
EXTERN_C NTSTATUS APIENTRY D3DKMTUnlock( _In_ CONST D3DKMT_UNLOCK* ){ LOG_DLL_ENTRY; return STATUS_SUCCESS; }
EXTERN_C NTSTATUS APIENTRY D3DKMTWaitForSynchronizationObject( _In_ CONST D3DKMT_WAITFORSYNCHRONIZATIONOBJECT* ){ LOG_DLL_ENTRY; return STATUS_SUCCESS; }
EXTERN_C NTSTATUS APIENTRY D3DKMTWaitForSynchronizationObject2( _In_ CONST D3DKMT_WAITFORSYNCHRONIZATIONOBJECT2* ){ LOG_DLL_ENTRY; return STATUS_SUCCESS; }
EXTERN_C NTSTATUS APIENTRY D3DKMTWaitForVerticalBlankEvent( _In_ CONST D3DKMT_WAITFORVERTICALBLANKEVENT* ){ LOG_DLL_ENTRY; return STATUS_SUCCESS; }