# Crystal
A D3D11 software rasterizer.

Crystal is primarly intended to be an educational tool for those developers interested in implementing parts of the rasterization pipeline for a well established API. It is not a D3D11 API compiliant implementation like Microsoft's reference or WARP rasterizers.

D3D12 is not currently supported since the benefits and motivation for modern graphics APIs like it are outside the current goals of this project. Although that could change one day.

# Install

Crystal is intended to be built with the Microsoft Visual Studio environment and build tools.

1. Install CMake 3.16.0
1. Install [Visual Studio Community 2019](https://visualstudio.microsoft.com/vs/)
1. Install the [Windows SDK](https://developer.microsoft.com/en-US/windows/downloads/windows-10-sdk)
1. Install the [Windows WDK](https://docs.microsoft.com/en-us/windows-hardware/drivers/download-the-wdk)
1. Create solution files via Cmake:
```
cd Crystal
cmake -B ./build -DWDK="C:\Program Files (x86)\Windows Kits\10\Include\10.0.18362.0"
```

Optionally, you can update provided _build\_vs2019\_x64.cmd_. If you installed the WDK to a non-default path, you will need to open and update the WDK environment variable.

See [Build Tips](build.md) for more information.

# Use

Compilation will output a 64bit Crystal.dll which can be loaded and supplied to one of the D3D11 device creation APIs. For example:

```
    D3D11CreateDevice(
        ...
        D3D_DRIVER_TYPE_SOFTWARE,
        LoadLibrary( "Crystal.dll" ),
        ...
    )
```

See the Smoke sample for initialization.

# Components

* module - UMD/KMD unified DLL
* samples - simple proof-of-concept samples for debugging
* tests - ULTs built on [googletest](https://github.com/google/googletest)
* benchmarks - benchmarks built on [googlebench](https://github.com/google/benchmark)
* tools - various python scripts, clang binaries, etc.

# Related Projects

* Microsoft [graphics-drivers-samples](https://github.com/microsoft/graphics-driver-samples)
* SalviaRenderer [github](https://github.com/wuye9036/SalviaRenderer)