$NetBSD: patch-media_webrtc_trunk_webrtc_modules_video__capture_video__capture.gypi,v 1.5 2014/10/05 01:59:08 ryoon Exp $

--- media/webrtc/trunk/webrtc/modules/video_capture/video_capture.gypi.orig	2014-09-24 01:05:32.000000000 +0000
+++ media/webrtc/trunk/webrtc/modules/video_capture/video_capture.gypi
@@ -7,6 +7,9 @@
 # be found in the AUTHORS file in the root of the source tree.
 
 {
+  'variables': {
+     'use_libv4l2%': 0,
+  },
   'targets': [
     {
       'target_name': 'video_capture_module',
@@ -46,6 +49,16 @@
                 'linux/video_capture_linux.cc',
                 'linux/video_capture_linux.h',
               ],
+              'conditions': [
+                ['use_libv4l2==1', {
+                  'defines': [
+                    'HAVE_LIBV4L2',
+                  ],
+                  'libraries': [
+                    '-lv4l2',
+                  ],
+                }],
+              ],
             }],  # linux
             ['OS=="mac"', {
               'sources': [
