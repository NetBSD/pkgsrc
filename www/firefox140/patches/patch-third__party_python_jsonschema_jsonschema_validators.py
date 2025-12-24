$NetBSD: patch-third__party_python_jsonschema_jsonschema_validators.py,v 1.1 2025/12/24 02:11:49 gutteridge Exp $

Fix builds with Python 3.14.
https://github.com/mozilla-firefox/firefox/commit/b09b27487e5d649612e0baae309608954ff9d542

--- third_party/python/jsonschema/jsonschema/validators.py.orig	2025-12-01 18:15:47.000000000 +0000
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
