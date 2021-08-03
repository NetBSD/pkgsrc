$NetBSD: patch-src_3rdparty_chromium_tools_variations_fieldtrial__to__struct.py,v 1.1 2021/08/03 21:04:36 markd Exp $

--- src/3rdparty/chromium/tools/variations/fieldtrial_to_struct.py.orig	2020-07-15 18:56:33.000000000 +0000
+++ src/3rdparty/chromium/tools/variations/fieldtrial_to_struct.py
@@ -40,6 +40,9 @@ _platforms = [
     'linux',
     'mac',
     'windows',
+    'freebsd',
+    'openbsd',
+    'netbsd',
 ]
 
 _form_factors = [
