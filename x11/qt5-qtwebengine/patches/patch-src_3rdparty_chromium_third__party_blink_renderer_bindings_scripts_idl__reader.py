$NetBSD: patch-src_3rdparty_chromium_third__party_blink_renderer_bindings_scripts_idl__reader.py,v 1.1 2023/06/08 20:38:06 markd Exp $

build with python3

--- src/3rdparty/chromium/third_party/blink/renderer/bindings/scripts/idl_reader.py.orig	2022-03-30 09:48:18.000000000 +0000
+++ src/3rdparty/chromium/third_party/blink/renderer/bindings/scripts/idl_reader.py
@@ -55,8 +55,8 @@ def validate_blink_idl_definitions(idl_f
          definitions. There is no filename convention in this case.
        - Otherwise, an IDL file is invalid.
     """
-    targets = (
-        definitions.interfaces.values() + definitions.dictionaries.values())
+    targets = (list(definitions.interfaces.values()) +
+               list(definitions.dictionaries.values()))
     number_of_targets = len(targets)
     if number_of_targets > 1:
         raise Exception(
