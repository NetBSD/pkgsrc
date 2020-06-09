$NetBSD: patch-src_qwt__null__paintdevice.cpp,v 1.1 2020/06/09 07:01:55 mef Exp $

Fix missing QPainterPath

--- src/qwt_null_paintdevice.cpp.orig	2019-01-02 16:21:31.296461212 +0000
+++ src/qwt_null_paintdevice.cpp
@@ -10,6 +10,8 @@
 #include "qwt_null_paintdevice.h"
 #include <qpaintengine.h>
 #include <qpixmap.h>
+#include <QPainterPath>
+
 
 class QwtNullPaintDevice::PrivateData
 {
