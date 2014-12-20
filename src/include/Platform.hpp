#pragma once

// Platform abstraction
#if defined(_WIN32)

#define PLATFORM_WINDOWS
#include <PlatformWindows.hpp>

#elif defined(__linux__)

#define PLATFORM_LINUX
#include <PlatformUnix.hpp>

#elif defined(__APPLE__)

#define PLATFORM_MACOS
#include <PlatformMac.hpp>

#else
#error Unknown platform
#endif
