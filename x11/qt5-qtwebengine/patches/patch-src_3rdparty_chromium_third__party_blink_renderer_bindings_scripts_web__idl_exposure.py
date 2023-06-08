$NetBSD: patch-src_3rdparty_chromium_third__party_blink_renderer_bindings_scripts_web__idl_exposure.py,v 1.1 2023/06/08 20:38:06 markd Exp $

build with python3

--- src/3rdparty/chromium/third_party/blink/renderer/bindings/scripts/web_idl/exposure.py.orig	2022-03-30 09:48:18.000000000 +0000
+++ src/3rdparty/chromium/third_party/blink/renderer/bindings/scripts/web_idl/exposure.py
@@ -8,8 +8,11 @@ from .runtime_enabled_features import Ru
 class _Feature(str):
     """Represents a runtime-enabled feature."""
 
+    def __new__(cls, value):
+        return str.__new__(cls, value)
+
     def __init__(self, value):
-        str.__init__(self, value)
+        str.__init__(self)
         self._is_context_dependent = (
             RuntimeEnabledFeatures.is_context_dependent(self))
 
