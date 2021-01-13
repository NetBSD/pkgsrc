$NetBSD: patch-src_icon.cpp,v 1.1 2021/01/13 10:57:48 jperkin Exp $

Explicitly use std::log.

--- src/icon.cpp.orig	2020-05-02 22:20:13.000000000 +0000
+++ src/icon.cpp
@@ -563,7 +563,7 @@ bool Icon::guessMonochrome(const QImage
     while (it != dist.constEnd()) {
         reverseDist.insert(it.value(), it.key());
         qreal probability = qreal(it.value()) / qreal(img.size().width() * img.size().height() - transparentPixels);
-        entropy -= probability * log(probability) / log(255);
+        entropy -= probability * std::log(probability) / std::log(255);
         ++it;
     }
 
