$NetBSD: patch-Source_cmake_WebKitCommon.cmake,v 1.2 2022/05/29 17:47:15 leot Exp $

- Fix support for arm
- Fix support for ppc, from FreeBSD.

--- Source/cmake/WebKitCommon.cmake.orig	2022-02-23 08:59:06.000000000 +0000
+++ Source/cmake/WebKitCommon.cmake
@@ -88,7 +88,7 @@ if (NOT HAS_RUN_WEBKIT_COMMON)
     endif ()
     if (LOWERCASE_CMAKE_SYSTEM_PROCESSOR MATCHES "(^aarch64|^arm64|^cortex-?[am][2-7][2-8])")
         set(WTF_CPU_ARM64 1)
-    elseif (LOWERCASE_CMAKE_SYSTEM_PROCESSOR MATCHES "(^arm|^cortex)")
+    elseif (LOWERCASE_CMAKE_SYSTEM_PROCESSOR MATCHES "(^arm|^cortex|^earm)")
         set(WTF_CPU_ARM 1)
     elseif (LOWERCASE_CMAKE_SYSTEM_PROCESSOR MATCHES "^mips64")
         set(WTF_CPU_MIPS64 1)
@@ -106,9 +106,9 @@ if (NOT HAS_RUN_WEBKIT_COMMON)
         endif ()
     elseif (LOWERCASE_CMAKE_SYSTEM_PROCESSOR MATCHES "(i[3-6]86|x86)")
         set(WTF_CPU_X86 1)
-    elseif (LOWERCASE_CMAKE_SYSTEM_PROCESSOR MATCHES "ppc")
+    elseif (LOWERCASE_CMAKE_SYSTEM_PROCESSOR MATCHES "(ppc|powerpc)")
         set(WTF_CPU_PPC 1)
-    elseif (LOWERCASE_CMAKE_SYSTEM_PROCESSOR MATCHES "ppc64")
+    elseif (LOWERCASE_CMAKE_SYSTEM_PROCESSOR MATCHES "(ppc64|powerpc64)")
         set(WTF_CPU_PPC64 1)
     elseif (LOWERCASE_CMAKE_SYSTEM_PROCESSOR MATCHES "ppc64le")
         set(WTF_CPU_PPC64LE 1)
