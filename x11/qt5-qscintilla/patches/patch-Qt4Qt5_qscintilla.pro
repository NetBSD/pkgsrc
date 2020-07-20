$NetBSD: patch-Qt4Qt5_qscintilla.pro,v 1.2 2020/07/20 17:09:15 adam Exp $

Add full path to installed library names on Darwin.

--- Qt4Qt5/qscintilla.pro.orig	2020-06-09 14:28:23.000000000 +0000
+++ Qt4Qt5/qscintilla.pro
@@ -38,7 +38,7 @@ CONFIG(debug, debug|release) {
 }
 
 macx:!CONFIG(staticlib) {
-    QMAKE_POST_LINK += install_name_tool -id @rpath/$(TARGET1) $(TARGET)
+    QMAKE_POST_LINK += install_name_tool -id $$[QT_INSTALL_LIBS]/$(TARGET1) $(TARGET)
 }
 
 INCLUDEPATH += . ../include ../lexlib ../src
