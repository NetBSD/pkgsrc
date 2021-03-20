$NetBSD: patch-src_svg_qsvghandler.cpp,v 1.1 2021/03/20 00:44:01 gutteridge Exp $

Fix out of bounds read in function QRadialFetchSimd from crafted svg file.
https://bugreports.qt.io/browse/QTBUG-91507

--- src/svg/qsvghandler.cpp.orig	2020-10-27 08:02:11.000000000 +0000
+++ src/svg/qsvghandler.cpp
@@ -672,6 +672,9 @@ static qreal toDouble(const QChar *&str)
             val = -val;
     } else {
         val = QByteArray::fromRawData(temp, pos).toDouble();
+        // Do not tolerate values too wild to be represented normally by floats
+        if (std::fpclassify(float(val)) != FP_NORMAL)
+            val = 0;
     }
     return val;
 
@@ -3043,6 +3046,8 @@ static QSvgStyleProperty *createRadialGr
         ncy = toDouble(cy);
     if (!r.isEmpty())
         nr = toDouble(r);
+    if (nr < 0.5)
+        nr = 0.5;
 
     qreal nfx = ncx;
     if (!fx.isEmpty())
