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
#pragma comment(lib, "C:\\Consilium\\MSGuildTalk2020\\libs\\lua-5.3.5_Win64_dll14_lib\\lua53.lib")
#endif

int main(int argc, char** argv)
{
    // TODO: file!
    std::string cmd = "a = 7 + 11";

    // Create Lua VM
    lua_State* L = luaL_newstate();

    // note c_str: in C land here 
    int r = luaL_dostring(L, cmd.c_str());

    // For any embedding - need to have checks!!
    if (r == LUA_OK)
    {
        // global to vm 
        lua_getglobal(L, "a");
        // -1 top of lua stack
        if (lua_isnumber(L, -1))
        {
            float a_in_cpp = (float)lua_tonumber(L, -1);
            printToConsole("a in cpp =  ", a_in_cpp);
        }

    }
    else
    {
        printToConsole(lua_tostring(L, -1));
    }

    return 0;
}