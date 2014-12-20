#ifndef game_PlatformMac_hpp
#define game_PlatformMac_hpp

#include <ResourcePath.hpp>

static const std::string ScriptDir = "scripts/";

inline std::string GetScriptsPath ()
{
    return resourcePath() + ScriptDir;
}

#endif