# Crystal
A D3D11 software rasterizer.

Crystal is primarly intended to be an educational tool for those developers interested in implementing parts of the rasterization pipeline or driver stack for a well established API. It is not a D3D11 API compiliant implementation like Microsoft's reference or WARP rasterizers.

The project's components are broken up into the their logical stack responsibilities.

D3D12 is not currently supported since the benefits and motivation for modern graphics APIs like it are outside the current goals of this project.

# Install

Crystal is intended to be built with the Microsoft Visual Studio environment and build tools.

1. Install CMake 3.16.0
2. Install [Visual Studio Community 2019](https://visualstudio.microsoft.com/vs/)
3. Install the [Windows SDK](https://developer.microsoft.com/en-US/windows/downloads/windows-10-sdk)
4. Install the [Windows WDK](https://docs.microsoft.com/en-us/windows-hardware/drivers/download-the-wdk)
5. Clone Repository & Build
   
```
git clone --recurse-submodules https://github.com/tnamet/Crystal
cd Crystal
cmake -B ./build -DWDK="C:\Program Files (x86)\Windows Kits\10\Include\10.0.18362.0"
```

Check [build.md](build.md) for known build issues.

# Use

Compilation will output several 64bit DLLs. The KMT can be supplied to one of the D3D11 device creation APIs. For example:

```
    D3D11CreateDevice(
        ...
        D3D_DRIVER_TYPE_SOFTWARE,
        LoadLibrary( "CrystalKmt64.dll" ),
        ...
    )
```

See the Smoke sample for initialization.

# Components

| Component | Name  | Description  |
|---|---|---|
| UMD | Usern Mode Device Driver | Drives creation of GPU work as a result of API calls made by the application.  |
| KMT | Kernel Mode Thunk Layer | Interface between the OS, DX runtime, UMD, and rasterizer. |
| GMM | Graphics Memory Manager | Abstracts out memory layout  |
| Raster | Software Rasterizer | Processes and renders a command stream |
| Common | Common | Common objects shared across all projects, debug interfaces |
| Samples | Samples | Sample projects for smoke testing |
| Tools | Tools | Git submodules, LLVM, auto-generation, and more. |

# Related Projects

* Microsoft [graphics-drivers-samples](https://github.com/microsoft/graphics-driver-samples)
* SalviaRenderer [github](https://github.com/wuye9036/SalviaRenderer)