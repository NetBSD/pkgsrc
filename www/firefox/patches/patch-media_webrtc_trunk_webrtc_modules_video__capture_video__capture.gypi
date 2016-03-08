$NetBSD: patch-media_webrtc_trunk_webrtc_modules_video__capture_video__capture.gypi,v 1.8 2016/03/08 21:32:52 ryoon Exp $

--- media/webrtc/trunk/webrtc/modules/video_capture/video_capture.gypi.orig	2016-02-25 23:02:07.000000000 +0000
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
@@ -64,8 +67,32 @@
             'video_capture_module',
             '<(webrtc_root)/common.gyp:webrtc_common',
           ],
-	  'cflags_mozilla': [
-	    '$(NSPR_CFLAGS)',
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
+        }],  # linux
+        ['OS=="mac"', {
+          'sources': [
+            'mac/qtkit/video_capture_qtkit.h',
+            'mac/qtkit/video_capture_qtkit.mm',
+            'mac/qtkit/video_capture_qtkit_info.h',
+            'mac/qtkit/video_capture_qtkit_info.mm',
+            'mac/qtkit/video_capture_qtkit_info_objc.h',
+            'mac/qtkit/video_capture_qtkit_info_objc.mm',
+            'mac/qtkit/video_capture_qtkit_objc.h',
+            'mac/qtkit/video_capture_qtkit_objc.mm',
+            'mac/qtkit/video_capture_qtkit_utility.h',
+            'mac/video_capture_mac.mm',
           ],
           'conditions': [
            ['include_v4l2_video_capture==1', {
