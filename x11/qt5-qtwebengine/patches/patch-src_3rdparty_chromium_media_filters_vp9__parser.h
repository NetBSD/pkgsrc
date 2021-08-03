$NetBSD: patch-src_3rdparty_chromium_media_filters_vp9__parser.h,v 1.1 2021/08/03 21:04:35 markd Exp $

--- src/3rdparty/chromium/media/filters/vp9_parser.h.orig	2020-07-08 21:40:45.000000000 +0000
+++ src/3rdparty/chromium/media/filters/vp9_parser.h
@@ -14,6 +14,7 @@
 
 #include <stddef.h>
 #include <stdint.h>
+#include <unistd.h>
 #include <sys/types.h>
 
 #include <memory>
