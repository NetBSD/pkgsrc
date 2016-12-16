$NetBSD: patch-src_3rdparty_webkit_Source_WebCore_html_HTMLImageElement.cpp,v 1.1 2016/12/16 00:06:46 joerg Exp $

Don't order pointers relative to 0.

--- src/3rdparty/webkit/Source/WebCore/html/HTMLImageElement.cpp.orig	2016-12-10 21:49:53.391056357 +0000
+++ src/3rdparty/webkit/Source/WebCore/html/HTMLImageElement.cpp
@@ -74,7 +74,7 @@ PassRefPtr<HTMLImageElement> HTMLImageEl
     RefPtr<HTMLImageElement> image = adoptRef(new HTMLImageElement(imgTag, document));
     if (optionalWidth)
         image->setWidth(*optionalWidth);
-    if (optionalHeight > 0)
+    if (optionalHeight)
         image->setHeight(*optionalHeight);
     return image.release();
 }
