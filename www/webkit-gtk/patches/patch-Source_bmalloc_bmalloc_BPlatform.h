$NetBSD: patch-Source_bmalloc_bmalloc_BPlatform.h,v 1.1 2018/10/24 18:31:07 leot Exp $

Add BOS(SOLARIS) definition.

--- Source/bmalloc/bmalloc/BPlatform.h.orig	2018-07-25 11:56:32.000000000 +0000
+++ Source/bmalloc/bmalloc/BPlatform.h
@@ -48,6 +48,10 @@
 #define BOS_LINUX 1
 #endif
 
+#ifdef __sun
+#define BOS_SOLARIS 1
+#endif
+
 #if defined(WIN32) || defined(_WIN32)
 #define BOS_WINDOWS 1
 #endif
