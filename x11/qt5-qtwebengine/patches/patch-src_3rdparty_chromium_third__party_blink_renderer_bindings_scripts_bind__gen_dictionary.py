$NetBSD: patch-src_3rdparty_chromium_third__party_blink_renderer_bindings_scripts_bind__gen_dictionary.py,v 1.1 2023/06/08 20:38:06 markd Exp $

build with python3

--- src/3rdparty/chromium/third_party/blink/renderer/bindings/scripts/bind_gen/dictionary.py.orig	2022-03-30 09:48:18.000000000 +0000
+++ src/3rdparty/chromium/third_party/blink/renderer/bindings/scripts/bind_gen/dictionary.py
@@ -993,7 +993,7 @@ def make_dict_trace_func(cg_context):
         _2 = _blink_member_name(member).value_var
         return TextNode(_format(pattern, _1=_1, _2=_2))
 
-    body.extend(map(make_trace_member_node, own_members))
+    body.extend(list(map(make_trace_member_node, own_members)))
     body.append(TextNode("BaseClass::Trace(visitor);"))
 
     return func_decl, func_def
