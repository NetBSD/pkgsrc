$NetBSD: patch-media_webrtc_signaling_signaling.gyp,v 1.1 2014/11/03 12:18:32 ryoon Exp $

--- media/webrtc/signaling/signaling.gyp.orig	2014-04-18 02:03:50.000000000 +0000
+++ media/webrtc/signaling/signaling.gyp
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
