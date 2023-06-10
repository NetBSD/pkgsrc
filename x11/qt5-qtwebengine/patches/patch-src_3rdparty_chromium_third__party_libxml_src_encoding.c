$NetBSD: patch-src_3rdparty_chromium_third__party_libxml_src_encoding.c,v 1.2 2023/06/10 18:23:07 adam Exp $

Fix building with ICU 68.1.

--- src/3rdparty/chromium/third_party/libxml/src/encoding.c.orig	2022-04-06 13:32:17.000000000 +0000
+++ src/3rdparty/chromium/third_party/libxml/src/encoding.c
@@ -57,6 +57,11 @@ struct _uconv_t {
 };
 #endif
 
+#if !defined(FALSE)
+# define FALSE (1 == 0)
+# define TRUE (! FALSE)
+#endif
+
 static xmlCharEncodingHandlerPtr xmlUTF16LEHandler = NULL;
 static xmlCharEncodingHandlerPtr xmlUTF16BEHandler = NULL;
 
