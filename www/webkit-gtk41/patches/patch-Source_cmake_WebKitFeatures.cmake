$NetBSD: patch-Source_cmake_WebKitFeatures.cmake,v 1.2 2026/09/22 12:27:03 wiz Exp $

Disabling JIT (performance will be way worse with pages using
JavaScript, but maybe works).
Also try to use system malloc.

--- Source/cmake/WebKitFeatures.cmake.orig	2026-08-06 09:22:31.282348400 +0000
+++ Source/cmake/WebKitFeatures.cmake
@@ -89,7 +89,7 @@ macro(WEBKIT_OPTION_BEGIN)
             set(ENABLE_C_LOOP_DEFAULT ON)
             set(ENABLE_SAMPLING_PROFILER_DEFAULT OFF)
         endif ()
-    elseif (WTF_CPU_ARM64 OR WTF_CPU_X86_64)
+    elseif (WTF_OS_LINUX AND (WTF_CPU_ARM64 OR WTF_CPU_X86_64))
         set(ENABLE_JIT_DEFAULT ON)
         set(ENABLE_FTL_DEFAULT ON)
         set(USE_SYSTEM_MALLOC_DEFAULT OFF)
@@ -110,7 +110,7 @@ macro(WEBKIT_OPTION_BEGIN)
         set(USE_MIMALLOC_DEFAULT ON)
         set(ENABLE_C_LOOP_DEFAULT ON)
         set(ENABLE_SAMPLING_PROFILER_DEFAULT OFF)
-    elseif (WTF_CPU_RISCV64)
+    elseif (WTF_CPU_RISCV64 AND WTF_OS_LINUX)
         set(ENABLE_JIT_DEFAULT ON)
         set(ENABLE_FTL_DEFAULT ON)
         set(USE_SYSTEM_MALLOC_DEFAULT OFF)
