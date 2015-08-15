$NetBSD: patch-Source_cmake_OptionsCommon.cmake,v 1.1 2015/08/15 15:34:32 leot Exp $

Using the T option of GNU ar lead to malformed .a archive on NetBSD. Disable it.

--- Source/cmake/OptionsCommon.cmake.orig	2015-08-06 08:21:28.000000000 +0000
+++ Source/cmake/OptionsCommon.cmake
@@ -17,10 +17,10 @@ endif ()
 
 execute_process(COMMAND ${CMAKE_AR} -V OUTPUT_VARIABLE AR_VERSION)
 if ("${AR_VERSION}" MATCHES "^GNU ar")
-    set(CMAKE_CXX_ARCHIVE_CREATE "<CMAKE_AR> cruT <TARGET> <LINK_FLAGS> <OBJECTS>")
-    set(CMAKE_C_ARCHIVE_CREATE "<CMAKE_AR> cruT <TARGET> <LINK_FLAGS> <OBJECTS>")
-    set(CMAKE_CXX_ARCHIVE_APPEND "<CMAKE_AR> ruT <TARGET> <LINK_FLAGS> <OBJECTS>")
-    set(CMAKE_C_ARCHIVE_APPEND "<CMAKE_AR> ruT <TARGET> <LINK_FLAGS> <OBJECTS>")
+    set(CMAKE_CXX_ARCHIVE_CREATE "<CMAKE_AR> cru <TARGET> <LINK_FLAGS> <OBJECTS>")
+    set(CMAKE_C_ARCHIVE_CREATE "<CMAKE_AR> cru <TARGET> <LINK_FLAGS> <OBJECTS>")
+    set(CMAKE_CXX_ARCHIVE_APPEND "<CMAKE_AR> ru <TARGET> <LINK_FLAGS> <OBJECTS>")
+    set(CMAKE_C_ARCHIVE_APPEND "<CMAKE_AR> ru <TARGET> <LINK_FLAGS> <OBJECTS>")
 endif ()
 
 set_property(GLOBAL PROPERTY USE_FOLDERS ON)
