$NetBSD: patch-setup.py,v 1.1 2020/09/16 03:00:37 gutteridge Exp $

Fix packaging with Python 3.6. Taken from upstream commit:
https://github.com/micktwomey/pyiso8601/commit/b5544878bc799bdd77d63d3c9e78c4fcc4e018ad

--- setup.py.orig	2020-09-11 17:04:56.000000000 +0000
+++ setup.py
@@ -5,7 +5,7 @@ try:
 except ImportError:
     from distutils import setup
 
-long_description = open(os.path.join(os.path.dirname(__file__), "README.rst")).read()
+long_description = open(os.path.join(os.path.dirname(__file__), "README.rst"), "rb").read().decode("UTF-8")
 
 setup(
     name="iso8601",
