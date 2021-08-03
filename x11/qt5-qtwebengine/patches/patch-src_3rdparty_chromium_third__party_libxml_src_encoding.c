$NetBSD: patch-src_3rdparty_chromium_third__party_libxml_src_encoding.c,v 1.1 2021/08/03 21:04:36 markd Exp $

Fix building with ICU 68.1.

--- src/3rdparty/chromium/third_party/libxml/src/encoding.c.orig	2020-11-07 01:22:36.000000000 +0000
+++ src/3rdparty/chromium/third_party/libxml/src/encoding.c
@@ -48,6 +48,11 @@
 #include "buf.h"
 #include "enc.h"
 
+#if !defined(FALSE)
+# define FALSE (1 == 0)
+# define TRUE (! FALSE)
+#endif
+
 static xmlCharEncodingHandlerPtr xmlUTF16LEHandler = NULL;
 static xmlCharEncodingHandlerPtr xmlUTF16BEHandler = NULL;
 
