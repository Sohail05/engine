#ifndef game_PlatformWindows_hpp
#define game_PlatformWindows_hpp

static const std::string script_dir = "scripts/";

//FIXME: return an absolute path
inline std::string GetScriptsPath ()
{
    return script_dir;
}

#endif