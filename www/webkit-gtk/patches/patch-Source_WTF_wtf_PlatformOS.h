$NetBSD: patch-Source_WTF_wtf_PlatformOS.h,v 1.1 2020/03/10 18:14:04 leot Exp $

Add OS(SOLARIS) definition and add them to Unix systems.

--- Source/WTF/wtf/PlatformOS.h.orig	2020-02-04 10:24:07.000000000 +0000
+++ Source/WTF/wtf/PlatformOS.h
@@ -114,6 +114,11 @@
 #define WTF_OS_OPENBSD 1
 #endif
 
+/* OS(SOLARIS) - Solaris and derivatives */
+#ifdef __sun
+#define WTF_OS_SOLARIS 1
+#endif
+
 /* OS(WINDOWS) - Any version of Windows */
 #if defined(WIN32) || defined(_WIN32)
 #define WTF_OS_WINDOWS 1
@@ -129,6 +134,7 @@
     || OS(LINUX)            \
     || OS(NETBSD)           \
     || OS(OPENBSD)          \
+    || OS(SOLARIS)          \
     || defined(unix)        \
     || defined(__unix)      \
     || defined(__unix__)
