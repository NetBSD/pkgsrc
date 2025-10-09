$NetBSD: patch-third__party_python_jsonschema_jsonschema_validators.py,v 1.1 2025/10/09 14:48:03 ryoon Exp $

* For Python 3.14 too.

--- third_party/python/jsonschema/jsonschema/validators.py.orig	2025-10-08 15:29:42.964096922 +0000
+++ third_party/python/jsonschema/jsonschema/validators.py
@@ -875,8 +875,11 @@ class RefResolver:
             return None
         uri, fragment = urldefrag(url)
         for subschema in subschemas:
+            id = subschema["$id"]
+            if not isinstance(id, str):
+                continue
             target_uri = self._urljoin_cache(
-                self.resolution_scope, subschema["$id"],
+                self.resolution_scope, id,
             )
             if target_uri.rstrip("/") == uri.rstrip("/"):
                 if fragment:
