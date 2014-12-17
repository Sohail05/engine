#include "ScriptEngine.hpp"
#include <scriptstdstring/scriptstdstring.h>
#include <cassert>
#include <iostream>

const std::string ScriptEngine::script_dir = "scripts";

// Print the script string to the standard output stream
void print(std::string &msg)
{
    std::cout << msg << std::endl;
}

// Implement a simple message callback function
void MessageCallback(const asSMessageInfo *msg, void *param)
{
    const char *type = "ERR ";
    if (msg->type == asMSGTYPE_WARNING)
        type = "WARN";
    else if (msg->type == asMSGTYPE_INFORMATION)
        type = "INFO";
    printf("%s (%d, %d) : %s : %s\n", msg->section, msg->row, msg->col, type, msg->message);
}

ScriptEngine::ScriptEngine() : m_engine(nullptr)
{
    m_engine = asCreateScriptEngine(ANGELSCRIPT_VERSION); 
    // Set the message callback to receive information on errors in human readable form.
    int r = m_engine->SetMessageCallback(asFUNCTION(MessageCallback), 0, asCALL_CDECL); assert(r >= 0);
    
    //use the default std::string
    RegisterStdString(m_engine);
    // Register the function that we want the scripts to call 
    r = m_engine->RegisterGlobalFunction("void print(const string &in)", asFUNCTION(print), asCALL_CDECL); assert(r >= 0);

	m_context = m_engine->CreateContext();
}

void ScriptEngine::loadScript(const std::string& script) {
	int r = m_builder.StartNewModule(m_engine, script.c_str());
	assert(r >= 0);

	r = m_builder.AddSectionFromFile(std::string(script_dir+script).c_str());
	assert(r >= 0);

	r = m_builder.BuildModule();
	assert(r >= 0);
}

void ScriptEngine::runScript(const std::string& script, const std::string& funcDecl) {
	asIScriptModule *mod = m_engine->GetModule(script.c_str());
	asIScriptFunction *func = mod->GetFunctionByDecl(funcDecl.c_str());
	assert(func != 0);

	asIScriptContext *ctx = m_engine->CreateContext();
	ctx->Prepare(func);
	int r = ctx->Execute();
	assert(r == asEXECUTION_FINISHED);
}

ScriptEngine::~ScriptEngine()
{
	m_context->Release();
    m_engine->Release();
}

