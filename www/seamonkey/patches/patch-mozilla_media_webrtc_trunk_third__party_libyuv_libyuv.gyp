$NetBSD: patch-mozilla_media_webrtc_trunk_third__party_libyuv_libyuv.gyp,v 1.2 2013/07/12 12:24:10 ryoon Exp $

--- mozilla/media/webrtc/trunk/third_party/libyuv/libyuv.gyp.orig	2013-06-20 04:35:15.000000000 +0000
+++ mozilla/media/webrtc/trunk/third_party/libyuv/libyuv.gyp
@@ -58,6 +58,11 @@
         }],
       ],
       'conditions': [
+        ['yuv_disable_asm==1', {
+          'defines': [
+            'YUV_DISABLE_ASM',
+          ],
+        }],
         ['build_with_mozilla==1', {
           'include_dirs': [
             '$(DEPTH)/dist/include',
