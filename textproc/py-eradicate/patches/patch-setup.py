$NetBSD: patch-setup.py,v 1.1 2025/10/09 12:28:55 wiz Exp $

Fix build with Python 3.14.
https://github.com/PyCQA/eradicate/issues/57

--- setup.py.orig	2025-10-09 12:27:22.572094370 +0000
+++ setup.py
@@ -11,7 +11,7 @@ def version():
     with open('eradicate.py') as input_file:
         for line in input_file:
             if line.startswith('__version__'):
-                return ast.parse(line).body[0].value.s
+                return ast.parse(line).body[0].value.value
 
 
 with open('README.rst') as readme:
