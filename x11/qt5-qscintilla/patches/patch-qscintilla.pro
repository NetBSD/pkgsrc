$NetBSD: patch-qscintilla.pro,v 1.1 2020/03/08 20:55:17 brook Exp $

Add full path to installed library names on Darwin.

--- qscintilla.pro.orig	2019-06-25 12:49:27.000000000 +0000
+++ qscintilla.pro
@@ -95,6 +95,10 @@ CONFIG(staticlib) {
 }
 INSTALLS += features
 
+mac {
+    QMAKE_SONAME_PREFIX=$$target.path
+}
+
 HEADERS = \
 	./Qsci/qsciglobal.h \
 	./Qsci/qsciscintilla.h \
