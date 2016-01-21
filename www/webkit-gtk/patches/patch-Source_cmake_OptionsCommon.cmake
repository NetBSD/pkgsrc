$NetBSD: patch-Source_cmake_OptionsCommon.cmake,v 1.3 2016/01/21 13:42:33 leot Exp $

Using the T option of GNU ar lead to malformed .a archive on NetBSD. Disable it.

--- Source/cmake/OptionsCommon.cmake.orig	2016-01-20 12:13:00.000000000 +0000
+++ Source/cmake/OptionsCommon.cmake
@@ -17,10 +17,10 @@ endif ()
 
 execute_process(COMMAND ${CMAKE_AR} -V OUTPUT_VARIABLE AR_VERSION)
 if ("${AR_VERSION}" MATCHES "^GNU ar")
-    set(CMAKE_CXX_ARCHIVE_CREATE "<CMAKE_AR> crT <TARGET> <LINK_FLAGS> <OBJECTS>")
-    set(CMAKE_C_ARCHIVE_CREATE "<CMAKE_AR> crT <TARGET> <LINK_FLAGS> <OBJECTS>")
-    set(CMAKE_CXX_ARCHIVE_APPEND "<CMAKE_AR> rT <TARGET> <LINK_FLAGS> <OBJECTS>")
-    set(CMAKE_C_ARCHIVE_APPEND "<CMAKE_AR> rT <TARGET> <LINK_FLAGS> <OBJECTS>")
+    set(CMAKE_CXX_ARCHIVE_CREATE "<CMAKE_AR> cr <TARGET> <LINK_FLAGS> <OBJECTS>")
+    set(CMAKE_C_ARCHIVE_CREATE "<CMAKE_AR> cr <TARGET> <LINK_FLAGS> <OBJECTS>")
+    set(CMAKE_CXX_ARCHIVE_APPEND "<CMAKE_AR> r <TARGET> <LINK_FLAGS> <OBJECTS>")
+    set(CMAKE_C_ARCHIVE_APPEND "<CMAKE_AR> r <TARGET> <LINK_FLAGS> <OBJECTS>")
 endif ()
 
 set_property(GLOBAL PROPERTY USE_FOLDERS ON)
