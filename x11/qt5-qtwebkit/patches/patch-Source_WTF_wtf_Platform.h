$NetBSD: patch-Source_WTF_wtf_Platform.h,v 1.3 2018/01/17 19:37:33 markd Exp $

* Disable JIT support for NetBSD, fix segfault of qtwebkit consumers
* Use system's malloc for NetBSD, do not use fastmalloc from qt5,
  fix segfault of qtwebkit consumers

* Disable DISASSEMBLER on Linux. Unresolved symbols as not building
  UDis86Disassembler.cpp for some reason.

--- Source/WTF/wtf/Platform.h.orig	2017-06-04 20:16:06.000000000 +0000
+++ Source/WTF/wtf/Platform.h
@@ -36,6 +36,9 @@
    macros, policy decision macros, and top-level port definitions. ==== */
 #define PLATFORM(WTF_FEATURE) (defined WTF_PLATFORM_##WTF_FEATURE  && WTF_PLATFORM_##WTF_FEATURE)
 
+#if defined(__NetBSD__)
+#define ENABLE_JIT 0
+#endif
 
 /* ==== Platform adaptation macros: these describe properties of the target environment. ==== */
 
@@ -691,6 +694,12 @@
 #define USE_SYSTEM_MALLOC 1
 #endif
 
+/* Workaround an issue with fastMalloc on NetBSD */
+#if OS(NETBSD)
+#define USE_SYSTEM_MALLOC 1
+#define ENABLE_ASSEMBLER 1
+#endif
+
 #define ENABLE_DEBUG_WITH_BREAKPOINT 0
 #define ENABLE_SAMPLING_COUNTERS 0
 #define ENABLE_SAMPLING_FLAGS 0
@@ -746,6 +754,10 @@
 #define USE_UDIS86 1
 #endif
 
+#if OS(LINUX)
+#define ENABLE_DISASSEMBLER 0
+#endif
+
 #if !defined(ENABLE_DISASSEMBLER) && USE(UDIS86)
 #define ENABLE_DISASSEMBLER 1
 #endif
