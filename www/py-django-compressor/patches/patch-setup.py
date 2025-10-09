$NetBSD: patch-setup.py,v 1.3 2025/10/09 12:25:30 wiz Exp $

Fix build with Python 3.14
https://github.com/django-compressor/django-compressor/commit/108b45cff914427f092ffe35425b1802cbe01307

Don't pin to a single version
https://github.com/django-compressor/django-compressor/issues/1195

--- setup.py.orig	2024-06-16 14:46:44.000000000 +0000
+++ setup.py
@@ -14,7 +14,7 @@ class VersionFinder(ast.NodeVisitor):
 
     def visit_Assign(self, node):
         if node.targets[0].id == "__version__":
-            self.version = node.value.s
+            self.version = node.value.value
 
 
 def read(*parts):
@@ -164,7 +164,7 @@ setup(
     install_requires=[
         "Django >= 4.2",
         "django-appconf >= 1.0.3",
-        "rcssmin == 1.1.2",
-        "rjsmin == 1.2.2",
+        "rcssmin >= 1.1.2",
+        "rjsmin >= 1.2.2",
     ],
 )
