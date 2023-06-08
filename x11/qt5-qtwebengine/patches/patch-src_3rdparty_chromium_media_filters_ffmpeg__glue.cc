$NetBSD: patch-src_3rdparty_chromium_media_filters_ffmpeg__glue.cc,v 1.1 2023/06/08 20:38:06 markd Exp $

build with ffmpeg5 - from archlinux

--- src/3rdparty/chromium/media/filters/ffmpeg_glue.cc.orig	2022-03-30 09:48:18.000000000 +0000
+++ src/3rdparty/chromium/media/filters/ffmpeg_glue.cc
@@ -59,7 +59,6 @@ static int64_t AVIOSeekOperation(void* o
 }
 
 void FFmpegGlue::InitializeFFmpeg() {
-  av_register_all();
 }
 
 static void LogContainer(bool is_local_file,
@@ -95,9 +94,6 @@ FFmpegGlue::FFmpegGlue(FFmpegURLProtocol
   // Enable fast, but inaccurate seeks for MP3.
   format_context_->flags |= AVFMT_FLAG_FAST_SEEK;
 
-  // Ensures we can read out various metadata bits like vp8 alpha.
-  format_context_->flags |= AVFMT_FLAG_KEEP_SIDE_DATA;
-
   // Ensures format parsing errors will bail out. From an audit on 11/2017, all
   // instances were real failures. Solves bugs like http://crbug.com/710791.
   format_context_->error_recognition |= AV_EF_EXPLODE;
