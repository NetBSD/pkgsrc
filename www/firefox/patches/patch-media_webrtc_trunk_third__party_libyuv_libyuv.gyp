$NetBSD: patch-media_webrtc_trunk_third__party_libyuv_libyuv.gyp,v 1.2 2013/06/26 11:32:12 ryoon Exp $

--- media/webrtc/trunk/third_party/libyuv/libyuv.gyp.orig	2013-06-17 22:13:19.000000000 +0000
+++ media/webrtc/trunk/third_party/libyuv/libyuv.gyp
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
