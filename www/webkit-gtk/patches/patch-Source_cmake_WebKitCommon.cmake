$NetBSD: patch-Source_cmake_WebKitCommon.cmake,v 1.1 2021/03/30 12:47:42 leot Exp $

- Fix support for arm
- Fix support for ppc, from FreeBSD.

--- Source/cmake/WebKitCommon.cmake.orig	2021-02-26 09:57:17.000000000 +0000
+++ Source/cmake/WebKitCommon.cmake
@@ -84,7 +84,7 @@ if (NOT HAS_RUN_WEBKIT_COMMON)
     endif ()
     if (LOWERCASE_CMAKE_SYSTEM_PROCESSOR MATCHES "(^aarch64|^arm64)")
         set(WTF_CPU_ARM64 1)
-    elseif (LOWERCASE_CMAKE_SYSTEM_PROCESSOR MATCHES "^arm")
+    elseif (LOWERCASE_CMAKE_SYSTEM_PROCESSOR MATCHES "(^arm|^earm)")
         set(WTF_CPU_ARM 1)
     elseif (LOWERCASE_CMAKE_SYSTEM_PROCESSOR MATCHES "^mips64")
         set(WTF_CPU_MIPS64 1)
@@ -102,9 +102,9 @@ if (NOT HAS_RUN_WEBKIT_COMMON)
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
