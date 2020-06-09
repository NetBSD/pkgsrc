$NetBSD: patch-src_qwt__painter__command.h,v 1.1 2020/06/09 07:01:55 mef Exp $

Fix missing QPainterPath

--- src/qwt_painter_command.h.orig	2019-01-02 16:21:30.320437610 +0000
+++ src/qwt_painter_command.h
@@ -15,6 +15,7 @@
 #include <qpixmap.h>
 #include <qimage.h>
 #include <qpolygon.h>
+#include <QPainterPath>
 
 class QPainterPath;
 
