$NetBSD: patch-src_3rdparty_chromium_third__party_blink_renderer_bindings_scripts_v8__interface.py,v 1.1 2023/06/08 20:38:06 markd Exp $

build with python3

--- src/3rdparty/chromium/third_party/blink/renderer/bindings/scripts/v8_interface.py.orig	2022-03-30 09:48:18.000000000 +0000
+++ src/3rdparty/chromium/third_party/blink/renderer/bindings/scripts/v8_interface.py
@@ -189,7 +189,7 @@ def context_enabled_features(attributes)
         return sorted([
             member for member in members
             if member.get(KEY) and not member.get('exposed_test')
-        ])
+        ], key=lambda item: item['name'])
 
     def member_filter_by_name(members, name):
         return [member for member in members if member[KEY] == name]
@@ -612,7 +612,8 @@ def interface_context(interface, interfa
         sorted(
             origin_trial_features(interface, context['constants'],
                                   context['attributes'], context['methods']) +
-            context_enabled_features(context['attributes'])),
+            context_enabled_features(context['attributes']),
+            key=lambda item: item['name']),
     })
     if context['optional_features']:
         includes.add('platform/bindings/v8_per_context_data.h')
@@ -1356,9 +1357,9 @@ def resolution_tests_methods(effective_o
 
     # Extract argument and IDL type to simplify accessing these in each loop.
     arguments = [method['arguments'][index] for method in methods]
-    arguments_methods = zip(arguments, methods)
+    arguments_methods = list(zip(arguments, methods))
     idl_types = [argument['idl_type_object'] for argument in arguments]
-    idl_types_methods = zip(idl_types, methods)
+    idl_types_methods = list(zip(idl_types, methods))
 
     # We can’t do a single loop through all methods or simply sort them, because
     # a method may be listed in multiple steps of the resolution algorithm, and
