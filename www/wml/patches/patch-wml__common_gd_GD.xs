$NetBSD: patch-wml__common_gd_GD.xs,v 1.1 2014/08/19 13:45:04 joerg Exp $

--- wml_common/gd/GD.xs.orig	2014-08-18 20:50:16.000000000 +0000
+++ wml_common/gd/GD.xs
@@ -49,7 +49,7 @@ gdpng(image)
 	void*         data;
 	data = (void *) gdImagePngPtr(image,&size);
 #else
-	const char*   data = '\0';
+	const char*   data = NULL;
         size = 1;
 croak("libgd was compiled without support of the PNG image format");
 #endif
