$NetBSD: patch-setup.py,v 1.2 2019/04/07 15:58:33 adam Exp $

Do not install tests.
Avoid too strict version requirements.

--- setup.py.orig	2018-09-23 11:26:23.000000000 +0000
+++ setup.py
@@ -35,7 +35,7 @@ setup(
     author='Benno Rice',
     author_email='benno@jeamland.net',
     url='https://github.com/python-hyper/wsproto/',
-    packages=find_packages(),
+    packages=find_packages(exclude=['test']),
     package_data={'': ['LICENSE', 'README.rst']},
     package_dir={'wsproto': 'wsproto'},
     include_package_data=True,
@@ -55,7 +55,7 @@ setup(
         'Programming Language :: Python :: Implementation :: PyPy',
     ],
     install_requires=[
-        'h11 ~= 0.8.1',  # means: 0.8.x where x >= 1
+        'h11>=0.8.1',
     ],
     extras_require={
         ':python_version == "2.7"':
