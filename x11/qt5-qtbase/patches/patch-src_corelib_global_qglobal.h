$NetBSD: patch-src_corelib_global_qglobal.h,v 1.1 2018/04/19 08:23:12 jperkin Exp $

Pull in upstream fix from https://codereview.qt-project.org/#/c/221071

--- src/corelib/global/qglobal.h.orig	2018-02-08 18:24:48.000000000 +0000
+++ src/corelib/global/qglobal.h
@@ -508,7 +508,7 @@ using qsizetype = QIntegerForSizeof<std:
 #  define Q_ALWAYS_INLINE inline
 #endif
 
-#ifdef Q_CC_GNU
+#if defined(Q_CC_GNU) && defined(Q_OS_WIN)
 #  define QT_INIT_METAOBJECT __attribute__((init_priority(101)))
 #else
 #  define QT_INIT_METAOBJECT
