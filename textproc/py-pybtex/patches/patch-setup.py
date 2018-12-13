$NetBSD: patch-setup.py,v 1.1 2018/12/13 21:01:01 adam Exp $

Do not install tests.

--- setup.py.orig	2018-12-13 20:55:25.000000000 +0000
+++ setup.py
@@ -82,7 +82,7 @@ setup(
     ],
     install_requires=install_requires,
     python_requires='>=2.7,!=3.0.*,!=3.1.*,!=3.2.*',
-    packages=find_packages(exclude=['docs']),
+    packages=find_packages(exclude=['docs','tests*']),
     include_package_data=True,
     cmdclass={'sdist': Sdist},
     entry_points={
