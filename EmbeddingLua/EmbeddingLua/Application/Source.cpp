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

int main(int argc, char** argv)
{
    // Create Lua VM (persistent)
    // TODO: Q: what cleans it up? Are we placing it on the heap?
    lua_State* L = luaL_newstate();
    luaL_openlibs(L); // includes math

    int r = luaL_dofile(L, "..\\LuaScript.lua");

    if (checkLuaInput(L, r))
    {
        lua_getglobal(L, "GetPlayer");
        if (lua_isfunction(L, -1))
        {
			// Player at 0th location
            lua_pushnumber(L, 1);

            // note we need to pass in 2, the number of arguments to function
            // and the number of arguments we are expecting as output (1)
            // lua_pcall executes the function
            if (checkLuaInput(L, lua_pcall(L, 1, 1, 0)))
            {
				if (lua_istable(L, -1))
				{
					lua_pushstring(L, "Name");
					lua_gettable(L, -2);
					printToConsole("Name: ", lua_tostring(L, -1));
				}


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