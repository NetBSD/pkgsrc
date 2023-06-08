$NetBSD: patch-src_3rdparty_chromium_third__party_blink_renderer_bindings_scripts_bind__gen_codegen__format.py,v 1.1 2023/06/08 20:38:06 markd Exp $

build with python3

--- src/3rdparty/chromium/third_party/blink/renderer/bindings/scripts/bind_gen/codegen_format.py.orig	2022-03-30 09:48:18.000000000 +0000
+++ src/3rdparty/chromium/third_party/blink/renderer/bindings/scripts/bind_gen/codegen_format.py
@@ -23,7 +23,7 @@ class _TemplateFormatter(string.Formatte
         self._template_formatter_indexing_count_ = 0
 
     def get_value(self, key, args, kwargs):
-        if isinstance(key, (int, long)):
+        if isinstance(key, int):
             return args[key]
         assert isinstance(key, str)
         if not key:
