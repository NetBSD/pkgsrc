$NetBSD: patch-awesomeConfig.cmake,v 1.2.6.1 2014/04/08 22:30:27 tron Exp $

--- awesomeConfig.cmake.orig	2013-04-01 11:44:46.000000000 +0000
+++ awesomeConfig.cmake	2013-07-21 21:05:57.000000000 +0000
@@ -16,7 +16,7 @@
 option(GENERATE_DOC "generate API documentation" ON)
 
 # {{{ CFLAGS
-add_definitions(-O1 -std=gnu99 -ggdb3 -rdynamic -fno-strict-aliasing -Wall -Wextra
+add_definitions(-O1 -std=gnu99 -rdynamic -fno-strict-aliasing -Wall -Wextra
     -Wchar-subscripts -Wundef -Wshadow -Wcast-align -Wwrite-strings
     -Wsign-compare -Wunused -Wno-unused-parameter -Wuninitialized -Winit-self
     -Wpointer-arith -Wformat-nonliteral
@@ -153,7 +153,7 @@
 endif()
 
 macro(a_find_library variable library)
-    find_library(${variable} ${library})
+    find_library(${variable} ${library} @LIBEV_PREFIX@/lib/ev)
     if(NOT ${variable})
         message(FATAL_ERROR ${library} " library not found.")
     endif()
