#include "ScriptEngine.hpp"
#include <scriptstdstring/scriptstdstring.h>
#include <scriptbuilder/scriptbuilder.h>
#include <cassert>
#include <iostream>

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
}

ScriptEngine::~ScriptEngine()
{
    m_engine->Release();
}

