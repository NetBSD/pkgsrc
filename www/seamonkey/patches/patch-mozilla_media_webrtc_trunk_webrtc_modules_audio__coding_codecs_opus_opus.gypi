$NetBSD: patch-mozilla_media_webrtc_trunk_webrtc_modules_audio__coding_codecs_opus_opus.gypi,v 1.1 2014/03/30 04:13:17 ryoon Exp $

--- mozilla/media/webrtc/trunk/webrtc/modules/audio_coding/codecs/opus/opus.gypi.orig	2014-03-19 01:42:08.000000000 +0000
+++ mozilla/media/webrtc/trunk/webrtc/modules/audio_coding/codecs/opus/opus.gypi
@@ -14,9 +14,9 @@
       'conditions': [
         ['build_with_mozilla==1', {
           # Mozilla provides its own build of the opus library.
-          'include_dirs': [
-            '$(DIST)/include/opus',
-           ]
+          'cflags_mozilla': [
+            '$(MOZ_OPUS_CFLAGS)',
+          ],
         }, {
           'dependencies': [
             '<(DEPTH)/third_party/opus/opus.gyp:opus'
