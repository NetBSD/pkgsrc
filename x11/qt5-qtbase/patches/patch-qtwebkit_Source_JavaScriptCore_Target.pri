$NetBSD: patch-qtwebkit_Source_JavaScriptCore_Target.pri,v 1.1 2013/12/13 14:38:35 ryoon Exp $

* Libtoolized
* Build as shared library
* Install libJavaScriptCore library
* Make conditionals for Unix

--- qtwebkit/Source/JavaScriptCore/Target.pri.orig	2013-11-27 01:01:49.000000000 +0000
+++ qtwebkit/Source/JavaScriptCore/Target.pri
@@ -13,14 +13,17 @@ WEBKIT += wtf
 QT += core
 QT -= gui
 
-CONFIG += staticlib
+#CONFIG += staticlib
+
+target.path = $$[QT_INSTALL_LIBS]
+INSTALLS += target
 
 *-g++*:QMAKE_CXXFLAGS_RELEASE -= -O2
 *-g++*:QMAKE_CXXFLAGS_RELEASE += -O3
 
 # Rules when JIT enabled (not disabled)
 !contains(DEFINES, ENABLE_JIT=0) {
-    linux*-g++*:greaterThan(QT_GCC_MAJOR_VERSION,3):greaterThan(QT_GCC_MINOR_VERSION,0) {
+    unix*-g++*:greaterThan(QT_GCC_MAJOR_VERSION,3):greaterThan(QT_GCC_MINOR_VERSION,0) {
         QMAKE_CXXFLAGS += -fno-stack-protector
         QMAKE_CFLAGS += -fno-stack-protector
     }
@@ -329,7 +332,7 @@ SOURCES += \
     tools/CodeProfiling.cpp \
     yarr/YarrJIT.cpp \
 
-linux-*:if(isEqual(QT_ARCH, "i386")|isEqual(QT_ARCH, "x86_64")) {
+unix-*:if(isEqual(QT_ARCH, "i386")|isEqual(QT_ARCH, "x86_64")) {
     SOURCES += \
         disassembler/UDis86Disassembler.cpp \
         disassembler/udis86/udis86.c \
