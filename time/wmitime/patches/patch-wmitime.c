$NetBSD: patch-wmitime.c,v 1.1 2021/08/08 09:40:44 nia Exp $

Remove non-portabile iconv modifier.

--- wmitime.c.orig	2015-08-22 01:42:17.000000000 +0000
+++ wmitime.c
@@ -337,7 +337,7 @@ void DrawDate(void)
     size_t inbytesleft, outbytesleft;
     iconv_t cd;
 
-    cd = iconv_open("ASCII//TRANSLIT", nl_langinfo(CODESET));
+    cd = iconv_open("ASCII", nl_langinfo(CODESET));
 
     inbuf = OrigBlitStr;
     outbuf = BlitStr;
