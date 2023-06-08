$NetBSD: patch-src_3rdparty_chromium_third__party_blink_renderer_bindings_scripts_v8__methods.py,v 1.1 2023/06/08 20:38:06 markd Exp $

build with python3

--- src/3rdparty/chromium/third_party/blink/renderer/bindings/scripts/v8_methods.py.orig	2022-03-30 09:48:18.000000000 +0000
+++ src/3rdparty/chromium/third_party/blink/renderer/bindings/scripts/v8_methods.py
@@ -46,6 +46,10 @@ import v8_types
 import v8_utilities
 from v8_utilities import (has_extended_attribute_value, is_unforgeable)
 
+# TODO: Remove this once Python2 is obsoleted.
+if sys.version_info.major != 2:
+    basestring = str
+
 
 def method_is_visible(method, interface_is_partial):
     if 'overloads' in method:
