$NetBSD: patch-src_3rdparty_chromium_third__party_devtools-frontend_src_scripts_build_build__inspector__overlay.py,v 1.1 2023/06/08 20:38:06 markd Exp $

build with python3

--- src/3rdparty/chromium/third_party/devtools-frontend/src/scripts/build/build_inspector_overlay.py.orig	2022-03-30 09:48:18.000000000 +0000
+++ src/3rdparty/chromium/third_party/devtools-frontend/src/scripts/build/build_inspector_overlay.py
@@ -45,7 +45,8 @@ def rollup(input_path, output_path, file
         ['--format', 'iife', '-n', 'InspectorOverlay'] + ['--input', target] +
         ['--plugin', rollup_plugin],
         stdout=subprocess.PIPE,
-        stderr=subprocess.PIPE)
+        stderr=subprocess.PIPE,
+        text=True)
     out, error = rollup_process.communicate()
     if not out:
         raise Exception("rollup failed: " + error)
