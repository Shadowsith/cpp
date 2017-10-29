#include <stdio.h>
#include <lua.hpp>

/* the Lua interpreter */
lua_State* L = luaL_newstate();

static int MyFunc(lua_State* L)
{
    int a = lua_tointeger(L, 1);
    int b = lua_tointeger(L, 2);
    int result = a + b;

    lua_pushinteger(L, result);
    return 1;

}


int main(void){
    luaL_openlibs(L);
    lua_pushcfunction(L, MyFunc);
    lua_register(L, "MyFunc", MyFunc);
    lua_pushinteger(L, 5);
    lua_setglobal(L, "Five");
    //lua_close(L);
}

