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

#pragma warning( push )
#pragma warning( disable : 4005 )
#include <ntstatus.h>
#pragma warning( pop )

// Project: Common
#include <common.h>