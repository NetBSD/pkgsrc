$NetBSD: patch-src_qwt__scale__draw.cpp,v 1.1 2020/06/09 07:01:55 mef Exp $

Fix missing QPainterPath

--- src/qwt_scale_draw.cpp.orig	2019-01-02 16:21:31.400463727 +0000
+++ src/qwt_scale_draw.cpp
@@ -15,6 +15,7 @@
 #include <qpen.h>
 #include <qpainter.h>
 #include <qmath.h>
+#include <QPainterPath>
 
 #if QT_VERSION < 0x040601
 #define qFastSin(x) qSin(x)
