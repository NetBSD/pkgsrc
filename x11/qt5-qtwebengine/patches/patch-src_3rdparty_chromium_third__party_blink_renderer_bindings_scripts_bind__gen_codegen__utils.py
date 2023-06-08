$NetBSD: patch-src_3rdparty_chromium_third__party_blink_renderer_bindings_scripts_bind__gen_codegen__utils.py,v 1.1 2023/06/08 20:38:06 markd Exp $

build with python3

--- src/3rdparty/chromium/third_party/blink/renderer/bindings/scripts/bind_gen/codegen_utils.py.orig	2022-03-30 09:48:18.000000000 +0000
+++ src/3rdparty/chromium/third_party/blink/renderer/bindings/scripts/bind_gen/codegen_utils.py
@@ -116,4 +116,4 @@ def write_code_node_to_file(code_node, f
 #                               stderr=format_result.error_message))
 #
 #    web_idl.file_io.write_to_file_if_changed(filepath, format_result.contents)
-    web_idl.file_io.write_to_file_if_changed(filepath, rendered_text)
+    web_idl.file_io.write_to_file_if_changed(filepath, rendered_text.encode('utf-8'))
