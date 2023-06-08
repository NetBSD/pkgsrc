$NetBSD: patch-src_3rdparty_chromium_third__party_blink_renderer_bindings_scripts_idl__definitions.py,v 1.1 2023/06/08 20:38:06 markd Exp $

build with python3

--- src/3rdparty/chromium/third_party/blink/renderer/bindings/scripts/idl_definitions.py.orig	2022-03-30 09:48:18.000000000 +0000
+++ src/3rdparty/chromium/third_party/blink/renderer/bindings/scripts/idl_definitions.py
@@ -394,7 +394,8 @@ class IdlInterface(object):
             else:
                 raise ValueError('Unrecognized node class: %s' % child_class)
 
-        if len(filter(None, [self.iterable, self.maplike, self.setlike])) > 1:
+        if len(list(filter(None,
+                           [self.iterable, self.maplike, self.setlike]))) > 1:
             raise ValueError(
                 'Interface can only have one of iterable<>, maplike<> and setlike<>.'
             )
@@ -512,6 +513,9 @@ class IdlAttribute(TypedObject):
     def accept(self, visitor):
         visitor.visit_attribute(self)
 
+    def __lt__(self, other):
+        return self.name < other.name
+
 
 ################################################################################
 # Constants
@@ -852,7 +856,7 @@ class IdlIncludes(object):
 ################################################################################
 
 
-class Exposure:
+class Exposure(object):
     """An Exposure holds one Exposed or RuntimeEnabled condition.
     Each exposure has two properties: exposed and runtime_enabled.
     Exposure(e, r) corresponds to [Exposed(e r)]. Exposure(e) corresponds to
