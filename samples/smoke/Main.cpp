#include <Windows.h>
#include <d3d11.h>
#include <vector>
#include <string>
#include <assert.h>
#include <array>

void GetCommandLineArguments( std::vector<std::wstring>& args )
{
    LPWSTR* szArglist;
    int nArgs;
    int i;

    szArglist = CommandLineToArgvW(GetCommandLineW(), &nArgs);
    for (int i = 0; i < nArgs; i++)
    {
        args.push_back(szArglist[i]);
    }
    LocalFree(szArglist);
}

LRESULT CALLBACK WindowProc( HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam )
{
    switch( uMsg )
    {
    case WM_CLOSE:
        {
            DestroyWindow( hwnd );
        }
        break;
    case WM_DESTROY:
        PostQuitMessage( 0 );
        break;
    default:
        return DefWindowProc( hwnd, uMsg, wParam, lParam );
    }
    return 0;
}

int main()
{
    HRESULT hr = S_OK;

    bool useSoftware = true;
    
    UINT flags = D3D11_CREATE_DEVICE_DEBUG | D3D11_CREATE_DEVICE_SINGLETHREADED;
    D3D_FEATURE_LEVEL featureLevel = D3D_FEATURE_LEVEL_9_1;
    ID3D11Device* pDevice = nullptr;
    ID3D11DeviceContext* pContext = nullptr;
    IDXGISwapChain* pSwapChain = nullptr;
    ID3D11Resource* pBackBuffer = nullptr;
    ID3D11RenderTargetView* pRTV = nullptr;

    std::array<D3D_FEATURE_LEVEL, 1> featureLevels = {
        D3D_FEATURE_LEVEL_11_1
    };

    D3D_DRIVER_TYPE driverType = D3D_DRIVER_TYPE_HARDWARE;
    HMODULE module = NULL;

    if( useSoftware )
    {
        std::vector<std::wstring> args;
        GetCommandLineArguments( args );

        module = LoadLibraryW( args[1].c_str() );
        assert( module != NULL );

        driverType = D3D_DRIVER_TYPE_SOFTWARE;

        assert( GetProcAddress( module, "OpenAdapter10" ) != NULL );
        assert( GetProcAddress( module, "OpenAdapter10_2" ) != NULL );
        assert( GetProcAddress( module, "D3DKMTCreateDevice" ) != NULL );
    }

    WNDCLASS wc = { 0 };
    wc.lpfnWndProc      = WindowProc;
    wc.hInstance        = GetModuleHandle( NULL );
    wc.lpszClassName    = "SmokeWindow";
    RegisterClass( &wc );

    UINT style = WS_OVERLAPPEDWINDOW;
    RECT windowRect = { 0 };
    windowRect.right    = 1280;
    windowRect.bottom   = 720;
    AdjustWindowRect( &windowRect, style, FALSE );

    HWND hwnd = CreateWindowEx(
        0,
        wc.lpszClassName,
        "Crystal Smoke",
        style,
        CW_USEDEFAULT,
        CW_USEDEFAULT,
        windowRect.right - windowRect.left,
        windowRect.bottom - windowRect.top,
        NULL,
        NULL,
        wc.hInstance,
        NULL );

    RECT clientRect = { 0 };
    GetClientRect( hwnd, &clientRect );

    DXGI_SWAP_CHAIN_DESC swapChainDesc = { 0 };
    swapChainDesc.BufferCount       = 2;
    swapChainDesc.BufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
    swapChainDesc.BufferDesc.Height = clientRect.bottom - clientRect.top;
    swapChainDesc.BufferDesc.Width  = clientRect.right - clientRect.left;
    swapChainDesc.BufferUsage       = DXGI_USAGE_RENDER_TARGET_OUTPUT;
    swapChainDesc.OutputWindow      = hwnd;
    swapChainDesc.SampleDesc.Count  = 1;
    swapChainDesc.SwapEffect        = DXGI_SWAP_EFFECT_FLIP_DISCARD;
    swapChainDesc.Windowed          = TRUE;

    hr = D3D11CreateDeviceAndSwapChain(
        nullptr,
        driverType,
        module,
        flags,
        nullptr,
        0,
        D3D11_SDK_VERSION,
        &swapChainDesc,
        &pSwapChain,
        &pDevice,
        &featureLevel,
        &pContext );

    if( SUCCEEDED( hr ) )
    {
        hr = pSwapChain->GetBuffer( 
            0, 
            __uuidof( pBackBuffer ), 
            (void**)&pBackBuffer );
    }

    if( SUCCEEDED( hr ) )
    {
        hr = pDevice->CreateRenderTargetView( 
            pBackBuffer, 
            nullptr, 
            &pRTV );
    }

    if( SUCCEEDED( hr ) )
    {
        ShowWindow( hwnd, SW_SHOWDEFAULT );

        MSG msg = { };
        while( GetMessage( &msg, NULL, 0, 0 ) )
        {
            TranslateMessage( &msg );
            DispatchMessage( &msg );

            FLOAT color[4] = { 0.21f, 0.37f, 0.72f, 1.0f };
            pContext->ClearRenderTargetView( pRTV, color );
            pSwapChain->Present( 0, 0 );
        }
    }

    if( pBackBuffer ) pBackBuffer->Release();
    if( pRTV ) pRTV->Release();
    if( pSwapChain ) pSwapChain->Release();
    if( pContext ) pContext->Release();
    if( pDevice ) pDevice->Release();

    return 0;
}