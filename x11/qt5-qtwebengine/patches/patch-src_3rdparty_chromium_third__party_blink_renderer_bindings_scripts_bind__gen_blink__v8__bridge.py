$NetBSD: patch-src_3rdparty_chromium_third__party_blink_renderer_bindings_scripts_bind__gen_blink__v8__bridge.py,v 1.1 2023/06/08 20:38:06 markd Exp $

build with python3

--- src/3rdparty/chromium/third_party/blink/renderer/bindings/scripts/bind_gen/blink_v8_bridge.py.orig	2022-03-30 09:48:18.000000000 +0000
+++ src/3rdparty/chromium/third_party/blink/renderer/bindings/scripts/bind_gen/blink_v8_bridge.py
@@ -344,7 +344,7 @@ def make_default_value_expr(idl_type, de
     """
     assert default_value.is_type_compatible_with(idl_type)
 
-    class DefaultValueExpr:
+    class DefaultValueExpr(object):
         _ALLOWED_SYMBOLS_IN_DEPS = ("isolate")
 
         def __init__(self, initializer_expr, initializer_deps,
@@ -502,7 +502,7 @@ def make_v8_to_blink_value(blink_var_nam
     assert isinstance(blink_var_name, str)
     assert isinstance(v8_value_expr, str)
     assert isinstance(idl_type, web_idl.IdlType)
-    assert (argument_index is None or isinstance(argument_index, (int, long)))
+    assert (argument_index is None or isinstance(argument_index, int))
     assert (default_value is None
             or isinstance(default_value, web_idl.LiteralConstant))
 
@@ -622,7 +622,7 @@ def make_v8_to_blink_value_variadic(blin
     """
     assert isinstance(blink_var_name, str)
     assert isinstance(v8_array, str)
-    assert isinstance(v8_array_start_index, (int, long))
+    assert isinstance(v8_array_start_index, int)
     assert isinstance(idl_type, web_idl.IdlType)
 
     pattern = ("auto&& ${{{_1}}} = "
