$NetBSD: patch-setup.py,v 1.1 2020/01/08 20:58:29 adam Exp $

Avoid files outside PYSITELIB.

--- setup.py.orig	2020-01-08 20:25:09.000000000 +0000
+++ setup.py
@@ -61,7 +61,6 @@ setup(
     author_email='tom@tomchristie.com',
     packages=get_packages('uvicorn'),
     install_requires=requirements,
-    data_files = [("", ["LICENSE.md"])],
     classifiers=[
         'Development Status :: 4 - Beta',
         'Environment :: Web Environment',
