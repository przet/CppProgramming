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

// Utility function declarations
bool checkLuaInput(lua_State* luaVM, int retCode); 

int lua_HostFunction(lua_State* luaVM)
{
	float a = (float)lua_tonumber(luaVM, 1);
	float b = (float)lua_tonumber(luaVM, 2);

	std::cout << "[C++] HostFunction(" << a << ", " << b << ") called" << std::endl;

	float c = a * b;
	lua_pushnumber(luaVM, c);
	// Number of args returned
	return 1;
}
int main(int argc, char** argv)
{
    // Create Lua VM (persistent)
    // TODO: Q: what cleans it up? Are we placing it on the heap?
    lua_State* L = luaL_newstate();
    luaL_openlibs(L); // includes math
	lua_register(L, "HostFunction", lua_HostFunction);

    int r = luaL_dofile(L, "..\\LuaScript.lua");

    if (checkLuaInput(L, r))
    {
        lua_getglobal(L, "DoAThing");
        if (lua_isfunction(L, -1))
        {
			lua_pushnumber(L, 5.0f);
			lua_pushnumber(L, 6.0f);
            if (checkLuaInput(L, lua_pcall(L, 2, 1, 0)))
            {
				printToConsole("[C++] called in Lua DoAThing(...), with result :", (float)lua_tonumber(L, -1));
				

            }
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