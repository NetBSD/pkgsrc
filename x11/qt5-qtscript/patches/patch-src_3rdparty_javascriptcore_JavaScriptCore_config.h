$NetBSD: patch-src_3rdparty_javascriptcore_JavaScriptCore_config.h,v 1.1 2014/12/30 17:23:47 adam Exp $

* Add DragonFly support

--- src/3rdparty/javascriptcore/JavaScriptCore/config.h.orig	2013-11-27 01:00:27.000000000 +0000
+++ src/3rdparty/javascriptcore/JavaScriptCore/config.h
@@ -53,7 +53,7 @@
 
 #endif
 
-#if OS(FREEBSD) || OS(OPENBSD)
+#if OS(FREEBSD) || OS(OPENBSD) || OS(DRAGONFLY)
 #define HAVE_PTHREAD_NP_H 1
 #endif
 
