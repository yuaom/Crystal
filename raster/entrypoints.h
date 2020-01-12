#pragma once
#include <cstdint>

using RASTERCONTEXT_HANDLE = size_t;

struct RASTERARGS_CREATECONTEXT
{
    RASTERCONTEXT_HANDLE    hHandle;    ///<< Raster Handle (out)
};

using PFNCREATECONTEXT      = bool( * )( RASTERARGS_CREATECONTEXT* args );
using PFNGETRINGWRITEINFO   = void( * )( RASTERCONTEXT_HANDLE handle, void* &pAddress, uint32_t& size );
using PFNRINGDOORBELL       = void( * )( RASTERCONTEXT_HANDLE handle, uint32_t size );

////////////////////////////////////////////////////////////////////////////////
struct RASTER_FUNCTIONS
{
    // Context Management
    PFNCREATECONTEXT    pfnCreateContext;

    // Ring Management
    PFNGETRINGWRITEINFO pfnGetRingWriteInfo;
    PFNRINGDOORBELL     pfnRingDoorbell;
};

////////////////////////////////////////////////////////////////////////////////
struct RASTER_OPTIONS
{
    uint32_t    TotalRingSize;          ///<< Total Ring Size ( in bytes )
    uint32_t    MinimumRingWriteSize;   ///<< Minimum Write Size required (in bytes)
};

////////////////////////////////////////////////////////////////////////////////
struct RASTERARGS_OPENRASTERIZER
{
    RASTER_OPTIONS      options;        // in
    RASTER_FUNCTIONS*   pRasterFuncs;   // out
};

////////////////////////////////////////////////////////////////////////////////
/// @brief Function Pointer Types
using PFNOPENRASTERIZER = bool ( * )( RASTERARGS_OPENRASTERIZER* );
bool OpenRasterizer( RASTERARGS_OPENRASTERIZER* pOpenRasterizer );

namespace Crystal
{
    namespace Raster
    {
        bool CreateContext( RASTERARGS_CREATECONTEXT* pContext );

        void GetRingWriteInfo( RASTERCONTEXT_HANDLE handle, void* &pAddress, uint32_t& size );
        void RingDoorbell( RASTERCONTEXT_HANDLE handle, uint32_t size );
    }
}
