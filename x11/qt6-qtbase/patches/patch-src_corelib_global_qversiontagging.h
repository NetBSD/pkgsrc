$NetBSD: patch-src_corelib_global_qversiontagging.h,v 1.3 2024/06/10 21:15:17 jperkin Exp $

SunOS linker does not support this version tagging.

--- src/corelib/global/qversiontagging.h.orig	2024-06-10 17:28:45.092935077 +0000
+++ src/corelib/global/qversiontagging.h
@@ -75,7 +75,7 @@ struct QVersionTag
 };
 }
 
-#if !defined(QT_NO_VERSION_TAGGING) && (defined(QT_BUILD_CORE_LIB) || defined(QT_BOOTSTRAPPED) || defined(QT_STATIC))
+#if !defined(QT_NO_VERSION_TAGGING) && (defined(QT_BUILD_CORE_LIB) || defined(QT_BOOTSTRAPPED) || defined(QT_STATIC) || defined(Q_OS_SOLARIS))
 // don't make tags in QtCore, bootstrapped systems or if the user asked not to
 #  define QT_NO_VERSION_TAGGING
 #endif
