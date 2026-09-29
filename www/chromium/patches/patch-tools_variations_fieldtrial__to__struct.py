$NetBSD: patch-tools_variations_fieldtrial__to__struct.py,v 1.27 2026/09/29 07:43:07 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- tools/variations/fieldtrial_to_struct.py.orig	2026-09-22 00:09:16.000000000 +0000
+++ tools/variations/fieldtrial_to_struct.py
@@ -31,6 +31,9 @@ _platforms = [
   'linux',
   'mac',
   'windows',
+  'openbsd',
+  'freebsd',
+  'netbsd',
 ]
 
 _form_factors = [
