$NetBSD: patch-Source_cmake_OptionsCommon.cmake,v 1.7 2022/10/08 11:06:35 nia Exp $

Using the T option of GNU ar lead to malformed .a archive on NetBSD. Disable it.

Add option to avoid use of builtin __int128_t type due to PR toolchain/57022

--- Source/cmake/OptionsCommon.cmake.orig	2022-06-30 09:49:38.479512200 +0000
+++ Source/cmake/OptionsCommon.cmake
@@ -128,10 +128,10 @@ endif ()
 option(USE_THIN_ARCHIVES "Produce all static libraries as thin archives" ${USE_THIN_ARCHIVES_DEFAULT})
 
 if (USE_THIN_ARCHIVES)
-    set(CMAKE_CXX_ARCHIVE_CREATE "<CMAKE_AR> crT <TARGET> <LINK_FLAGS> <OBJECTS>")
-    set(CMAKE_C_ARCHIVE_CREATE "<CMAKE_AR> crT <TARGET> <LINK_FLAGS> <OBJECTS>")
-    set(CMAKE_CXX_ARCHIVE_APPEND "<CMAKE_AR> rT <TARGET> <LINK_FLAGS> <OBJECTS>")
-    set(CMAKE_C_ARCHIVE_APPEND "<CMAKE_AR> rT <TARGET> <LINK_FLAGS> <OBJECTS>")
+    set(CMAKE_CXX_ARCHIVE_CREATE "<CMAKE_AR> cr <TARGET> <LINK_FLAGS> <OBJECTS>")
+    set(CMAKE_C_ARCHIVE_CREATE "<CMAKE_AR> cr <TARGET> <LINK_FLAGS> <OBJECTS>")
+    set(CMAKE_CXX_ARCHIVE_APPEND "<CMAKE_AR> r <TARGET> <LINK_FLAGS> <OBJECTS>")
+    set(CMAKE_C_ARCHIVE_APPEND "<CMAKE_AR> r <TARGET> <LINK_FLAGS> <OBJECTS>")
 endif ()
 
 set(ENABLE_DEBUG_FISSION_DEFAULT OFF)
@@ -219,12 +219,18 @@ WEBKIT_CHECK_HAVE_STRUCT(HAVE_STAT_BIRTH
 WEBKIT_CHECK_HAVE_STRUCT(HAVE_TM_GMTOFF "struct tm" tm_gmtoff time.h)
 WEBKIT_CHECK_HAVE_STRUCT(HAVE_TM_ZONE "struct tm" tm_zone time.h)
 
+option(AVOID_INT128 "Avoid using compiler builtin __int128_t type" OFF)
+
+if (NOT AVOID_INT128)
 # Check for int types
 check_type_size("__int128_t" INT128_VALUE)
 
 if (HAVE_INT128_VALUE)
   SET_AND_EXPOSE_TO_BUILD(HAVE_INT128_T INT128_VALUE)
 endif ()
+else ()
+  SET_AND_EXPOSE_TO_BUILD(HAVE_INT128_T FALSE)
+endif ()
 
 # Check which filesystem implementation is available if any
 if (STD_FILESYSTEM_IS_AVAILABLE)
