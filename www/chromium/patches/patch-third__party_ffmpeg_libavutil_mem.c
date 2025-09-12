$NetBSD: patch-third__party_ffmpeg_libavutil_mem.c,v 1.7 2025/09/12 16:02:35 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- third_party/ffmpeg/libavutil/mem.c.orig	2025-09-08 23:21:33.000000000 +0000
+++ third_party/ffmpeg/libavutil/mem.c
@@ -33,9 +33,6 @@
 #include <stdlib.h>
 #include <stdatomic.h>
 #include <string.h>
-#if HAVE_MALLOC_H
-#include <malloc.h>
-#endif
 
 #include "attributes.h"
 #include "avassert.h"
