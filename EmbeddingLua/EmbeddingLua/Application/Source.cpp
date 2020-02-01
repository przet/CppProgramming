#include <iostream>
#include <string>

template <typename U, typename T>
void
printToConsole(U desc, T t )
{
    std::cout << desc << t << std::endl;
}

template <typename T>
void
printToConsole(T t)
{
    std::cout << t << std::endl;
}

extern "C"
{
#include <lua.h>
#include <lauxlib.h>
#include <lualib.h>
}

#ifdef _WIN32
#pragma comment(lib, "F:\\lua-5.3.5_Win32_dll15_lib\\lua53.lib")
#endif

// Utility function declarations
bool checkLuaInput(lua_State* luaVM, int retCode); 

int main(int argc, char** argv)
{
    // TODO: file!
    std::string cmd = "a = 7 + 11 + math.sin(23.7)";

    // Create Lua VM (persistent)
    // TODO: Q: what cleans it up? Are we placing it on the heap?
    lua_State* L = luaL_newstate();
    luaL_openlibs(L); // includes math

    // note c_str: in C land here 
    int r = luaL_dostring(L, cmd.c_str());

    // For any embedding - need to have checks!!
    if(checkLuaInput(L, r))
    {
        lua_getglobal(L, "a");
        if (lua_isnumber(L, -1))
        {
            float a_in_cpp = (float)lua_tonumber(L, -1);
            printToConsole("a in cpp =  ", a_in_cpp);
        }
     }

    // demonstration of Lua VM persitence
    cmd = "a = a + 100";
    r = luaL_dostring(L, cmd.c_str());

    // TODO extract this repeated code into a function
    if(checkLuaInput(L, r))
    {
        lua_getglobal(L, "a");
        if (lua_isnumber(L, -1))
        {
            float a_in_cpp = (float)lua_tonumber(L, -1);
            printToConsole("a in cpp =  ", a_in_cpp);
        }
     }
    return 0;
}

// Utility function definitions
bool checkLuaInput(lua_State* luaVM, int retCode)
{
    if (retCode == LUA_OK)
        return true;
    else
    {
        printToConsole(lua_tostring(luaVM, -1));
        return false;
    }
}