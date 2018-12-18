$NetBSD: patch-src_corelib_global_qconfig-bootstrapped.h,v 1.3 2018/12/18 09:57:18 adam Exp $

SunOS does not have getauxval.

--- src/corelib/global/qconfig-bootstrapped.h.orig	2018-12-03 11:15:26.000000000 +0000
+++ src/corelib/global/qconfig-bootstrapped.h
@@ -80,7 +80,11 @@
 #define QT_FEATURE_datestring 1
 #define QT_FEATURE_datetimeparser -1
 #define QT_FEATURE_etw -1
+#ifdef __sun
+# define QT_FEATURE_getauxval -1
+#else
 #define QT_FEATURE_getauxval (QT_HAS_INCLUDE(<sys/auxv.h>) ? 1 : -1)
+#endif
 #define QT_FEATURE_getentropy -1
 #define QT_NO_GEOM_VARIANT
 #define QT_FEATURE_iconv -1
