$NetBSD: patch-src_3rdparty_chromium_third__party_blink_renderer_build_scripts_in__file.py,v 1.1 2023/06/08 20:38:06 markd Exp $

build with python3

--- src/3rdparty/chromium/third_party/blink/renderer/build/scripts/in_file.py.orig	2022-03-30 09:48:18.000000000 +0000
+++ src/3rdparty/chromium/third_party/blink/renderer/build/scripts/in_file.py
@@ -66,7 +66,7 @@ class InFile(object):
         self._defaults = defaults
         self._valid_values = copy.deepcopy(
             valid_values if valid_values else {})
-        self._parse(map(str.strip, lines))
+        self._parse(list(map(str.strip, lines)))
 
     @classmethod
     def load_from_files(self, file_paths, defaults, valid_values,
