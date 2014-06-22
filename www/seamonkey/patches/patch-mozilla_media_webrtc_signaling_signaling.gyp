$NetBSD: patch-mozilla_media_webrtc_signaling_signaling.gyp,v 1.3 2014/06/22 08:54:39 ryoon Exp $

--- mozilla/media/webrtc/signaling/signaling.gyp.orig	2014-06-13 00:46:10.000000000 +0000
+++ mozilla/media/webrtc/signaling/signaling.gyp
@@ -825,14 +825,13 @@
             ['OS=="mac"', {
               'defines' : [
                 'SIP_OS_OSX',
-                '_POSIX_SOURCE',
+                # using BSD extensions, leave _POSIX_SOURCE undefined
                 'CPR_MEMORY_LITTLE_ENDIAN',
                 'NO_SOCKET_POLLING',
                 'USE_TIMER_SELECT_BASED',
                 'FULL_BUILD',
                 'STUBBED_OUT',
                 'USE_PRINTF',
-                '_DARWIN_C_SOURCE',
                 'NO_NSPR_10_SUPPORT',
               ],
             }],
