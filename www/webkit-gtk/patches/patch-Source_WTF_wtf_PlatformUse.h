$NetBSD: patch-Source_WTF_wtf_PlatformUse.h,v 1.1 2020/03/10 18:14:04 leot Exp $

Avoid flock() on SunOS, not supported on older platforms.

--- Source/WTF/wtf/PlatformUse.h.orig	2020-02-04 10:24:07.000000000 +0000
+++ Source/WTF/wtf/PlatformUse.h
@@ -87,7 +87,7 @@
 #define USE_CF 1
 #endif
 
-#if PLATFORM(COCOA) || (PLATFORM(GTK) || PLATFORM(WPE))
+#if (PLATFORM(COCOA) || (PLATFORM(GTK) || PLATFORM(WPE))) && !OS(SOLARIS)
 #define USE_FILE_LOCK 1
 #endif
 
