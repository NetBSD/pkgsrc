$NetBSD: patch-src_3rdparty_chromium_third__party_blink_renderer_bindings_scripts_generate__origin__trial__features.py,v 1.1 2023/06/08 20:38:06 markd Exp $

build with python3

--- src/3rdparty/chromium/third_party/blink/renderer/bindings/scripts/generate_origin_trial_features.py.orig	2022-03-30 09:48:18.000000000 +0000
+++ src/3rdparty/chromium/third_party/blink/renderer/bindings/scripts/generate_origin_trial_features.py
@@ -80,7 +80,7 @@ def read_idl_file(reader, idl_filename):
     assert len(interfaces) == 1, (
         "Expected one interface in file %r, found %d" %
         (idl_filename, len(interfaces)))
-    return (interfaces.values()[0], includes)
+    return (list(interfaces.values())[0], includes)
 
 
 def interface_is_global(interface):
@@ -281,7 +281,7 @@ def main():
 
     info_provider = create_component_info_provider(
         os.path.normpath(options.info_dir), options.target_component)
-    idl_filenames = map(str.strip, open(options.idl_files_list))
+    idl_filenames = list(map(str.strip, open(options.idl_files_list)))
 
     generate_origin_trial_features(info_provider, options, idl_filenames)
     return 0
