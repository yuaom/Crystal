#pragma once

#include <memory>
#include <string>
#include <sstream>
#include <assert.h>

#include <Windows.h>
#include <d3d10umddi.h>

#pragma warning( push )
#pragma warning( disable : 4005 )
#include <ntstatus.h>
#pragma warning( pop )

#define KILOBYTE	1024
#define MEGABYTE	1024 * KILOBYTE

#include "log.h"