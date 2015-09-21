$NetBSD: patch-mozilla_media_webrtc_trunk_webrtc_modules_video__capture_video__capture.gypi,v 1.4 2015/09/21 05:03:45 ryoon Exp $

--- mozilla/media/webrtc/trunk/webrtc/modules/video_capture/video_capture.gypi.orig	2015-09-02 09:27:28.000000000 +0000
+++ mozilla/media/webrtc/trunk/webrtc/modules/video_capture/video_capture.gypi
@@ -7,6 +7,9 @@
 # be found in the AUTHORS file in the root of the source tree.
 
 {
+  'variables': {
+     'use_libv4l2%': 0,
+  },
   'targets': [
     {
       # Note this library is missing an implementation for the video capture.
@@ -69,6 +72,19 @@
             'linux/video_capture_linux.cc',
             'linux/video_capture_linux.h',
           ],
+          'conditions': [
+            ['use_libv4l2==1', {
+              'defines': [
+                'HAVE_LIBV4L2',
+              ],
+              'cflags_mozilla': [
+                '$(MOZ_LIBV4L2_CFLAGS)',
+              ],
+              'libraries': [
+                '-lv4l2',
+              ],
+            }],
+          ],
         }],  # linux
         ['OS=="mac"', {
           'sources': [
