$NetBSD: patch-setup.py,v 1.1 2019/07/02 04:19:59 adam Exp $

Relax dependencies.

--- setup.py.orig	2019-07-02 04:14:10.000000000 +0000
+++ setup.py
@@ -23,11 +23,11 @@ setup(
         'textile'
     ],
     install_requires=[
-        'Jinja2==2.10',
-        'Markdown==2.6.11',
-        'Pygments==2.2.0',
-        'docutils==0.14',
-        'six==1.11.0'
+        'Jinja2>=2.10',
+        'Markdown>=2.6.11',
+        'Pygments>=2.2.0',
+        'docutils>=0.14',
+        'six>=1.11.0'
     ],
     classifiers=[
         'Programming Language :: Python',
