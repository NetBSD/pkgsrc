$NetBSD: patch-media_webrtc_trunk_webrtc_modules_video__capture_video__capture.gypi,v 1.3 2014/02/08 09:36:00 ryoon Exp $

--- media/webrtc/trunk/webrtc/modules/video_capture/video_capture.gypi.orig	2014-01-28 04:03:58.000000000 +0000
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
@@ -47,6 +50,16 @@
         }, {  # include_internal_video_capture == 1
           'conditions': [
             ['include_v4l2_video_capture==1', {
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
               'include_dirs': [
                 'linux',
               ],
