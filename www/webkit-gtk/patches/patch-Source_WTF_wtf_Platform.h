$NetBSD: patch-Source_WTF_wtf_Platform.h,v 1.7 2015/09/26 10:16:38 leot Exp $

--- Source/WTF/wtf/Platform.h.orig	2015-09-21 07:29:46.000000000 +0000
+++ Source/WTF/wtf/Platform.h
@@ -667,6 +667,11 @@
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
