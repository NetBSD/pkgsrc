$NetBSD: patch-sipbuild_buildable.py,v 1.1 2023/08/06 19:18:35 adam Exp $

Fix for Python < 3.11: importlib.machinery has to be imported directly.
For consitent PLISTs across platforms, always return .abi3 suffix.

--- sipbuild/buildable.py.orig	2023-08-02 11:50:08.000000000 +0000
+++ sipbuild/buildable.py
@@ -21,7 +21,7 @@
 # POSSIBILITY OF SUCH DAMAGE.
 
 
-import importlib
+import importlib.machinery
 import os
 
 from .exceptions import UserException
@@ -153,10 +153,9 @@ class BuildableModule(BuildableFromSourc
 
         suffixes = importlib.machinery.EXTENSION_SUFFIXES
 
-        if self.uses_limited_api:
-            for s in suffixes:
-                if '.abi3' in s:
-                    return s
+        for s in suffixes:
+            if '.abi3' in s:
+                return s
 
         return suffixes[0]
 
