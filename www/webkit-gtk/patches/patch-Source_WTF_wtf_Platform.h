$NetBSD: patch-Source_WTF_wtf_Platform.h,v 1.1 2013/08/14 22:16:54 jmcneill Exp $

--- Source/WTF/wtf/Platform.h.orig	2012-11-23 20:12:16.000000000 +0000
+++ Source/WTF/wtf/Platform.h
@@ -484,6 +484,11 @@
 #define USE_SYSTEM_MALLOC 1
 #endif
 
+/* Workaround an alignment issue with fastMalloc on NetBSD/arm */
+#if OS(NETBSD) && CPU(ARM)
+#define USE_SYSTEM_MALLOC 1
+#endif
+
 #if PLATFORM(BLACKBERRY)
 #define WTF_USE_MERSENNE_TWISTER_19937 1
 #define WTF_USE_SKIA 1
