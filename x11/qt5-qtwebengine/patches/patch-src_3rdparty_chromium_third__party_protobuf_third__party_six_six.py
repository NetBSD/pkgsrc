$NetBSD: patch-src_3rdparty_chromium_third__party_protobuf_third__party_six_six.py,v 1.1 2025/07/07 13:50:44 wiz Exp $

Python 3.12 fix
https://sources.debian.org/data/main/q/qtwebengine-opensource-src/5.15.18+dfsg-2~bpo12+1/debian/patches/python3.12-six.patch

--- src/3rdparty/chromium/third_party/protobuf/third_party/six/six.py.orig	2024-04-03 09:31:09.000000000 +0000
+++ src/3rdparty/chromium/third_party/protobuf/third_party/six/six.py
@@ -71,6 +71,11 @@ else:
             MAXSIZE = int((1 << 63) - 1)
         del X
 
+if PY34:
+    from importlib.util import spec_from_loader
+else:
+    spec_from_loader = None
+
 
 def _add_doc(func, doc):
     """Add documentation to a function."""
@@ -186,6 +191,11 @@ class _SixMetaPathImporter(object):
             return self
         return None
 
+    def find_spec(self, fullname, path, target=None):
+        if fullname in self.known_modules:
+            return spec_from_loader(fullname, self)
+        return None
+
     def __get_module(self, fullname):
         try:
             return self.known_modules[fullname]
