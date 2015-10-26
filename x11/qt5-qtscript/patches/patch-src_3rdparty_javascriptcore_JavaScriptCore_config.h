$NetBSD: patch-src_3rdparty_javascriptcore_JavaScriptCore_config.h,v 1.2 2015/10/26 19:04:00 adam Exp $

* Add DragonFly support

--- src/3rdparty/javascriptcore/JavaScriptCore/config.h.orig	2015-10-13 04:35:46.000000000 +0000
+++ src/3rdparty/javascriptcore/JavaScriptCore/config.h
@@ -53,7 +53,7 @@
 
 #endif
 
-#if (OS(FREEBSD) || OS(OPENBSD)) && !defined(__GLIBC__)
+#if (OS(FREEBSD) || OS(OPENBSD) || OS(DRAGONFLY)) && !defined(__GLIBC__)
 #define HAVE_PTHREAD_NP_H 1
 #endif
 
