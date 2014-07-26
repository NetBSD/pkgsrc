$NetBSD: patch-build_lua-detect.mk,v 1.1 2014/07/26 19:58:38 wiz Exp $

Fix lua detection for pkgsrc.

--- build/lua-detect.mk.orig	2014-05-27 22:00:18.000000000 +0000
+++ build/lua-detect.mk
@@ -27,7 +27,7 @@ ifeq ($(LUA_VERSION),5.0)
     LUA_VERSION=
 endif
 
-LUA_LIBS     := $(or $(shell pkg-config --libs lua$(LUA_VERSION)),   $(error "pkg-config couldn't find linker flags for lua$(LUA_VERSION)!"))
-LUA_INCLUDES := $(shell pkg-config --cflags lua$(LUA_VERSION))
+LUA_LIBS     := $(or $(shell pkg-config --libs lua),   $(error "pkg-config couldn't find linker flags for lua!"))
+LUA_INCLUDES := $(shell pkg-config --cflags lua)
 LUA          := $(or $(shell which lua$(LUA_VERSION)),               $(error No lua$(LUA_VERSION) interpreter found!))
 LUAC         := $(or $(shell which luac$(LUA_VERSION)),              $(error No lua$(LUA_VERSION) compiler found!))
