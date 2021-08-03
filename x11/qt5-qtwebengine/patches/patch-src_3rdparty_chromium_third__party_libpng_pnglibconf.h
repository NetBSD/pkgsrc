$NetBSD: patch-src_3rdparty_chromium_third__party_libpng_pnglibconf.h,v 1.1 2021/08/03 21:04:36 markd Exp $

--- src/3rdparty/chromium/third_party/libpng/pnglibconf.h.orig	2020-07-15 18:56:31.000000000 +0000
+++ src/3rdparty/chromium/third_party/libpng/pnglibconf.h
@@ -230,8 +230,10 @@
  * This is necessary to build multiple copies of libpng.  We need this while pdfium builds
  * its own copy of libpng.
  */
+#if 0
 #define PNG_PREFIX
 #include "pngprefix.h"
+#endif
 /* end of chromium prefixing */
 
 #endif /* PNGLCONF_H */
