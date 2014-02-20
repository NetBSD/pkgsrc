$NetBSD: patch-media_webrtc_signaling_signaling.gyp,v 1.4 2014/02/20 13:19:03 ryoon Exp $

--- media/webrtc/signaling/signaling.gyp.orig	2013-12-05 16:07:48.000000000 +0000
+++ media/webrtc/signaling/signaling.gyp
@@ -244,6 +244,19 @@
           'cflags_mozilla': [
           ],
         }],
+        ['os_bsd==1', {
+          'include_dirs': [
+          ],
+          'defines': [
+            # avoiding pointless ifdef churn
+            'SIP_OS_OSX',
+            'OSX',
+            'SECLIB_OPENSSL',
+          ],
+
+          'cflags_mozilla': [
+          ],
+        }],
         ['OS=="mac"', {
           'include_dirs': [
           ],
@@ -823,14 +836,13 @@
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
