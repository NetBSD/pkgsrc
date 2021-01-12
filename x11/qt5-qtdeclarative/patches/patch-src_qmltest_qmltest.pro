$NetBSD: patch-src_qmltest_qmltest.pro,v 1.1 2021/01/12 16:46:45 jperkin Exp $

Workaround linking issue on SunOS.

--- src/qmltest/qmltest.pro.orig	2020-10-27 08:02:12.000000000 +0000
+++ src/qmltest/qmltest.pro
@@ -6,6 +6,8 @@ DEFINES += QT_NO_URL_CAST_FROM_STRING QT
 QT = core testlib-private
 QT_PRIVATE = quick quick-private qml-private gui core-private
 
+solaris-*:LIBS += -mimpure-text
+
 # Testlib is only a private dependency, which results in our users not
 # inheriting testlibs's MODULE_CONFIG transitively. Make it explicit.
 MODULE_CONFIG += $${QT.testlib.CONFIG}
