$NetBSD: patch-src_3rdparty_chromium_third__party_blink_renderer_bindings_scripts_web__idl_callback__interface.py,v 1.1 2023/06/08 20:38:06 markd Exp $

build with python3

--- src/3rdparty/chromium/third_party/blink/renderer/bindings/scripts/web_idl/callback_interface.py.orig	2022-03-30 09:48:18.000000000 +0000
+++ src/3rdparty/chromium/third_party/blink/renderer/bindings/scripts/web_idl/callback_interface.py
@@ -91,11 +91,13 @@ class CallbackInterface(UserDefinedType,
             for operation_ir in ir.operations
         ])
         self._operation_groups = tuple([
-            OperationGroup(
-                operation_group_ir,
-                filter(lambda x: x.identifier == operation_group_ir.identifier,
-                       self._operations),
-                owner=self) for operation_group_ir in ir.operation_groups
+            OperationGroup(operation_group_ir,
+                           list(
+                               filter(
+                                   lambda x: x.identifier == operation_group_ir
+                                   .identifier, self._operations)),
+                           owner=self)
+            for operation_group_ir in ir.operation_groups
         ])
 
     @property
