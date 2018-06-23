$NetBSD: patch-sip_QtTest_qtestmouse.sip,v 1.1 2018/06/23 17:49:36 wiz Exp $

Fix build with Qt 5.11, which removed this symbol.

--- sip/QtTest/qtestmouse.sip.orig	2018-02-27 10:43:53.000000000 +0000
+++ sip/QtTest/qtestmouse.sip
@@ -41,7 +41,6 @@ namespace QTest
     void mousePress(QWidget *widget, Qt::MouseButton button, Qt::KeyboardModifiers modifier = 0, QPoint pos = QPoint(), int delay = -1);
     void mouseRelease(QWidget *widget, Qt::MouseButton button, Qt::KeyboardModifiers modifier = 0, QPoint pos = QPoint(), int delay = -1);
     void mouseEvent(QTest::MouseAction action, QWidget *widget, Qt::MouseButton button, Qt::KeyboardModifiers modifier, QPoint pos, int delay = -1);
-    void waitForEvents() /ReleaseGIL/;
     void mouseEvent(QTest::MouseAction action, QWindow *window, Qt::MouseButton button, Qt::KeyboardModifiers modifier, QPoint pos, int delay = -1);
     void mousePress(QWindow *window, Qt::MouseButton button, Qt::KeyboardModifiers modifier = Qt::KeyboardModifiers(), QPoint pos = QPoint(), int delay = -1);
     void mouseRelease(QWindow *window, Qt::MouseButton button, Qt::KeyboardModifiers modifier = Qt::KeyboardModifiers(), QPoint pos = QPoint(), int delay = -1);
