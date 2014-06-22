$NetBSD: patch-mozilla_media_webrtc_trunk_webrtc_build_common.gypi,v 1.5 2014/06/22 08:54:39 ryoon Exp $

--- mozilla/media/webrtc/trunk/webrtc/build/common.gypi.orig	2014-06-13 00:45:43.000000000 +0000
+++ mozilla/media/webrtc/trunk/webrtc/build/common.gypi
@@ -256,7 +256,7 @@
       }],
       ['OS=="dragonfly" or OS=="netbsd"', {
         'defines': [
-          # doesn't support pthread_condattr_setclock
+          # doesn't support pthread_condattr_setclock, NetBSD 6 supports it.
           'WEBRTC_CLOCK_TYPE_REALTIME',
         ],
       }],
