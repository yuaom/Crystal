# Crystal
A D3D11 software rasterizer.

Crystal is primarly intended to be a educational tool for those developers interested in implementing parts of the rasterization pipeline for a well established API. It is not a D3D11 API compiliant implementation like Microsoft's reference or WARP rasterizers.

D3D12 is not currently supported since the benefits and motivation for modern graphics APIs like it are outside the current goals of this project. Although that could change one day.

# Install

Crystal is intended to be built with the Microsoft Visual Studio environment and build tools.

1. Install CMake 3.16.0
2. Run build_vs2019_x64.cmd
3. Open ./build/Crystal.sln and build.

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

# Components

TBD 

# Samples

TBD