$NetBSD: patch-mozilla_media_webrtc_trunk_third__party_libyuv_libyuv.gyp,v 1.1 2013/05/23 13:25:30 ryoon Exp $

--- mozilla/media/webrtc/trunk/third_party/libyuv/libyuv.gyp.orig	2013-05-03 03:08:06.000000000 +0000
+++ mozilla/media/webrtc/trunk/third_party/libyuv/libyuv.gyp
@@ -9,6 +9,7 @@
 {
   'variables': {
      'use_system_libjpeg%': 0,
+     'yuv_disable_asm%': 0,
   },
   'targets': [
     {
@@ -50,6 +51,11 @@
         ],
       },
       'conditions': [
+        ['yuv_disable_asm==1', {
+          'defines': [
+            'YUV_DISABLE_ASM',
+          ],
+        }],
         ['build_with_mozilla==1', {
           'include_dirs': [
             '$(DEPTH)/dist/include',
