$NetBSD: patch-Source_cmake_WebKitFeatures.cmake,v 1.1 2026/08/30 14:25:06 wiz Exp $

Disabling JIT (performance will be way worse with pages using
JavaScript, but maybe works).
Also try to use system malloc.

--- Source/cmake/WebKitFeatures.cmake.orig	2025-08-08 09:17:56.304456000 +0000
+++ Source/cmake/WebKitFeatures.cmake
@@ -88,7 +88,7 @@ macro(WEBKIT_OPTION_BEGIN)
             set(ENABLE_C_LOOP_DEFAULT ON)
             set(ENABLE_SAMPLING_PROFILER_DEFAULT OFF)
         endif ()
-    elseif (WTF_CPU_ARM64 OR WTF_CPU_X86_64)
+    elseif (WTF_OS_LINUX AND (WTF_CPU_ARM64 OR WTF_CPU_X86_64))
         set(ENABLE_JIT_DEFAULT ON)
         set(ENABLE_FTL_DEFAULT ON)
         set(USE_SYSTEM_MALLOC_DEFAULT OFF)
@@ -106,7 +106,7 @@ macro(WEBKIT_OPTION_BEGIN)
         set(USE_SYSTEM_MALLOC_DEFAULT OFF)
         set(ENABLE_C_LOOP_DEFAULT ON)
         set(ENABLE_SAMPLING_PROFILER_DEFAULT OFF)
-    elseif (WTF_CPU_RISCV64)
+    elseif (WTF_CPU_RISCV64 AND WTF_OS_LINUX)
         set(ENABLE_JIT_DEFAULT ON)
         set(ENABLE_FTL_DEFAULT ON)
         set(USE_SYSTEM_MALLOC_DEFAULT OFF)
