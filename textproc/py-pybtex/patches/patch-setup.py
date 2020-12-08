$NetBSD: patch-setup.py,v 1.2 2020/12/08 15:03:58 adam Exp $

Do not install tests.

--- setup.py.orig	2020-12-08 14:55:32.000000000 +0000
+++ setup.py
@@ -92,7 +92,7 @@ setup(
     install_requires=install_requires,
     extras_require=extras_require,
     python_requires='>=2.7,!=3.0.*,!=3.1.*,!=3.2.*',
-    packages=find_packages(exclude=['docs']),
+    packages=find_packages(exclude=['docs','tests*']),
     include_package_data=True,
     cmdclass={'sdist': Sdist},
     entry_points={
