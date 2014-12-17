#pragma once
#include <angelscript.h>
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

	void loadScript(const std::string& script);
    void runScript(const std::string& script, const std::string& funcDecl);
private:
    static const std::string script_dir;
    asIScriptEngine* m_engine;
	CScriptBuilder m_builder;
	asIScriptContext *m_context;
};