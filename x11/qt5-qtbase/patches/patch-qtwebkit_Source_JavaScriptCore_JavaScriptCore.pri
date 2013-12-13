$NetBSD: patch-qtwebkit_Source_JavaScriptCore_JavaScriptCore.pri,v 1.1 2013/12/13 14:38:35 ryoon Exp $

* Make conditional for Unix

--- qtwebkit/Source/JavaScriptCore/JavaScriptCore.pri.orig	2013-11-27 01:01:48.000000000 +0000
+++ qtwebkit/Source/JavaScriptCore/JavaScriptCore.pri
@@ -41,6 +41,6 @@ wince* {
     INCLUDEPATH += $$SOURCE_DIR/os-win32
 }
 
-linux-*:if(isEqual(QT_ARCH, "i386")|isEqual(QT_ARCH, "x86_64")) {
+unix-*:if(isEqual(QT_ARCH, "i386")|isEqual(QT_ARCH, "x86_64")) {
     INCLUDEPATH += $$SOURCE_DIR/disassembler/udis86
 }
