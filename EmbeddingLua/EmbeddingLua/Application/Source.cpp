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

    int r = luaL_dofile(L, "..\\LuaScript.lua");

    if(checkLuaInput(L, r))
    {
        lua_getglobal(L, "player");
        if (lua_istable(L, -1))
        {
            // Stack management time!
            // Top of stack: player table
            // We want the Name (key) value
            // So: push string
            // Push "Name" to top of lua stack - table now at -2
            // lua_gettable, then reads top of stack as a key into the table,
            // replaces top of stack with the value associated with the key(via a pop)
            // get top of stack, then pop it off to reset stack - not essential (can manage indices),
            // but is good practice (consider: working with larger, nested data structures
            lua_pushstring(L, "Name");
            lua_gettable(L, -2);
            player.name = lua_tostring(L, -1);
            printToConsole("Player name is: ", player.name);
            // Note 1 not -1
            // TODO: ... investigate _why_...
            lua_pop(L, 1);
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