$NetBSD: patch-src_corelib_global_qconfig-bootstrapped.h,v 1.1 2018/01/31 12:36:57 jperkin Exp $

SunOS does not have getauxval.

--- src/corelib/global/qconfig-bootstrapped.h.orig	2017-11-30 13:49:46.000000000 +0000
+++ src/corelib/global/qconfig-bootstrapped.h
@@ -78,7 +78,11 @@
 #define QT_FEATURE_cxx11_random (QT_HAS_INCLUDE(<random>) ? 1 : -1)
 #define QT_NO_DATASTREAM
 #define QT_FEATURE_datetimeparser -1
+#ifdef __sun
+# define QT_FEATURE_getauxval -1
+#else
 #define QT_FEATURE_getauxval (QT_HAS_INCLUDE(<sys/auxv.h>) ? 1 : -1)
+#endif
 #define QT_FEATURE_getentropy -1
 #define QT_NO_GEOM_VARIANT
 #define QT_FEATURE_iconv -1
