$NetBSD: patch-setup.py,v 1.2 2020/12/15 09:07:41 adam Exp $

Relax dependencies.

--- setup.py.orig	2020-08-20 22:45:13.000000000 +0000
+++ setup.py
@@ -23,11 +23,11 @@ setup(
         'textile'
     ],
     install_requires=[
-        'Jinja2==2.10.1',
-        'Markdown==2.6.11',
-        'Pygments==2.2.0',
-        'docutils==0.14',
-        'six==1.11.0'
+        'Jinja2>=2.10.1',
+        'Markdown>=2.6.11',
+        'Pygments>=2.2.0',
+        'docutils>=0.14',
+        'six>=1.11.0'
     ],
     classifiers=[
         'Programming Language :: Python',
