$NetBSD: patch-src_3rdparty_chromium_media_ffmpeg_ffmpeg__regression__tests.cc,v 1.1 2025/02/23 18:59:28 markd Exp $

fix for ffmpeg7 - from ArchLinux

--- src/3rdparty/chromium/media/ffmpeg/ffmpeg_regression_tests.cc.orig	2023-11-09 12:02:51.000000000 +0000
+++ src/3rdparty/chromium/media/ffmpeg/ffmpeg_regression_tests.cc
@@ -86,16 +86,16 @@ FFMPEG_TEST_CASE(Cr47761, "crbug47761.og
 FFMPEG_TEST_CASE(Cr50045, "crbug50045.mp4", PIPELINE_OK, PIPELINE_OK);
 FFMPEG_TEST_CASE(Cr62127, "crbug62127.webm", PIPELINE_OK, PIPELINE_OK);
 FFMPEG_TEST_CASE(Cr93620, "security/93620.ogg", PIPELINE_OK, PIPELINE_OK);
-FFMPEG_TEST_CASE(Cr100492,
-                 "security/100492.webm",
-                 DECODER_ERROR_NOT_SUPPORTED,
-                 DECODER_ERROR_NOT_SUPPORTED);
+FFMPEG_TEST_CASE(Cr100492, "security/100492.webm", PIPELINE_OK, PIPELINE_OK);
 FFMPEG_TEST_CASE(Cr100543, "security/100543.webm", PIPELINE_OK, PIPELINE_OK);
 FFMPEG_TEST_CASE(Cr101458,
                  "security/101458.webm",
                  PIPELINE_ERROR_DECODE,
                  PIPELINE_ERROR_DECODE);
-FFMPEG_TEST_CASE(Cr108416, "security/108416.webm", PIPELINE_OK, PIPELINE_OK);
+FFMPEG_TEST_CASE(Cr108416,
+                 "security/108416.webm",
+                 PIPELINE_ERROR_DECODE,
+                 PIPELINE_ERROR_DECODE);
 FFMPEG_TEST_CASE(Cr110849,
                  "security/110849.mkv",
                  DEMUXER_ERROR_COULD_NOT_OPEN,
@@ -150,7 +150,10 @@ FFMPEG_TEST_CASE(Cr234630b,
                  "security/234630b.mov",
                  DEMUXER_ERROR_NO_SUPPORTED_STREAMS,
                  DEMUXER_ERROR_NO_SUPPORTED_STREAMS);
-FFMPEG_TEST_CASE(Cr242786, "security/242786.webm", PIPELINE_OK, PIPELINE_OK);
+FFMPEG_TEST_CASE(Cr242786,
+                 "security/242786.webm",
+                 PIPELINE_OK,
+                 PIPELINE_ERROR_DECODE);
 // Test for out-of-bounds access with slightly corrupt file (detection logic
 // thinks it's a MONO file, but actually contains STEREO audio).
 FFMPEG_TEST_CASE(Cr275590,
@@ -371,8 +374,8 @@ FFMPEG_TEST_CASE(WEBM_2,
                  DEMUXER_ERROR_NO_SUPPORTED_STREAMS);
 FFMPEG_TEST_CASE(WEBM_4,
                  "security/out.webm.68798.1929",
-                 DECODER_ERROR_NOT_SUPPORTED,
-                 DECODER_ERROR_NOT_SUPPORTED);
+                 PIPELINE_OK,
+                 PIPELINE_OK);
 FFMPEG_TEST_CASE(WEBM_5, "frame_size_change.webm", PIPELINE_OK, PIPELINE_OK);
 
 // General MKV test cases.
