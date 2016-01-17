$NetBSD: patch-setup.py,v 1.1 2016/01/17 13:45:42 wiz Exp $

Drop sphinx dependency.
https://github.com/snide/sphinx_rtd_theme/commit/9e2b17147dcf182622b5f3d9bf5e130dec924fe1

--- setup.py.orig	2015-09-09 03:02:58.000000000 +0000
+++ setup.py
@@ -27,7 +27,6 @@ setup(
         'static/font/*.*'
     ]},
     include_package_data=True,
-    install_requires=open('requirements.txt').read().splitlines(),
     classifiers=[
         'Development Status :: 3 - Alpha',
         'License :: OSI Approved :: BSD License',
