$NetBSD: patch-lib_kpty.cpp,v 1.2 2020/04/23 04:11:19 gutteridge Exp $

Allow the package to build on NetBSD and macOS.
https://github.com/lxqt/qtermwidget/pull/338

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
@@ -174,14 +180,12 @@ KPtyPrivate::~KPtyPrivate()
 {
 }
 
-#ifndef HAVE_OPENPTY
 bool KPtyPrivate::chownpty(bool)
 {
 //    return !QProcess::execute(KStandardDirs::findExe("kgrantpty"),
 //        QStringList() << (grant?"--grant":"--revoke") << QString::number(masterFd));
     return true;
 }
-#endif
 
 /////////////////////////////
 // public member functions //
