$NetBSD: patch-setup.py,v 1.1 2025/10/09 11:59:29 wiz Exp $

Fix build with Python 3.14
Based on a comment in
https://github.com/html5lib/html5lib-python/pull/589

--- setup.py.orig	2025-10-09 11:57:09.810246679 +0000
+++ setup.py
@@ -89,9 +89,14 @@ with open(join(here, "html5lib", "__init
     for a in assignments:
         if (len(a.targets) == 1 and
                 isinstance(a.targets[0], ast.Name) and
-                a.targets[0].id == "__version__" and
-                isinstance(a.value, ast.Str)):
-            version = a.value.s
+                a.targets[0].id == "__version__"):
+            if hasattr(ast, "Str") and isinstance(a.value, ast.Str):
+                version = a.value.s
+            elif (hasattr(ast, "Constant")
+                  and isinstance(a.value, ast.Constant)
+                  and isinstance(a.value.value, str)):
+                version = a.value.value
+assert version is not None
 
 setup(name='html5lib',
       version=version,
