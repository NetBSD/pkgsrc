$NetBSD: patch-Source_WebKit_PlatformGTK.cmake,v 1.1 2018/05/16 18:55:45 jperkin Exp $

SunOS ld does not support --version-script.

--- Source/WebKit/PlatformGTK.cmake.orig	2018-04-10 07:33:13.000000000 +0000
+++ Source/WebKit/PlatformGTK.cmake
@@ -24,7 +24,7 @@ add_definitions(-DLOCALEDIR="${CMAKE_INS
 add_definitions(-DLIBDIR="${LIB_INSTALL_DIR}")
 add_definitions(-DDATADIR="${CMAKE_INSTALL_FULL_DATADIR}")
 
-if (NOT DEVELOPER_MODE AND NOT CMAKE_SYSTEM_NAME MATCHES "Darwin")
+if (NOT DEVELOPER_MODE AND NOT CMAKE_SYSTEM_NAME MATCHES "Darwin" AND NOT CMAKE_SYSTEM_NAME MATCHES "SunOS")
     WEBKIT_ADD_TARGET_PROPERTIES(WebKit LINK_FLAGS "-Wl,--version-script,${CMAKE_CURRENT_SOURCE_DIR}/webkitglib-symbols.map")
 endif ()
 
