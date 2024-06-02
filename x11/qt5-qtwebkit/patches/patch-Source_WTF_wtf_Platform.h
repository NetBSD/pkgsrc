$NetBSD: patch-Source_WTF_wtf_Platform.h,v 1.5 2024/06/02 12:26:24 ryoon Exp $

* Use system's malloc for NetBSD, do not use fastmalloc from qt5,
  fix segfault of qtwebkit consumers

* Disable DISASSEMBLER on Linux. Unresolved symbols as not building
  UDis86Disassembler.cpp for some reason.

* Fix build with ICU 75.
  From: https://github.com/qtwebkit/qtwebkit/commit/756e1c8f23dc2720471298281c421c0076d02df8.patch

--- Source/WTF/wtf/Platform.h.orig	2024-06-02 11:06:38.219855486 +0000
+++ Source/WTF/wtf/Platform.h
@@ -686,6 +686,12 @@
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
@@ -741,6 +747,10 @@
 #define USE_UDIS86 1
 #endif
 
+#if OS(LINUX)
+#define ENABLE_DISASSEMBLER 0
+#endif
+
 #if !defined(ENABLE_DISASSEMBLER) && USE(UDIS86)
 #define ENABLE_DISASSEMBLER 1
 #endif
@@ -1125,6 +1135,13 @@
 #define ENABLE_PLATFORM_FONT_LOOKUP 1
 #endif
 
+/* FIXME: This does not belong in Platform.h and should instead be included in another mechanism (compiler option, prefix header, config.h, etc) */
+/* ICU configuration. Some of these match ICU defaults on some platforms, but we would like them consistently set everywhere we build WebKit. */
+#define U_SHOW_CPLUSPLUS_API 0
+#ifdef __cplusplus
+#define UCHAR_TYPE char16_t
+#endif
+
 #if COMPILER(MSVC)
 #undef __STDC_LIMIT_MACROS
 #define __STDC_LIMIT_MACROS
