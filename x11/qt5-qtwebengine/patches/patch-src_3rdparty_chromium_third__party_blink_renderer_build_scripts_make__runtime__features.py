$NetBSD: patch-src_3rdparty_chromium_third__party_blink_renderer_build_scripts_make__runtime__features.py,v 1.1 2023/06/08 20:38:06 markd Exp $

build with python3

--- src/3rdparty/chromium/third_party/blink/renderer/build/scripts/make_runtime_features.py.orig	2022-03-30 09:48:18.000000000 +0000
+++ src/3rdparty/chromium/third_party/blink/renderer/build/scripts/make_runtime_features.py
@@ -138,7 +138,7 @@ class RuntimeFeatureWriter(BaseRuntimeFe
                 except Exception:
                     # If trouble unpickling, overwrite
                     pass
-        with open(os.path.abspath(file_name), 'w') as pickle_file:
+        with open(os.path.abspath(file_name), 'wb') as pickle_file:
             pickle.dump(features_map, pickle_file)
 
     def _template_inputs(self):
