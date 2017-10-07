$NetBSD: patch-setup.py,v 1.2 2017/10/07 07:31:14 adam Exp $

Install README.creole into right directory.

--- setup.py.orig	2015-08-15 20:26:05.000000000 +0000
+++ setup.py
@@ -207,7 +207,7 @@ setup(
     url='https://github.com/jedie/python-creole/',
     packages=find_packages(),
     include_package_data=True, # include package data under svn source control
-    data_files=[("", ["README.creole"])], # README used in unittest test_setup_utils.py
+    data_files=[("share/doc/py-creole", ["README.creole"])], # README used in unittest test_setup_utils.py
     entry_points={
         "console_scripts": [
             "creole2html = creole.cmdline:cli_creole2html",
