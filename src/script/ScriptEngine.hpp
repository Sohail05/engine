#pragma once
#include "angelscript.h"

/** @brief A class above angelscript
*
*   This class handles all script files by the game (.as files).
*   It added some engine function to the scriptengine, so internals
*   can be accessed and modified.
*   @author Stephan Vedder
*   @date 16.12.2014
*/
class ScriptEngine
{
public:
    /** 
    *   Initializes the scriptengine (RAII)
    */
    ScriptEngine();
    /**
    *   RAI the scriptengin
    */
    ~ScriptEngine();

private:
    asIScriptEngine* m_engine;
};