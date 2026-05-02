$NetBSD: patch-media_ffvpx_libavcodec_parser__list.c,v 1.2.2.2 2026/05/02 19:26:59 bsiegert Exp $

Fix build failure due to incompatible pointer types.
https://github.com/mozilla-firefox/firefox/commit/930757b47bf1ce3522468f384570634032f0500b

--- media/ffvpx/libavcodec/parser_list.c.orig	2026-04-27 16:08:57.000000000 +0000
+++ media/ffvpx/libavcodec/parser_list.c
@@ -1,6 +1,6 @@
 #include "config_components.h"
 
-static const AVCodecParser * const parser_list[] = {
+static const FFCodecParser * const parser_list[] = {
 #if CONFIG_VP8_PARSER
     &ff_vp8_parser,
 #endif
