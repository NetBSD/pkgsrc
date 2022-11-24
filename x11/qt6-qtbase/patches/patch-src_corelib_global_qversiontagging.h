$NetBSD: patch-src_corelib_global_qversiontagging.h,v 1.1 2022/11/24 11:11:38 nros Exp $

* remove redefine warnings when QT_NO_VERSION_TAGGING is defined

--- src/corelib/global/qversiontagging.h.orig	2022-10-23 21:39:46.764900043 +0000
+++ src/corelib/global/qversiontagging.h
@@ -73,7 +73,7 @@ struct QVersionTag
 };
 }
 
-#if defined(QT_BUILD_CORE_LIB) || defined(QT_BOOTSTRAPPED) || defined(QT_STATIC)
+#if !defined(QT_NO_VERSION_TAGGING) && (defined(QT_BUILD_CORE_LIB) || defined(QT_BOOTSTRAPPED) || defined(QT_STATIC))
 // don't make tags in QtCore, bootstrapped systems or if the user asked not to
 #  define QT_NO_VERSION_TAGGING
 #endif
