$NetBSD: patch-cmake_QtToolchainHelpers.cmake,v 1.2 2026/04/30 06:39:34 adam Exp $

add OPENBSD, NETBSD
is_gcc valid for all UNIX types

--- cmake/QtToolchainHelpers.cmake.orig	2026-03-16 11:40:07.000000000 +0000
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
@@ -384,7 +388,7 @@ macro(append_compiler_linker_sdk_setup)
     extend_gn_list(gnArgArg ARGS is_clang CONDITION CLANG)
     extend_gn_list(gnArgArg ARGS is_mingw CONDITION MINGW)
     extend_gn_list(gnArgArg ARGS is_msvc CONDITION MSVC)
-    extend_gn_list(gnArgArg ARGS is_gcc CONDITION LINUX AND CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
+    extend_gn_list(gnArgArg ARGS is_gcc CONDITION UNIX AND CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
 
     if(CLANG)
         get_clang_runtime_path_version(clang_runtime_path_version)
@@ -456,7 +460,7 @@ macro(append_compiler_linker_sdk_setup)
         list(APPEND gnArgArg libclang_path="${QWELibClang_LIBRARY_DIR}")
 
         #TODO: This is Linux specific for now.
-        if(LINUX)
+        if(UNIX)
             list(APPEND gnArgArg clang_resource_dir="${QWELibClang_RESOURCE_PATH}")
         endif()
     endif()
@@ -478,7 +482,7 @@ macro(append_compiler_linker_sdk_setup)
         )
     endif()
     get_gn_arch(cpu ${TEST_architecture_arch})
-    if(LINUX AND CMAKE_CROSSCOMPILING AND cpu STREQUAL "arm")
+    if(UNIX AND CMAKE_CROSSCOMPILING AND cpu STREQUAL "arm")
 
         extend_gn_list_cflag(gnArgArg
             ARG arm_tune
@@ -587,7 +591,7 @@ macro(append_toolchain_setup)
         endif()
         unset(host_cpu)
         unset(target_cpu)
-    elseif(LINUX)
+    elseif(UNIX)
         get_gn_arch(cpu ${TEST_architecture_arch})
         list(APPEND gnArgArg
             custom_toolchain="${buildDir}/target_toolchain:target"
