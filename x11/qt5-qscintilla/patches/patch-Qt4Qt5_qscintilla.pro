$NetBSD: patch-Qt4Qt5_qscintilla.pro,v 1.1.2.2 2020/07/03 10:29:50 bsiegert Exp $

Add full path to installed library names on Darwin.

--- Qt4Qt5/qscintilla.pro.orig	2020-06-09 14:28:23.000000000 +0000
+++ Qt4Qt5/qscintilla.pro
@@ -38,7 +38,7 @@ CONFIG(debug, debug|release) {
 }
 
 macx:!CONFIG(staticlib) {
-    QMAKE_POST_LINK += install_name_tool -id @rpath/$(TARGET1) $(TARGET)
+    QMAKE_POST_LINK += install_name_tool -id $$target.path/$(TARGET1) $(TARGET)
 }
 
 INCLUDEPATH += . ../include ../lexlib ../src
