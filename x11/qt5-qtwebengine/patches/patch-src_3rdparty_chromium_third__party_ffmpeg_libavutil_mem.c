$NetBSD: patch-src_3rdparty_chromium_third__party_ffmpeg_libavutil_mem.c,v 1.1 2021/08/03 21:04:36 markd Exp $

--- src/3rdparty/chromium/third_party/ffmpeg/libavutil/mem.c.orig	2020-07-15 19:01:34.000000000 +0000
+++ src/3rdparty/chromium/third_party/ffmpeg/libavutil/mem.c
@@ -32,9 +32,6 @@
 #include <stdint.h>
 #include <stdlib.h>
 #include <string.h>
-#if HAVE_MALLOC_H
-#include <malloc.h>
-#endif
 
 #include "avassert.h"
 #include "avutil.h"
