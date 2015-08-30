$NetBSD: patch-Source_WTF_wtf_Platform.h,v 1.2 2015/08/30 09:56:45 markd Exp $

* Disable JIT support for NetBSD, fix segfault of qtwebkit consumers
* Use system's malloc for NetBSD, do not use fastmalloc from qt5,
  fix segfault of qtwebkit consumers

* Disable DISASSEMBLER on Linux. Unresolved symbols as not building
  UDis86Disassembler.cpp for some reason.
--- Source/WTF/wtf/Platform.h.orig	2013-11-27 01:01:21.000000000 +0000
+++ Source/WTF/wtf/Platform.h
@@ -36,6 +36,9 @@
    macros, policy decision macros, and top-level port definitions. ==== */
 #define PLATFORM(WTF_FEATURE) (defined WTF_PLATFORM_##WTF_FEATURE  && WTF_PLATFORM_##WTF_FEATURE)
 
+#if defined(__NetBSD__)
+#define ENABLE_JIT 0
+#endif
 
 /* ==== Platform adaptation macros: these describe properties of the target environment. ==== */
 
@@ -694,6 +697,11 @@
 #endif
 #endif
 
+/* Workaround an issue with fastMalloc on NetBSD */
+#if OS(NETBSD)
+#define USE_SYSTEM_MALLOC 1
+#endif
+
 #if PLATFORM(EFL)
 #define ENABLE_GLOBAL_FASTMALLOC_NEW 0
 #endif
@@ -804,6 +812,10 @@
 #define WTF_USE_ARMV7_DISASSEMBLER 1
 #endif
 
+#if OS(LINUX)
+#define ENABLE_DISASSEMBLER 0
+#endif
+
 #if !defined(ENABLE_DISASSEMBLER) && (USE(UDIS86) || USE(ARMV7_DISASSEMBLER))
 #define ENABLE_DISASSEMBLER 1
 #endif
