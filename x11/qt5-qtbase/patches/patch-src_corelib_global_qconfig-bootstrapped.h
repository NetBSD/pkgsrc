$NetBSD: patch-src_corelib_global_qconfig-bootstrapped.h,v 1.4 2020/01/21 20:25:37 adam Exp $

SunOS does not have getauxval.

--- src/corelib/global/qconfig-bootstrapped.h.orig	2019-12-07 06:27:07.000000000 +0000
+++ src/corelib/global/qconfig-bootstrapped.h
@@ -81,7 +81,11 @@
 #define QT_FEATURE_datetimeparser -1
 #define QT_FEATURE_easingcurve -1
 #define QT_FEATURE_etw -1
+#ifdef __sun
+# define QT_FEATURE_getauxval -1
+#else
 #define QT_FEATURE_getauxval (QT_HAS_INCLUDE(<sys/auxv.h>) ? 1 : -1)
+#endif
 #define QT_FEATURE_getentropy -1
 #define QT_NO_GEOM_VARIANT
 #define QT_FEATURE_hijricalendar -1
