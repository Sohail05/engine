#pragma once
#include "angelscript.h"
#include <scriptbuilder/scriptbuilder.h>

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

	void loadScript(char* script);
	void runScript(char* script, char* funcDecl);
private:
    asIScriptEngine* m_engine;
	CScriptBuilder m_builder;
	asIScriptContext *m_context;
};