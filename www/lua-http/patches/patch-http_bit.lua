$NetBSD: patch-http_bit.lua,v 1.1 2020/09/03 07:39:40 nia Exp $

Recognize Lua 5.4.

--- http/bit.lua.orig	2019-02-13 11:43:45.000000000 +0000
+++ http/bit.lua
@@ -8,7 +8,7 @@ This means we can ignore the differences
 ]]
 
 -- Lua 5.3 has built-in bit operators, wrap them in a function.
-if _VERSION == "Lua 5.3" then
+if _VERSION == "Lua 5.3" or _VERSION == "Lua 5.4" then
 	-- Use debug.getinfo to get correct file+line numbers for loaded snippet
 	local info = debug.getinfo(1, "Sl")
 	return assert(load(("\n"):rep(info.currentline+1)..[[return {
