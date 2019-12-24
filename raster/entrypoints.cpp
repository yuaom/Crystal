#include "pch.h"
#include "entrypoints.h"
#include "raster_context.h"

////////////////////////////////////////////////////////////////////////////////
bool OpenRasterizer( RASTERARGS_OPENRASTERIZER* pOpenRasterizer )
{
    pOpenRasterizer->pRasterFuncs->pfnCreateContext = Crystal::Raster::CreateContext;

    return true;
}

namespace Crystal
{
    namespace Raster
    {
        ////////////////////////////////////////////////////////////////////////////////
        bool CreateContext( RASTERARGS_CREATECONTEXT* pCreateContextArgs )
        {
            return Context::Create( pCreateContextArgs );
        }
    }
}