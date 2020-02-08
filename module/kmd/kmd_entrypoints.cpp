#include "pch.h"
#include "kmd_entrypoints.h"
#include "kmd_adapter.h"
#include "kmd_device.h"
#include "kmd_context.h"
#include "kmd_allocation.h"

////////////////////////////////////////////////////////////////////////////////
EXTERN_C NTSTATUS APIENTRY D3DKMTCreateDevice( D3DKMT_CREATEDEVICE* pKTCreateDevice )
{
    LOG_DLL_ENTRY;

    NTSTATUS result = STATUS_SUCCESS;

    bool success = Crystal::KMD::Device::Create( pKTCreateDevice );

    if( !success )
    {
        result = E_FAIL;
    }

    return result;
}

////////////////////////////////////////////////////////////////////////////////
EXTERN_C NTSTATUS APIENTRY D3DKMTDestroyDevice( CONST D3DKMT_DESTROYDEVICE* pKTDestroyDevice )
{
    LOG_DLL_ENTRY;

    Crystal::KMD::Device::Destroy( pKTDestroyDevice->hDevice );
    
    return STATUS_SUCCESS;
}

////////////////////////////////////////////////////////////////////////////////
EXTERN_C NTSTATUS APIENTRY D3DKMTOpenAdapterFromGdiDisplayName(
    D3DKMT_OPENADAPTERFROMGDIDISPLAYNAME* pOpenAdapterFromGdiDisplayName )
{
    LOG_DLL_ENTRY;

    auto& pDisplays = Crystal::Displays::get();

    Crystal::Displays::find_result_itr_t display;
    if( pDisplays->FindByName( pOpenAdapterFromGdiDisplayName->DeviceName, display ) )
    {
        auto& pKmdAdapterManger = Crystal::KMD::KmdAdapterManager::get();

        Crystal::KMD::KmdAdapter* pAdapter = pKmdAdapterManger->CreateAdapter();

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
            DWORD dw = GetModuleFileNameW(
                g_hInstance,
                pFileNameInfo->UmdFileName,
                _countof( pFileNameInfo->UmdFileName ) );

            if( dw == 0 )
            {
                result = STATUS_INVALID_PARAMETER;
            }
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

    if( pPresent->Flags.Blt )
    {
        Crystal::KMD::Context* pContext = Crystal::KMD::Context::FromHandle( pPresent->hContext );

        // For now just synchronize the CPU/GPU, but later will
        // wait on the presentable surface
        while( pContext->m_RenderFenceCPU != pContext->m_RenderFenceGPU ) Sleep( 1 );

        Crystal::KMD::Allocation* pAllocation = Crystal::KMD::Allocation::FromHandle( pPresent->hSource );

        HDC dc = ::GetDC( pPresent->hWindow );
        HDC srcDC = CreateCompatibleDC( dc );

        //BITMAPINFO info;
        //ZeroMemory( &info, sizeof( BITMAPINFO ) );
        //info.bmiHeader.biSize           = sizeof( BITMAPINFO );
        //info.bmiHeader.biWidth          = pAllocation->GetWidth();
        //info.bmiHeader.biHeight         = -pAllocation->GetHeight();
        //info.bmiHeader.biPlanes         = 1;
        //info.bmiHeader.biBitCount       = pAllocation->GetBitsPerPixel();
        //info.bmiHeader.biCompression    = BI_RGB;
        BITMAPV5HEADER info;
        memset( &info, 0, sizeof( BITMAPV5HEADER ) );
        info.bV5Size        = sizeof( BITMAPV5HEADER );
        info.bV5Width       = pAllocation->GetWidth();
        info.bV5Height      = -pAllocation->GetHeight();
        info.bV5Planes      = 1;
        info.bV5BitCount    = 32;
        info.bV5Compression = BI_RGB;
        info.bV5AlphaMask   = 0xFF000000;
        info.bV5RedMask     = 0x00FF0000;
        info.bV5GreenMask   = 0x0000FF00;
        info.bV5BlueMask    = 0x000000FF;

        uint64_t srcData = pAllocation->GetAddress();

        HBITMAP hSrcBitmap = CreateDIBSection( 
            dc,
            reinterpret_cast<BITMAPINFO*>( &info ),
            DIB_RGB_COLORS, 
            reinterpret_cast<void**>( srcData ),
            NULL, 
            0 );

        if( hSrcBitmap )
        {
            SelectObject( srcDC, hSrcBitmap );

            BOOL success = BitBlt( dc,
                0, 
                0, 
                pAllocation->GetWidth(),
                pAllocation->GetHeight(),
                srcDC, 
                0, 
                0, 
                SRCCOPY );

            assert( success );
        }

        DeleteDC( srcDC );
        ReleaseDC( pPresent->hWindow, dc );
    }
    
    return STATUS_SUCCESS;
}

////////////////////////////////////////////////////////////////////////////////
EXTERN_C NTSTATUS APIENTRY D3DKMTCreateContext( D3DKMT_CREATECONTEXT* pCreateContext ) {
    LOG_DLL_ENTRY;

    Crystal::KMD::Context::Create( pCreateContext );

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