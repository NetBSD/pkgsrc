$NetBSD: patch-setup.py,v 1.3 2023/11/13 16:34:01 wiz Exp $

Make sure cython is not found.
https://github.com/yaml/pyyaml/issues/601

--- setup.py.orig	2023-07-17 23:39:53.000000000 +0000
+++ setup.py
@@ -87,6 +87,7 @@ try:
 except ImportError:
     if with_cython:
         raise
+with_cython = False
 
 try:
     from wheel.bdist_wheel import bdist_wheel
