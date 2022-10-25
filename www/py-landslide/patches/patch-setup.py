$NetBSD: patch-setup.py,v 1.3 2022/10/25 15:56:21 adam Exp $

Relax dependencies.

--- setup.py.orig	2022-06-12 03:45:27.000000000 +0000
+++ setup.py
@@ -23,12 +23,12 @@ setup(
         'textile'
     ],
     install_requires=[
-        'MarkupSafe==1.1.1',
-        'Jinja2==2.10.1',
-        'Markdown==2.6.11',
-        'Pygments==2.2.0',
-        'docutils==0.14',
-        'six==1.11.0'
+        'MarkupSafe>=1.1.1',
+        'Jinja2>=2.10.1',
+        'Markdown>=2.6.11',
+        'Pygments>=2.2.0',
+        'docutils>=0.14',
+        'six>=1.11.0'
     ],
     classifiers=[
         'Programming Language :: Python',
