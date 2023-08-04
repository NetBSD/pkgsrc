$NetBSD: patch-setup.py,v 1.4 2023/08/04 22:50:55 adam Exp $

Relax dependencies.

--- setup.py.orig	2023-03-24 03:22:12.000000000 +0000
+++ setup.py
@@ -23,11 +23,11 @@ setup(
         'textile'
     ],
     install_requires=[
-        'MarkupSafe==2.1.2',
-        'Jinja2==3.1.2',
-        'Markdown==3.4.1',
-        'Pygments==2.14.0',
-        'docutils==0.19'
+        'MarkupSafe>=2.1.2',
+        'Jinja2>=3.1.2',
+        'Markdown>=3.4.1',
+        'Pygments>=2.14.0',
+        'docutils>=0.19'
     ],
     classifiers=[
         'Programming Language :: Python',
