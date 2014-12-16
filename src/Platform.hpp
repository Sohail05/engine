#pragma once

// Platform abstraction
#if defined(_WIN32)
#define PLATFORM_WINDOWS
#elif defined(__linux__)
#define PLATFORM_LINUX
#elif defined(_OSX_)
#define PLATFORM_MACOS
#else
#error Unknown platform
#endif
