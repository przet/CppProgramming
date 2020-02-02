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
    struct Player
    {
        std::string title;
        std::string name;
        std::string family;
        int level = 0;
    } player;

    // Create Lua VM (persistent)
    // TODO: Q: what cleans it up? Are we placing it on the heap?
    lua_State* L = luaL_newstate();
    luaL_openlibs(L); // includes math

    // note c_str: in C land here 
    int r = luaL_dofile(L, "..\\LuaScript.lua");

    // For any embedding - need to have checks!!
    if(checkLuaInput(L, r))
    {
        lua_getglobal(L, "PlayerName");
        // Note it is important to know the nature of the data 
        // in the lua script (string, fp etc).
        // TODO: infer? how? Eventually we might not be able to infer...
        if (lua_isstring(L, -1))
        {
            player.name = lua_tostring(L, -1);
            printToConsole("Player name is: ", player.name);
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