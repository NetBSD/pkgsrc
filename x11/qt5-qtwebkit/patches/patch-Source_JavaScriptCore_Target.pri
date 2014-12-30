$NetBSD: patch-Source_JavaScriptCore_Target.pri,v 1.1 2014/12/30 17:23:47 adam Exp $

* Libtoolized
* Build as shared library
* Install libJavaScriptCore library
* Make conditionals for Unix

--- Source/JavaScriptCore/Target.pri.orig	2014-09-11 10:48:22.000000000 +0000
+++ Source/JavaScriptCore/Target.pri
@@ -13,7 +13,9 @@ WEBKIT += wtf
 QT += core
 QT -= gui
 
-CONFIG += staticlib optimize_full
+CONFIG += optimize_full
+target.path = $$[QT_INSTALL_LIBS]
+INSTALLS += target
 
 # Rules when JIT enabled (not disabled)
 !contains(DEFINES, ENABLE_JIT=0) {
@@ -326,7 +328,7 @@ SOURCES += \
     tools/CodeProfiling.cpp \
     yarr/YarrJIT.cpp \
 
-linux-*:if(isEqual(QT_ARCH, "i386")|isEqual(QT_ARCH, "x86_64")) {
+unix-*:if(isEqual(QT_ARCH, "i386")|isEqual(QT_ARCH, "x86_64")) {
     SOURCES += \
         disassembler/UDis86Disassembler.cpp \
         disassembler/udis86/udis86.c \
