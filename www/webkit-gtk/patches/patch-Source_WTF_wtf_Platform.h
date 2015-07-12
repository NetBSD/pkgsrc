$NetBSD: patch-Source_WTF_wtf_Platform.h,v 1.5 2015/07/12 00:44:46 wiz Exp $

--- Source/WTF/wtf/Platform.h.orig	2015-03-23 08:08:04.000000000 +0000
+++ Source/WTF/wtf/Platform.h
@@ -579,7 +579,7 @@
 #endif
 
 #if !defined(HAVE_STRNSTR)
-#if OS(DARWIN) || (OS(FREEBSD) && !defined(__GLIBC__))
+#if OS(DARWIN) || ((OS(FREEBSD) || OS(NETBSD)) && !defined(__GLIBC__))
 #define HAVE_STRNSTR 1
 #endif
 #endif
@@ -632,6 +632,11 @@
 #define USE_SYSTEM_MALLOC 1
 #endif
 
+/* Workaround an alignment issue with fastMalloc on NetBSD/arm */
+#if OS(NETBSD) && CPU(ARM)
+#define USE_SYSTEM_MALLOC 1
+#endif
+
 #define ENABLE_DEBUG_WITH_BREAKPOINT 0
 #define ENABLE_SAMPLING_COUNTERS 0
 #define ENABLE_SAMPLING_FLAGS 0
