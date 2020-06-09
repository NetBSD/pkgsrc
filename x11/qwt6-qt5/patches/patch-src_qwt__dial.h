$NetBSD: patch-src_qwt__dial.h,v 1.1 2020/06/09 07:01:55 mef Exp $

Fix missing QPainterPath

--- src/qwt_dial.h.orig	2019-01-02 16:21:30.356438480 +0000
+++ src/qwt_dial.h
@@ -15,6 +15,7 @@
 #include "qwt_abstract_scale_draw.h"
 #include <qframe.h>
 #include <qpalette.h>
+#include <QPainterPath>
 
 class QwtDialNeedle;
 class QwtRoundScaleDraw;
