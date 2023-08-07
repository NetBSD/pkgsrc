$NetBSD: patch-python_mozbuild_mozbuild_backend_base.py,v 1.1 2023/08/07 13:28:04 abs Exp $

Update for modern (>3.9) python open() mode

--- python/mozbuild/mozbuild/backend/base.py.orig	2022-08-15 18:05:01.000000000 +0000
+++ python/mozbuild/mozbuild/backend/base.py
@@ -272,7 +272,7 @@ class BuildBackend(LoggingMixin):
         return status
 
     @contextmanager
-    def _write_file(self, path=None, fh=None, readmode="rU"):
+    def _write_file(self, path=None, fh=None, readmode="r"):
         """Context manager to write a file.
 
         This is a glorified wrapper around FileAvoidWrite with integration to
