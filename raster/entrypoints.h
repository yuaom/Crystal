#pragma once
#include <cstdint>

////////////////////////////////////////////////////////////////////////////////
/// @brief CreateContext
using RASTERCONTEXT_HANDLE = size_t;

struct RASTERARGS_CREATECONTEXT
{
    RASTERCONTEXT_HANDLE    hHandle;    ///<< Raster Handle (out)
};

using PFNCREATECONTEXT = bool( * )( RASTERARGS_CREATECONTEXT* );

////////////////////////////////////////////////////////////////////////////////
struct RASTER_FUNCTIONS
{
    PFNCREATECONTEXT    pfnCreateContext;
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
bool CreateContext( RASTERARGS_CREATECONTEXT* pContext );