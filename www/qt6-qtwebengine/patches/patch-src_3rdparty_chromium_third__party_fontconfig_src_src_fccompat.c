$NetBSD: patch-src_3rdparty_chromium_third__party_fontconfig_src_src_fccompat.c,v 1.2 2026/04/30 06:39:43 adam Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- src/3rdparty/chromium/third_party/fontconfig/src/src/fccompat.c.orig	2026-03-16 11:40:07.000000000 +0000
+++ src/3rdparty/chromium/third_party/fontconfig/src/src/fccompat.c
@@ -175,7 +175,9 @@ FcRandom (void)
 {
     int32_t result;
 
-#if HAVE_RANDOM_R
+#if HAVE_ARC4RANDOM
+    result = arc4random() & 0x7fffffff;
+#elif HAVE_RANDOM_R
     static struct random_data fcrandbuf;
     static char               statebuf[256];
     static FcBool             initialized = FcFalse;
