$NetBSD: patch-src_3rdparty_chromium_third__party_dawn_generator_generator__lib.py,v 1.1 2023/06/08 20:38:06 markd Exp $

build with python3

--- src/3rdparty/chromium/third_party/dawn/generator/generator_lib.py.orig	2022-03-30 09:48:18.000000000 +0000
+++ src/3rdparty/chromium/third_party/dawn/generator/generator_lib.py
@@ -201,6 +201,10 @@ def _compute_python_dependencies(root_di
 
     paths = set()
     for path in module_paths:
+        # Builtin/namespaced modules may return None for the file path.
+        if not path:
+            continue
+
         path = os.path.abspath(path)
 
         if not path.startswith(root_dir):
