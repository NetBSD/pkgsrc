$NetBSD: patch-cmake_QtToolchainHelpers.cmake,v 1.1 2025/12/21 09:38:12 markd Exp $

add OPENBSD, NETBSD
is_gcc valid for all UNIX types

--- cmake/QtToolchainHelpers.cmake.orig	2025-05-29 01:27:28.000000000 +0000
+++ cmake/QtToolchainHelpers.cmake
@@ -91,6 +91,10 @@ function(get_gn_os result)
         set(${result} "win" PARENT_SCOPE)
     elseif(LINUX)
         set(${result} "linux" PARENT_SCOPE)
+    elseif(OPENBSD)
+        set(${result} "openbsd" PARENT_SCOPE)
+    elseif(NETBSD)
+        set(${result} "netbsd" PARENT_SCOPE)
     elseif(MACOS)
         set(${result} "mac" PARENT_SCOPE)
     elseif(IOS)
@@ -354,7 +358,7 @@ macro(append_compiler_linker_sdk_setup)
     extend_gn_list(gnArgArg ARGS is_clang CONDITION CLANG)
     extend_gn_list(gnArgArg ARGS is_mingw CONDITION MINGW)
     extend_gn_list(gnArgArg ARGS is_msvc CONDITION MSVC)
-    extend_gn_list(gnArgArg ARGS is_gcc CONDITION LINUX AND CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
+    extend_gn_list(gnArgArg ARGS is_gcc CONDITION UNIX AND CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
 
     if(CLANG)
         if(MACOS)
@@ -548,7 +552,7 @@ macro(append_toolchain_setup)
         endif()
         unset(host_cpu)
         unset(target_cpu)
-    elseif(LINUX)
+    elseif(UNIX)
         get_gn_arch(cpu ${TEST_architecture_arch})
         list(APPEND gnArgArg
             custom_toolchain="${buildDir}/target_toolchain:target"
