$NetBSD: patch-media_webrtc_webrtc__config.gypi,v 1.1 2013/05/23 13:12:13 ryoon Exp $

--- media/webrtc/webrtc_config.gypi.orig	2013-05-11 19:19:46.000000000 +0000
+++ media/webrtc/webrtc_config.gypi
@@ -14,7 +14,6 @@
     'include_internal_video_render': 0,
     'clang_use_chrome_plugins': 0,
     'enable_protobuf': 0,
-    'include_pulse_audio': 0,
     'include_tests': 0,
 # use_system_lib* still seems to be in use in trunk/build
     'use_system_libjpeg': 0,
