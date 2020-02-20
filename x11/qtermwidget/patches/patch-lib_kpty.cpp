$NetBSD: patch-lib_kpty.cpp,v 1.1 2020/02/20 05:47:44 gutteridge Exp $

Allow the package to build on NetBSD.

--- lib/kpty.cpp.orig	2019-02-25 22:13:12.000000000 +0000
+++ lib/kpty.cpp
@@ -27,7 +27,7 @@
 #include <QtDebug>
 
 
-#if defined(__FreeBSD__) || defined(__NetBSD__) || defined(__DragonFly__)
+#if defined(__FreeBSD__) || defined(__DragonFly__)
 #define HAVE_LOGIN
 #define HAVE_LIBUTIL_H
 #endif
@@ -37,6 +37,12 @@
 #define HAVE_UTIL_H
 #endif
 
+#if defined(__NetBSD__)
+#define HAVE_LOGIN
+#define HAVE_UTIL_H
+#define HAVE_OPENPTY
+#endif
+
 #if defined(__APPLE__)
 #define HAVE_OPENPTY
 #define HAVE_UTIL_H
@@ -174,7 +180,7 @@ KPtyPrivate::~KPtyPrivate()
 {
 }
 
-#ifndef HAVE_OPENPTY
+#ifndef __APPLE__
 bool KPtyPrivate::chownpty(bool)
 {
 //    return !QProcess::execute(KStandardDirs::findExe("kgrantpty"),
