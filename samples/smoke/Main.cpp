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

int main()
{
	HRESULT hr = S_OK;
	
	UINT flags = D3D11_CREATE_DEVICE_DEBUG | D3D11_CREATE_DEVICE_SINGLETHREADED;
	D3D_FEATURE_LEVEL featureLevel = D3D_FEATURE_LEVEL_9_1;
	ID3D11Device* pDevice = nullptr;
	ID3D11DeviceContext* pContext = nullptr;

	std::array<D3D_FEATURE_LEVEL, 4> featureLevels = {
		D3D_FEATURE_LEVEL_11_1,
		D3D_FEATURE_LEVEL_11_0,
		D3D_FEATURE_LEVEL_10_1,
		D3D_FEATURE_LEVEL_10_0
	};

	std::vector<std::wstring> args;
	GetCommandLineArguments( args );

	HMODULE module = LoadLibraryW( args[1].c_str() );
	assert( module != NULL );

	assert( GetProcAddress( module, "OpenAdapter10" ) != NULL );
	assert( GetProcAddress( module, "OpenAdapter10_2" ) != NULL );
	assert( GetProcAddress( module, "D3DKMTCreateDevice" ) != NULL );

	hr = D3D11CreateDevice(
		nullptr,
		D3D_DRIVER_TYPE_SOFTWARE,
		module,
		flags,
		nullptr,
		0,
		D3D11_SDK_VERSION,
		&pDevice,
		&featureLevel,
		&pContext );

	return 0;
}