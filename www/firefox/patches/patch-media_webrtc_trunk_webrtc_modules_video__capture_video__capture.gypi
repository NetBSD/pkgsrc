$NetBSD: patch-media_webrtc_trunk_webrtc_modules_video__capture_video__capture.gypi,v 1.1 2013/05/23 13:12:13 ryoon Exp $

--- media/webrtc/trunk/webrtc/modules/video_capture/video_capture.gypi.orig	2013-05-11 19:19:45.000000000 +0000
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
@@ -48,7 +51,17 @@
           ],
         }, {  # include_internal_video_capture == 1
           'conditions': [
-            ['OS=="linux"', {
+            ['include_v4l2_video_capture==1', {
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
@@ -157,7 +170,7 @@
             'test/video_capture_main_mac.mm',
           ],
           'conditions': [
-            ['OS=="mac" or OS=="linux"', {
+            ['OS!="win" and OS!="android"', {
               'cflags': [
                 '-Wno-write-strings',
               ],
@@ -165,13 +178,17 @@
                 '-lpthread -lm',
               ],
             }],
-            ['OS=="linux"', {
+            ['include_v4l2_video_capture==1', {
               'libraries': [
-                '-lrt',
                 '-lXext',
                 '-lX11',
               ],
             }],
+            ['OS=="linux"', {
+              'libraries': [
+                '-lrt',
+              ],
+            }],
             ['OS=="mac"', {
               'dependencies': [
                 # Link with a special main for mac so we can use the webcam.
