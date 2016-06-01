$NetBSD: patch-src_libs_3rdparty_net7ssh_src_src.pro,v 1.2 2016/06/01 13:42:08 joerg Exp $

--- src/libs/3rdparty/net7ssh/src/src.pro.orig	2010-08-24 07:46:09.000000000 +0000
+++ src/libs/3rdparty/net7ssh/src/src.pro
@@ -6,7 +6,7 @@ CONFIG += dll
 include(../../../../qtcreatorlibrary.pri)
 
 DEPENDPATH += .
-INCLUDEPATH += $$PWD $$PWD/../../botan $$PWD/../../botan/build
+INCLUDEPATH += $$PWD $(PREFIX)/include/botan-1.10
 
 include(../net7ssh_dependencies.pri)
 
@@ -23,6 +23,8 @@ unix {
     QMAKE_CXXFLAGS += -Wno-unused-parameter
 }
 
+LIBS += -lbotan
+
 # Input
 HEADERS += crypt.h \
         ne7ssh.h \
