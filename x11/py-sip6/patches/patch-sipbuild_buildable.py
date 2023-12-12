$NetBSD: patch-sipbuild_buildable.py,v 1.2 2023/12/12 14:14:15 gdt Exp $

Fix for Python < 3.11: importlib.machinery has to be imported directly.
For consitent PLISTs across platforms, always return .abi3 suffix.

Sent upstream 202312.  Upstream has applied the first hunk.
Upstream said the that second hunk is wrong; things really do change
with the limited api.  To be dropped on update to 6.8.1 and we'll have
to revisit the original problem.

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
 
