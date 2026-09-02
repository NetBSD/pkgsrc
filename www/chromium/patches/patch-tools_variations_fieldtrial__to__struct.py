$NetBSD: patch-tools_variations_fieldtrial__to__struct.py,v 1.25 2026/09/02 13:13:38 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- tools/variations/fieldtrial_to_struct.py.orig	2026-08-31 22:47:51.000000000 +0000
+++ tools/variations/fieldtrial_to_struct.py
@@ -31,6 +31,9 @@ _platforms = [
     'linux',
     'mac',
     'windows',
+    'openbsd',
+    'freebsd',
+    'netbsd',
 ]
 
 _form_factors = [
