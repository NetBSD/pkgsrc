$NetBSD: patch-Source_WTF_wtf_Platform.h,v 1.11 2018/10/01 21:45:31 jperkin Exp $

Avoid flock() on SunOS, not supported on older platforms.

--- Source/WTF/wtf/Platform.h.orig	2018-02-20 09:12:50.000000000 +0000
+++ Source/WTF/wtf/Platform.h
@@ -533,8 +533,10 @@
 #define USE_HARFBUZZ 1
 #define USE_SOUP 1
 #define USE_WEBP 1
+#ifndef __sun
 #define USE_FILE_LOCK 1
 #endif
+#endif
 
 #if PLATFORM(GTK)
 #define GLIB_VERSION_MIN_REQUIRED GLIB_VERSION_2_36
