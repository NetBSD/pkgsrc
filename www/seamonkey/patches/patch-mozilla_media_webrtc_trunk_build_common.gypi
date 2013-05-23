$NetBSD: patch-mozilla_media_webrtc_trunk_build_common.gypi,v 1.1 2013/05/23 13:25:30 ryoon Exp $

--- mozilla/media/webrtc/trunk/build/common.gypi.orig	2013-05-03 03:08:06.000000000 +0000
+++ mozilla/media/webrtc/trunk/build/common.gypi
@@ -80,12 +80,21 @@
             ['use_ash==1', {
               'use_aura%': 1,
             }],
+
+            # A flag for BSD platforms
+            ['OS=="dragonfly" or OS=="freebsd" or OS=="netbsd" or \
+              OS=="openbsd"', {
+              'os_bsd%': 1,
+            }, {
+              'os_bsd%': 0,
+            }],
           ],
         },
         # Copy conditionally-set variables out one scope.
         'chromeos%': '<(chromeos)',
         'use_aura%': '<(use_aura)',
         'use_ash%': '<(use_ash)',
+        'os_bsd%': '<(os_bsd)',
         'use_openssl%': '<(use_openssl)',
         'use_ibus%': '<(use_ibus)',
         'enable_viewport%': '<(enable_viewport)',
@@ -119,7 +128,7 @@
           }],
 
           # Set toolkit_uses_gtk for the Chromium browser on Linux.
-          ['(OS=="linux" or OS=="freebsd" or OS=="openbsd" or OS=="solaris") and use_aura==0', {
+          ['(OS=="linux" or OS=="solaris" or os_bsd==1) and use_aura==0', {
             'toolkit_uses_gtk%': 1,
           }, {
             'toolkit_uses_gtk%': 0,
@@ -144,6 +153,7 @@
       'toolkit_uses_gtk%': '<(toolkit_uses_gtk)',
       'use_aura%': '<(use_aura)',
       'use_ash%': '<(use_ash)',
+      'os_bsd%': '<(os_bsd)',
       'use_openssl%': '<(use_openssl)',
       'use_ibus%': '<(use_ibus)',
       'enable_viewport%': '<(enable_viewport)',
@@ -406,15 +416,8 @@
           'os_posix%': 1,
         }],
 
-        # A flag for BSD platforms
-        ['OS=="freebsd" or OS=="openbsd"', {
-          'os_bsd%': 1,
-        }, {
-          'os_bsd%': 0,
-        }],
-
         # NSS usage.
-        ['(OS=="linux" or OS=="freebsd" or OS=="openbsd" or OS=="solaris") and use_openssl==0', {
+        ['(OS=="linux" or OS=="solaris" or os_bsd==1) and use_openssl==0', {
           'use_nss%': 1,
         }, {
           'use_nss%': 0,
