$NetBSD: patch-src_qwt__global.h,v 1.1 2020/06/09 07:01:55 mef Exp $

Fix missing QPainterPath

--- src/qwt_global.h.orig	2019-01-02 16:21:30.380439061 +0000
+++ src/qwt_global.h
@@ -11,6 +11,8 @@
 #define QWT_GLOBAL_H
 
 #include <qglobal.h>
+#include <QPainterPath>
+
 
 // QWT_VERSION is (major << 16) + (minor << 8) + patch.
 
