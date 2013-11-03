$NetBSD: patch-media_mtransport_third__party_nrappkit_nrappkit.gyp,v 1.1 2013/11/03 04:51:59 ryoon Exp $

--- media/mtransport/third_party/nrappkit/nrappkit.gyp.orig	2013-05-11 19:19:43.000000000 +0000
+++ media/mtransport/third_party/nrappkit/nrappkit.gyp
@@ -147,8 +147,18 @@
           ],
           
           'conditions' : [
-              ## Mac
+              ## Mac and BSDs
               [ 'OS == "mac"', {
+                'defines' : [
+                    'DARWIN',
+                ],
+              }],
+              [ 'os_bsd == 1', {
+                'defines' : [
+                    'BSD',
+                ],
+              }],
+              [ 'OS == "mac" or os_bsd == 1', {
                 'cflags_mozilla': [
                     '-Wall',
                     '-Wno-parentheses',
@@ -156,7 +166,6 @@
                     '-Wmissing-prototypes',
                  ],
                  'defines' : [
-                     'DARWIN',
                      'HAVE_LIBM=1',
                      'HAVE_STRDUP=1',
                      'HAVE_STRLCPY=1',
