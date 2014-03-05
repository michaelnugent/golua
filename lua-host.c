#include "lua.h"
#include "lauxlib.h"
#include "lualib.h"
 
#include "stdio.h"
#include "lua-host.h"
 
 
int main(int argc, char **argv) {
  return call_lua(argv[1]);
}

int call_lua(char *str) {
        //create a new lua state
        lua_State * L = luaL_newstate();
 
        //open all libraries
        luaL_openlibs(L);
 
        //int s = luaL_loadfile(L, file);
        int s = luaL_loadstring(L, str);
 
        if(!s)
            s = lua_pcall(L, 0, LUA_MULTRET, 0);
 
        //show any errors
        if(s){
            printf("Error: %s \n", lua_tostring(L, -1));
            lua_pop(L, 1);
        }

        return 0;
}

