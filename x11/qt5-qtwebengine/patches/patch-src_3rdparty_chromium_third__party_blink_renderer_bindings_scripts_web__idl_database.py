$NetBSD: patch-src_3rdparty_chromium_third__party_blink_renderer_bindings_scripts_web__idl_database.py,v 1.1 2023/06/08 20:38:06 markd Exp $

build with python3

--- src/3rdparty/chromium/third_party/blink/renderer/bindings/scripts/web_idl/database.py.orig	2022-03-30 09:48:18.000000000 +0000
+++ src/3rdparty/chromium/third_party/blink/renderer/bindings/scripts/web_idl/database.py
@@ -156,4 +156,4 @@ class Database(object):
         return self._view_by_kind(Database._Kind.UNION)
 
     def _view_by_kind(self, kind):
-        return self._impl.find_by_kind(kind).values()
+        return list(self._impl.find_by_kind(kind).values())
