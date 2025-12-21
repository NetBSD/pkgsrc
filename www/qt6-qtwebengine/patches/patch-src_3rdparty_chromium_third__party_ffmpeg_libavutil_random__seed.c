$NetBSD: patch-src_3rdparty_chromium_third__party_ffmpeg_libavutil_random__seed.c,v 1.1 2025/12/21 09:38:42 markd Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- src/3rdparty/chromium/third_party/ffmpeg/libavutil/random_seed.c.orig	2024-12-17 17:58:49.000000000 +0000
+++ src/3rdparty/chromium/third_party/ffmpeg/libavutil/random_seed.c
@@ -20,6 +20,10 @@
 
 #include "config.h"
 
+#if defined(__NetBSD__)
+#define _NETBSD_SOURCE 1
+#endif
+
 #if HAVE_UNISTD_H
 #include <unistd.h>
 #endif
@@ -35,6 +39,11 @@
 #elif CONFIG_OPENSSL
 #include <openssl/rand.h>
 #endif
+#if HAVE_ARC4RANDOM_BUF
+#undef __BSD_VISIBLE
+#define __BSD_VISIBLE 1
+#include <stdlib.h>
+#endif
 #include <fcntl.h>
 #include <math.h>
 #include <time.h>
