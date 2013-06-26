$NetBSD: patch-media_webrtc_webrtc__config.gypi,v 1.2 2013/06/26 11:32:12 ryoon Exp $

--- media/webrtc/webrtc_config.gypi.orig	2013-06-17 22:13:21.000000000 +0000
+++ media/webrtc/webrtc_config.gypi
@@ -14,7 +14,6 @@
     'include_internal_video_render': 0,
     'clang_use_chrome_plugins': 0,
     'enable_protobuf': 0,
-    'include_pulse_audio': 0,
     'include_tests': 0,
     'enable_android_opensl': 1,
 # use_system_lib* still seems to be in use in trunk/build
