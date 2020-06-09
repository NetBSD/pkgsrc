$NetBSD: patch-src_qwt__painter.h,v 1.1 2020/06/09 07:01:55 mef Exp $

Add missing QPainterPath

--- src/qwt_painter.h.orig	2019-01-02 16:21:30.232435482 +0000
+++ src/qwt_painter.h
@@ -17,6 +17,7 @@
 #include <qpen.h>
 #include <qline.h>
 #include <qpalette.h>
+#include <QPainterPath>
 
 class QPainter;
 class QBrush;
