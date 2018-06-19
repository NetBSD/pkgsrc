$NetBSD: patch-src_corelib_global_qconfig-bootstrapped.h,v 1.2 2018/06/19 07:21:23 adam Exp $

SunOS does not have getauxval.

--- src/corelib/global/qconfig-bootstrapped.h.orig	2018-05-14 04:46:28.000000000 +0000
+++ src/corelib/global/qconfig-bootstrapped.h
@@ -79,7 +79,11 @@
 #define QT_NO_DATASTREAM
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
