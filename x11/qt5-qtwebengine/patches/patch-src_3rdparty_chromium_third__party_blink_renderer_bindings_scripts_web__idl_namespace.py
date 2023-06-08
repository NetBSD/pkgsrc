$NetBSD: patch-src_3rdparty_chromium_third__party_blink_renderer_bindings_scripts_web__idl_namespace.py,v 1.1 2023/06/08 20:38:06 markd Exp $

build with python3

--- src/3rdparty/chromium/third_party/blink/renderer/bindings/scripts/web_idl/namespace.py.orig	2022-03-30 09:48:18.000000000 +0000
+++ src/3rdparty/chromium/third_party/blink/renderer/bindings/scripts/web_idl/namespace.py
@@ -107,11 +107,13 @@ class Namespace(UserDefinedType, WithExt
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
