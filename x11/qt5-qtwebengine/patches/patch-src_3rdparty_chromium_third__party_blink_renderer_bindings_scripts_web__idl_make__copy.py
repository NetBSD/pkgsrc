$NetBSD: patch-src_3rdparty_chromium_third__party_blink_renderer_bindings_scripts_web__idl_make__copy.py,v 1.1 2023/06/08 20:38:06 markd Exp $

build with python3

--- src/3rdparty/chromium/third_party/blink/renderer/bindings/scripts/web_idl/make_copy.py.orig	2022-03-30 09:48:18.000000000 +0000
+++ src/3rdparty/chromium/third_party/blink/renderer/bindings/scripts/web_idl/make_copy.py
@@ -3,6 +3,13 @@
 # found in the LICENSE file.
 
 
+import sys
+
+# TODO: Remove this once Python2 is obsoleted.
+if sys.version_info.major != 2:
+    long = int
+    basestring = str
+
 def make_copy(obj, memo=None):
     """
     Creates a copy of the given object, which should be an IR or part of IR.
