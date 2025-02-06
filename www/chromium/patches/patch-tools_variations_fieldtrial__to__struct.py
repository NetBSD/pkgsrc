$NetBSD: patch-tools_variations_fieldtrial__to__struct.py,v 1.1 2025/02/06 09:58:30 wiz Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- tools/variations/fieldtrial_to_struct.py.orig	2024-12-17 17:58:49.000000000 +0000
+++ tools/variations/fieldtrial_to_struct.py
@@ -41,6 +41,9 @@ _platforms = [
     'linux',
     'mac',
     'windows',
+    'openbsd',
+    'freebsd',
+    'netbsd',
 ]
 
 _form_factors = [
