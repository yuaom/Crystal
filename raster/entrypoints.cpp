#include "entrypoints.h"

RASTER_FUNCTIONS g_RasterFuncs =
{
    CreateContext
};

////////////////////////////////////////////////////////////////////////////////
bool OpenRasterizer( RASTERARGS_OPENRASTERIZER* pOpenRasterizer )
{
    pOpenRasterizer->pRasterFuncs = &g_RasterFuncs;

    return true;
}

////////////////////////////////////////////////////////////////////////////////
bool CreateContext( RASTERARGS_CREATECONTEXT* pContext )
{
    return true;
}