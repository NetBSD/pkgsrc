$NetBSD: patch-qtquick1_tests_auto_declarative_qdeclarativeimage_tst__qdeclarativeimage.cpp,v 1.1 2013/12/13 14:38:35 ryoon Exp $

* Teat NetBSD like Linux

--- qtquick1/tests/auto/declarative/qdeclarativeimage/tst_qdeclarativeimage.cpp.orig	2013-11-27 01:00:25.000000000 +0000
+++ qtquick1/tests/auto/declarative/qdeclarativeimage/tst_qdeclarativeimage.cpp
@@ -384,7 +384,7 @@ void tst_qdeclarativeimage::svg()
     QCOMPARE(obj->pixmap().height(), 300);
     QCOMPARE(obj->width(), 300.0);
     QCOMPARE(obj->height(), 300.0);
-#if defined(Q_OS_LINUX)
+#if defined(Q_OS_LINUX) || defined(OS_NETBSD)
     QCOMPARE(obj->pixmap(), QPixmap(SRCDIR "/data/heart.png"));
 #elif defined(Q_OS_WIN32)
     QCOMPARE(obj->pixmap(), QPixmap(SRCDIR "/data/heart-win32.png"));
@@ -396,7 +396,7 @@ void tst_qdeclarativeimage::svg()
     QCOMPARE(obj->pixmap().height(), 200);
     QCOMPARE(obj->width(), 200.0);
     QCOMPARE(obj->height(), 200.0);
-#if defined(Q_OS_LINUX)
+#if defined(Q_OS_LINUX) || defined(OS_NETBSD)
     QCOMPARE(obj->pixmap(), QPixmap(SRCDIR "/data/heart200.png"));
 #elif defined(Q_OS_WIN32)
     QCOMPARE(obj->pixmap(), QPixmap(SRCDIR "/data/heart200-win32.png"));
