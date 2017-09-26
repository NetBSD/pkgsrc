$NetBSD: patch-plasma_generic_scriptengines_python_plasma__importer.py,v 1.1 2017/09/26 13:10:07 abs Exp $
No need to check python version as exec() works in supported 2.x (2.7)
versions now

--- plasma/generic/scriptengines/python/plasma_importer.py.orig	2015-08-12 07:03:15.000000000 +0000
+++ plasma/generic/scriptengines/python/plasma_importer.py
@@ -22,8 +22,6 @@ import sys
 import os
 import imp
 
-PY3 = sys.version_info[0] == 3
-
 
 class PlasmaImporter(object):
     def __init__(self):
@@ -107,10 +105,7 @@ class PlasmaImporter(object):
             mod.__path__ = [self.marker]
         if code is not None:
             try:
-                if PY3:
-                    exec(code in mod.__dict__)
-                else:
-                    exec code in mod.__dict__
+                exec(code in mod.__dict__)
             finally:
                 code.close()
         return mod
