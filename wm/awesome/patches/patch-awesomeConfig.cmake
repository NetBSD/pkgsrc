$NetBSD: patch-awesomeConfig.cmake,v 1.5 2017/08/18 10:16:11 triaxx Exp $

Use pkgsrc lua interpreter instead of builtin one.

--- awesomeConfig.cmake.orig	2017-07-15 13:53:13.000000000 +0000
+++ awesomeConfig.cmake
@@ -40,7 +40,7 @@ a_find_program(XMLTO_EXECUTABLE xmlto FA
 a_find_program(GZIP_EXECUTABLE gzip FALSE)
 # Lua documentation
 if(GENERATE_DOC)
-    a_find_program(LDOC_EXECUTABLE ldoc FALSE)
+    a_find_program(LDOC_EXECUTABLE @LDOC_EXECUTABLE@ FALSE)
     if(NOT LDOC_EXECUTABLE)
         a_find_program(LDOC_EXECUTABLE ldoc.lua FALSE)
     endif()
@@ -361,7 +361,7 @@ file(MAKE_DIRECTORY ${BUILD_DIR}/script_
 
 add_custom_command(
         OUTPUT ${BUILD_DIR}/docs/06-appearance.md
-        COMMAND lua ${SOURCE_DIR}/docs/06-appearance.md.lua
+        COMMAND @LUA_INTERPRETER@ ${SOURCE_DIR}/docs/06-appearance.md.lua
         ${BUILD_DIR}/docs/06-appearance.md
         DEPENDS lgi-check
 )
@@ -369,7 +369,7 @@ add_custom_command(
 add_custom_command(
         OUTPUT ${BUILD_DIR}/awesomerc.lua ${BUILD_DIR}/docs/05-awesomerc.md
             ${BUILD_DIR}/script_files/rc.lua
-        COMMAND lua ${SOURCE_DIR}/docs/05-awesomerc.md.lua
+        COMMAND @LUA_INTERPRETER@ ${SOURCE_DIR}/docs/05-awesomerc.md.lua
         ${BUILD_DIR}/docs/05-awesomerc.md ${SOURCE_DIR}/awesomerc.lua
         ${BUILD_DIR}/awesomerc.lua
         ${BUILD_DIR}/script_files/rc.lua
@@ -377,7 +377,7 @@ add_custom_command(
 
 add_custom_command(
         OUTPUT ${BUILD_DIR}/script_files/theme.lua
-        COMMAND lua ${SOURCE_DIR}/docs/sample_theme.lua ${BUILD_DIR}/script_files/
+        COMMAND @LUA_INTERPRETER@ ${SOURCE_DIR}/docs/sample_theme.lua ${BUILD_DIR}/script_files/
 )
 
 # Create a target for the auto-generated awesomerc.lua and other files
