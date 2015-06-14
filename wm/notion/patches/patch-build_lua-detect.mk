$NetBSD: patch-build_lua-detect.mk,v 1.2 2015/06/14 21:02:46 wiz Exp $

--- build/lua-detect.mk.orig	2015-06-13 14:37:26.000000000 +0000
+++ build/lua-detect.mk
@@ -15,20 +15,12 @@
 
 LUA_VERSIONS_CANDIDATES = $(or $(LUA_VERSION),5.2 5.1 5.0)
 
-LUA_PKG := $(firstword $(foreach ver,$(LUA_VERSIONS_CANDIDATES),$(shell \
-       ($(PKG_CONFIG) --exists lua-$(ver)     && echo lua-$(ver)) \
-    || ($(PKG_CONFIG) --exists lua$(ver:5.0=) && echo lua$(ver:5.0=)))))
-
-ifeq ($(LUA_PKG),)
-    $(error Could not find $(or $(LUA_VERSION),any) lua version. (Did you install the -dev package?))
-endif
-
 LUA_VERSION ?= $(or $(shell $(PKG_CONFIG) --variable=V $(LUA_PKG)),5.0)
 
 # prior to 5.1 the lib didn't include version in name.
-LUA_SUFFIX := $(if $(findstring $(LUA_VERSION),5.0),,$(LUA_VERSION))
+LUA_SUFFIX := 
 
-LUA_LIBS     := $(or $(shell $(PKG_CONFIG) --libs $(LUA_PKG)), $(error "pkg-config couldn't find linker flags for lua$(LUA_SUFFIX)!"))
-LUA_INCLUDES := $(shell $(PKG_CONFIG) --cflags $(LUA_PKG))
+LUA_LIBS     := $(or $(shell $(PKG_CONFIG) --libs lua), $(error "pkg-config couldn't find linker flags for lua!"))
+LUA_INCLUDES := $(shell $(PKG_CONFIG) --cflags lua)
 LUA          := $(or $(shell which lua$(LUA_SUFFIX)),          $(shell which lua),  $(error No lua$(LUA_SUFFIX) interpreter found!))
 LUAC         := $(or $(shell which luac$(LUA_SUFFIX)),         $(shell which luac), $(error No lua$(LUA_SUFFIX) compiler found!))
