$NetBSD: patch-src_svg_qsvghandler.cpp,v 1.2 2022/04/18 11:18:17 adam Exp $

Fix out of bounds read in function QRadialFetchSimd from crafted svg file.
https://bugreports.qt.io/browse/QTBUG-91507

--- src/svg/qsvghandler.cpp.orig	2021-03-18 12:54:01.000000000 +0000
+++ src/svg/qsvghandler.cpp
@@ -3046,6 +3046,8 @@ static QSvgStyleProperty *createRadialGr
         ncy = toDouble(cy);
     if (!r.isEmpty())
         nr = toDouble(r);
+    if (nr < 0.5)
+        nr = 0.5;
 
     qreal nfx = ncx;
     if (!fx.isEmpty())
