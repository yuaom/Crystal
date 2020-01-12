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
#include <memory>

#include <Windows.h>

#define KILOBYTE    ( 1024 )
#define MEGABYTE    ( 1024 * KILOBYTE )
#define PAGE_SIZE   ( 4 * KILOBYTE )

namespace Utilities
{
    bool GetEnvironmentVariable( const std::wstring& name, std::wstring& out );
    void SetThreadName( const char* threadName );
}

#include "log.h"
#include "debugvars.h"
#include "../entrypoints.h"