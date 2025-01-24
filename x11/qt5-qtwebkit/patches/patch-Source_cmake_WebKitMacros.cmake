$NetBSD: patch-Source_cmake_WebKitMacros.cmake,v 1.3 2025/01/24 11:54:38 wiz Exp $

Don't build frameworks on Darwin.

--- Source/cmake/WebKitMacros.cmake.orig	2020-03-04 17:16:37.000000000 +0000
+++ Source/cmake/WebKitMacros.cmake
@@ -285,7 +285,7 @@ macro(WEBKIT_FRAMEWORK _target)
         add_custom_command(TARGET ${_target} POST_BUILD COMMAND ${${_target}_POST_BUILD_COMMAND} VERBATIM)
     endif ()
 
-    if (APPLE AND NOT PORT STREQUAL "GTK" AND NOT ${${_target}_LIBRARY_TYPE} MATCHES STATIC)
+    if (FALSE AND NOT PORT STREQUAL "GTK" AND NOT ${${_target}_LIBRARY_TYPE} MATCHES STATIC)
         set_target_properties(${_target} PROPERTIES FRAMEWORK TRUE)
         if (${_target}_PUBLIC_HEADERS)
             set_target_properties(${_target} PROPERTIES PUBLIC_HEADER "${${_target}_PUBLIC_HEADERS}")
