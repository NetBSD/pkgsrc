$NetBSD: patch-Source_WebKit_PlatformGTK.cmake,v 1.2 2018/10/24 18:31:07 leot Exp $

SunOS ld does not support --version-script.

--- Source/WebKit/PlatformGTK.cmake.orig	2018-08-21 16:06:11.000000000 +0000
+++ Source/WebKit/PlatformGTK.cmake
@@ -22,7 +22,7 @@ add_definitions(-DPKGLIBEXECDIR="${LIBEX
 add_definitions(-DLOCALEDIR="${CMAKE_INSTALL_FULL_LOCALEDIR}")
 add_definitions(-DLIBDIR="${LIB_INSTALL_DIR}")
 
-if (NOT DEVELOPER_MODE AND NOT CMAKE_SYSTEM_NAME MATCHES "Darwin")
+if (NOT DEVELOPER_MODE AND NOT CMAKE_SYSTEM_NAME MATCHES "Darwin" AND NOT CMAKE_SYSTEM_NAME MATCHES "SunOS")
     WEBKIT_ADD_TARGET_PROPERTIES(WebKit LINK_FLAGS "-Wl,--version-script,${CMAKE_CURRENT_SOURCE_DIR}/webkitglib-symbols.map")
 endif ()
 
