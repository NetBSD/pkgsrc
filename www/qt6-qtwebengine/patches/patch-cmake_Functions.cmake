$NetBSD: patch-cmake_Functions.cmake,v 1.1 2025/12/21 09:38:12 markd Exp $

* Based on OpenBSD's qt6-qtwebengine patches, and
  pkgsrc's qt5-qtwebengine patches

--- cmake/Functions.cmake.orig	2025-05-29 01:27:28.000000000 +0000
+++ cmake/Functions.cmake
@@ -103,7 +103,7 @@ function(add_linker_options target build
     set(libs_rsp "${buildDir}/${ninjaTarget}_libs.rsp")
     set(ldir_rsp "${buildDir}/${ninjaTarget}_ldir.rsp")
     set_target_properties(${cmakeTarget} PROPERTIES STATIC_LIBRARY_OPTIONS "@${objects_rsp}")
-    if(LINUX OR ANDROID)
+    if(UNIX OR ANDROID)
          get_gn_arch(cpu ${TEST_architecture_arch})
          if(CMAKE_CROSSCOMPILING AND cpu STREQUAL "arm" AND ${config} STREQUAL "Debug")
              target_link_options(${cmakeTarget} PRIVATE "LINKER:--long-plt")
