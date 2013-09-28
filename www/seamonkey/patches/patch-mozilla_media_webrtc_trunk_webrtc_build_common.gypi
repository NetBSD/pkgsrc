$NetBSD: patch-mozilla_media_webrtc_trunk_webrtc_build_common.gypi,v 1.3 2013/09/28 14:37:05 ryoon Exp $

--- mozilla/media/webrtc/trunk/webrtc/build/common.gypi.orig	2013-09-16 18:26:50.000000000 +0000
+++ mozilla/media/webrtc/trunk/webrtc/build/common.gypi
@@ -71,9 +71,9 @@
     'enable_data_logging%': 0,
 
     # Disable these to not build components which can be externally provided.
-    'build_libjpeg%': 1,
+    'build_libjpeg%': 0,
     'build_libyuv%': 1,
-    'build_libvpx%': 1,
+    'build_libvpx%': 0,
 
     # Enable to use the Mozilla internal settings.
     'build_with_mozilla%': 0,
@@ -238,7 +238,7 @@
       }],
       ['OS=="dragonfly" or OS=="netbsd"', {
         'defines': [
-          # doesn't support pthread_condattr_setclock
+          # doesn't support pthread_condattr_setclock, NetBSD 6 supports it.
           'WEBRTC_CLOCK_TYPE_REALTIME',
         ],
       }],
