$NetBSD: patch-media_webrtc_trunk_webrtc_modules_video__capture_video__capture.gypi,v 1.11 2017/04/27 01:49:47 ryoon Exp $

--- media/webrtc/trunk/webrtc/modules/video_capture/video_capture.gypi.orig	2017-04-11 04:15:17.000000000 +0000
+++ media/webrtc/trunk/webrtc/modules/video_capture/video_capture.gypi
@@ -7,6 +7,9 @@
 # be found in the AUTHORS file in the root of the source tree.
 
 {
+  'variables': {
+     'use_libv4l2%': 0,
+  },
   'targets': [
     {
       # Note this library is missing an implementation for the video capture.
@@ -76,6 +79,19 @@
                 'linux/video_capture_linux.cc',
                 'linux/video_capture_linux.h',
               ],
+              'conditions': [
+                ['use_libv4l2==1', {
+                  'defines': [
+                    'HAVE_LIBV4L2',
+                  ],
+                  'cflags_mozilla': [
+                    '$(MOZ_LIBV4L2_CFLAGS)',
+                  ],
+                  'libraries': [
+                    '-lv4l2',
+                  ],
+                }],
+              ],
             }],
             ['OS=="mac"', {
               'sources': [
