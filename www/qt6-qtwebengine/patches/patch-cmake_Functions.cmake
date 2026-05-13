$NetBSD: patch-cmake_Functions.cmake,v 1.3 2026/05/13 05:31:25 adam Exp $

* Based on OpenBSD's qt6-qtwebengine patches, and
  pkgsrc's qt5-qtwebengine patches

--- cmake/Functions.cmake.orig	2026-05-08 07:54:08.000000000 +0000
+++ cmake/Functions.cmake
@@ -103,7 +103,7 @@ function(add_linker_options target build
     set(ldir_rsp "${buildDir}/${ninjaTarget}_ldir.rsp")
     set(lflags_rsp "${buildDir}/${ninjaTarget}_lflags.rsp")
     set_target_properties(${cmakeTarget} PROPERTIES STATIC_LIBRARY_OPTIONS "@${objects_rsp}")
-    if(LINUX OR ANDROID)
+    if(UNIX OR ANDROID)
          get_gn_arch(cpu ${TEST_architecture_arch})
 
          #QTBUG-145054#
