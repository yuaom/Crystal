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

#include <Windows.h>

namespace Utilities
{
    bool GetEnvironmentVariable( const std::wstring& name, std::wstring& out );
}

#include "log.h"
#include "debugvars.h"