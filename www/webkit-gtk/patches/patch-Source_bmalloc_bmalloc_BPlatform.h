$NetBSD: patch-Source_bmalloc_bmalloc_BPlatform.h,v 1.2 2019/09/10 22:10:04 leot Exp $

Add BOS(SOLARIS) and BOS(NETBSD) definitions.

--- Source/bmalloc/bmalloc/BPlatform.h.orig	2019-08-28 11:46:33.000000000 +0000
+++ Source/bmalloc/bmalloc/BPlatform.h
@@ -48,10 +48,18 @@
 #define BOS_LINUX 1
 #endif
 
+#ifdef __sun
+#define BOS_SOLARIS 1
+#endif
+
 #if defined(__FreeBSD__) || defined(__DragonFly__) || defined(__FreeBSD_kernel__)
 #define BOS_FREEBSD 1
 #endif
 
+#if defined(__NetBSD__)
+#define BOS_NETBSD 1
+#endif
+
 #if defined(WIN32) || defined(_WIN32)
 #define BOS_WINDOWS 1
 #endif
