$NetBSD: patch-pyjade_ext_django_loader.py,v 1.1 2017/12/18 11:09:14 adam Exp $

Upgrade loader to be compatible with django 1.10
https://github.com/syrusakbary/pyjade/pull/263

--- pyjade/ext/django/loader.py.orig	2017-12-18 11:00:49.000000000 +0000
+++ pyjade/ext/django/loader.py
@@ -7,7 +7,11 @@ try:
 except ImportError:  # Django < 1.9
     from django.template.base import TemplateDoesNotExist
 
-from django.template.loader import BaseLoader
+try:
+    from django.template.loaders.base import Loader as BaseLoader
+except ImportError:  # Django < 1.9
+    from django.template.loader import BaseLoader
+
 try:
     from django.template.engine import Engine
 except ImportError:  # Django < 1.8
@@ -18,7 +22,6 @@ from django.conf import settings
 from .compiler import Compiler
 
 from pyjade.utils import process
-# from django.template.loaders.cached import Loader
 
 
 try:
@@ -40,7 +43,7 @@ except ImportError:  # Django >= 1.9
 class Loader(BaseLoader):
     is_usable = True
 
-    def __init__(self, loaders):
+    def __init__(self, engine, loaders):
         self.template_cache = {}
         self._loaders = loaders
         self._cached_loaders = []
@@ -112,12 +115,6 @@ class Loader(BaseLoader):
             self.template_cache[key] = template
         return self.template_cache[key], None
 
-    # def _preprocess(self, source, name, filename=None):
-    #     parser = Parser(source,filename=filename)
-    #     block = parser.parse()
-    #     compiler = Compiler(block)
-    #     return compiler.compile().strip()
-
     def reset(self):
-        "Empty the template cache."
+        """Empty the template cache."""
         self.template_cache.clear()
