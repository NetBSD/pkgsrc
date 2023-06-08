$NetBSD: patch-src_3rdparty_chromium_third__party_blink_renderer_bindings_scripts_idl__types.py,v 1.1 2023/06/08 20:38:06 markd Exp $

build with python3

--- src/3rdparty/chromium/third_party/blink/renderer/bindings/scripts/idl_types.py.orig	2022-03-30 09:48:18.000000000 +0000
+++ src/3rdparty/chromium/third_party/blink/renderer/bindings/scripts/idl_types.py
@@ -349,7 +349,7 @@ class IdlUnionType(IdlTypeBase):
         return True
 
     def single_matching_member_type(self, predicate):
-        matching_types = filter(predicate, self.flattened_member_types)
+        matching_types = list(filter(predicate, self.flattened_member_types))
         if len(matching_types) > 1:
             raise ValueError('%s is ambiguous.' % self.name)
         return matching_types[0] if matching_types else None
