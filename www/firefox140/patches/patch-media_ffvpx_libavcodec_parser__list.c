$NetBSD: patch-media_ffvpx_libavcodec_parser__list.c,v 1.1 2026/04/30 18:51:23 gutteridge Exp $

Fix build failure due to incompatible pointer types.
error: initialization of 'const AVCodecParser *' from incompatible pointer type 'const FFCodecParser *'

--- media/ffvpx/libavcodec/parser_list.c.orig	2026-04-27 16:08:57.000000000 +0000
+++ media/ffvpx/libavcodec/parser_list.c
@@ -1,6 +1,6 @@
 #include "config_components.h"
 
-static const AVCodecParser * const parser_list[] = {
+static const FFCodecParser * const parser_list[] = {
 #if CONFIG_VP8_PARSER
     &ff_vp8_parser,
 #endif
