$NetBSD: patch-qtscript_src_3rdparty_javascriptcore_JavaScriptCore_config.h,v 1.1 2013/12/13 14:38:35 ryoon Exp $

* Add DragonFly support

--- qtscript/src/3rdparty/javascriptcore/JavaScriptCore/config.h.orig	2013-11-27 01:00:27.000000000 +0000
+++ qtscript/src/3rdparty/javascriptcore/JavaScriptCore/config.h
@@ -53,7 +53,7 @@
 
 #endif
 
-#if OS(FREEBSD) || OS(OPENBSD)
+#if OS(FREEBSD) || OS(OPENBSD) || OS(DRAGONFLY)
 #define HAVE_PTHREAD_NP_H 1
 #endif
 
