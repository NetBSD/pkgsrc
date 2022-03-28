$NetBSD: patch-Source_cmake_OptionsCommon.cmake,v 1.1 2022/03/28 23:10:44 tnn Exp $

Make ar(1) flags compatible with SunOS

--- Source/cmake/OptionsCommon.cmake.orig	2020-03-04 17:16:37.000000000 +0000
+++ Source/cmake/OptionsCommon.cmake
@@ -19,10 +19,10 @@ option(USE_THIN_ARCHIVES "Produce all st
 if (USE_THIN_ARCHIVES)
     execute_process(COMMAND ${CMAKE_AR} -V OUTPUT_VARIABLE AR_VERSION)
     if ("${AR_VERSION}" MATCHES "^GNU ar")
-        set(CMAKE_CXX_ARCHIVE_CREATE "<CMAKE_AR> crT <TARGET> <LINK_FLAGS> <OBJECTS>")
-        set(CMAKE_C_ARCHIVE_CREATE "<CMAKE_AR> crT <TARGET> <LINK_FLAGS> <OBJECTS>")
-        set(CMAKE_CXX_ARCHIVE_APPEND "<CMAKE_AR> rT <TARGET> <LINK_FLAGS> <OBJECTS>")
-        set(CMAKE_C_ARCHIVE_APPEND "<CMAKE_AR> rT <TARGET> <LINK_FLAGS> <OBJECTS>")
+        set(CMAKE_CXX_ARCHIVE_CREATE "<CMAKE_AR> crs <TARGET> <LINK_FLAGS> <OBJECTS>")
+        set(CMAKE_C_ARCHIVE_CREATE "<CMAKE_AR> crs <TARGET> <LINK_FLAGS> <OBJECTS>")
+        set(CMAKE_CXX_ARCHIVE_APPEND "<CMAKE_AR> rs <TARGET> <LINK_FLAGS> <OBJECTS>")
+        set(CMAKE_C_ARCHIVE_APPEND "<CMAKE_AR> rs <TARGET> <LINK_FLAGS> <OBJECTS>")
     endif ()
 endif ()
 
