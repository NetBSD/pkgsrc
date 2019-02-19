$NetBSD: patch-setup.py,v 1.1 2019/02/19 09:43:56 adam Exp $

Exclude all tests.

--- setup.py.orig	2019-02-19 09:37:15.000000000 +0000
+++ setup.py
@@ -51,7 +51,7 @@ setup(
     author='Isaac Muse',
     author_email='Isaac.Muse@gmail.com',
     url='https://github.com/facelessuser/soupsieve',
-    packages=find_packages(exclude=['tests', 'tools']),
+    packages=find_packages(exclude=['tests', 'tests.*', 'tools']),
     install_requires=get_requirements(),
     license='MIT License',
     classifiers=[
