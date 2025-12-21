$NetBSD: patch-src_3rdparty_chromium_tools_variations_fieldtrial__to__struct.py,v 1.1 2025/12/21 09:38:46 markd Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- src/3rdparty/chromium/tools/variations/fieldtrial_to_struct.py.orig	2024-12-17 17:58:49.000000000 +0000
+++ src/3rdparty/chromium/tools/variations/fieldtrial_to_struct.py
@@ -41,6 +41,9 @@ _platforms = [
     'linux',
     'mac',
     'windows',
+    'openbsd',
+    'freebsd',
+    'netbsd',
 ]
 
 _form_factors = [
