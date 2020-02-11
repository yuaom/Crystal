#pragma once

#include <memory>
#include <string>
#include <sstream>
#include <assert.h>
#include <variant>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <stack>
#include <tuple>
#include <atomic>
#include <thread>
#include <mutex>
#include <iomanip>

// Windows
#include <Windows.h>
#include <d3d10umddi.h>

// Crystal Rasterizer
#include <Raster.h>

namespace RasterCommands = Crystal::Raster::COMMANDS;

#pragma warning( push )
#pragma warning( disable : 4005 )
#include <ntstatus.h>
#pragma warning( pop )

extern HINSTANCE    g_hInstance;

// Project: Common
#include "../common/common.h"

#include "display.h"