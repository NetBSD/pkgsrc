$NetBSD: patch-Lua.h,v 1.1 2021/04/13 08:55:59 nia Exp $

Fix absolute paths.

--- Lua.h.orig	2020-05-24 10:59:03.000000000 +0000
+++ Lua.h
@@ -6,41 +6,9 @@
 
 #include "StrFns.h"
 
-#if defined __BUNDLED__
-	#if defined __LUA_VERSION_5_3__
-		#include "Lua-5.3/src/lua.hpp"
-		#include "Lua-5.3/src/lualib.h"
-		#include "Lua-5.3/src/lauxlib.h"
-	#else // __LUAJIT_VERSION_2_1__
-		#include "LuaJIT/src/lua.hpp"
-	#endif
-#else
-	#if defined __LUA_VERSION_x__
-		#include "/usr/local/include/lua.hpp"
-		#include "/usr/local/include/lualib.h"
-		#include "/usr/local/include/lauxlib.h"
-	#elif __LUA_VERSION_5_4__
-		#include "/usr/local/include/lua54/lua.hpp"
-		#include "/usr/local/include/lua54/lualib.h"
-		#include "/usr/local/include/lua54/lauxlib.h"
-	#elif __LUA_VERSION_5_3__
-		#include "/usr/local/include/lua53/lua.hpp"
-		#include "/usr/local/include/lua53/lualib.h"
-		#include "/usr/local/include/lua53/lauxlib.h"
-	#elif __LUA_VERSION_5_2__
-		#include "/usr/local/include/lua52/lua.hpp"
-		#include "/usr/local/include/lua52/lualib.h"
-		#include "/usr/local/include/lua52/lauxlib.h"
-	#elif __LUA_VERSION_5_1__
-		#include "/usr/local/include/lua51/lua.hpp"
-		#include "/usr/local/include/lua51/lualib.h"
-		#include "/usr/local/include/lua51/lauxlib.h"
-	#elif __LUAJIT_VERSION_2_0__
-		#include "/usr/local/include/luajit-2.0/lua.hpp"
-	#else //__LUAJIT_VERSION_2_1__
-		#include "/usr/local/include/luajit-2.1/lua.hpp"
-	#endif
-#endif
+#include <lua.hpp>
+#include <lualib.h>
+#include <lauxlib.h>
 
 void process_lua_error(std::string& errStr, int& errLineNo);
 
