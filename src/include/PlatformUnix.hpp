#ifndef game_PlatformUnix_hpp
#define game_PlatformUnix_hpp

static const std::string script_dir = "scripts/";

//FIXME: return an absolute path - getcwd() ?
inline std::string GetScriptsPath ()
{
    return script_dir;
}

#endif