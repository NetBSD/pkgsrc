$NetBSD: patch-media_webrtc_trunk_webrtc_build_common.gypi,v 1.1 2013/05/23 13:12:13 ryoon Exp $

--- media/webrtc/trunk/webrtc/build/common.gypi.orig	2013-05-11 19:19:44.000000000 +0000
+++ media/webrtc/trunk/webrtc/build/common.gypi
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
@@ -210,6 +215,18 @@
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
