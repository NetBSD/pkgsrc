$NetBSD: patch-media_webrtc_trunk_webrtc_build_common.gypi,v 1.2 2013/06/26 11:32:12 ryoon Exp $

--- media/webrtc/trunk/webrtc/build/common.gypi.orig	2013-06-17 22:13:20.000000000 +0000
+++ media/webrtc/trunk/webrtc/build/common.gypi
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
@@ -124,6 +124,11 @@
         # and Java Implementation
         'enable_android_opensl%': 0,
       }],
+      ['OS=="linux" or OS=="solaris" or os_bsd==1', {
+        'include_v4l2_video_capture%': 1,
+      }, {
+        'include_v4l2_video_capture%': 0,
+      }],
       ['OS=="ios"', {
         'enable_video%': 0,
         'enable_protobuf%': 0,
@@ -215,6 +220,18 @@
           }],
         ],
       }],
+      ['os_bsd==1', {
+        'defines': [
+          'WEBRTC_BSD',
+          'WEBRTC_THREAD_RR',
+        ],
+      }],
+      ['OS=="dragonfly" or OS=="netbsd"', {
+        'defines': [
+          # doesn't support pthread_condattr_setclock
+          'WEBRTC_CLOCK_TYPE_REALTIME',
+        ],
+      }],
       ['OS=="ios"', {
         'defines': [
           'WEBRTC_MAC',
