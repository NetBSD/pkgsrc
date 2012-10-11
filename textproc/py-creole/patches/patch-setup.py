$NetBSD: patch-setup.py,v 1.1 2012/10/11 15:35:09 wen Exp $

Install README.creole into right directory.

--- setup.py.orig	2012-10-11 06:13:34.000000000 +0000
+++ setup.py
@@ -44,7 +44,7 @@ setup(
     url='http://code.google.com/p/python-creole/',
     packages=find_packages(),
     include_package_data=True, # include package data under svn source control
-    data_files=[("", ["README.creole"])], # README used in unittest test_setup_utils.py
+    data_files=[("share/doc/py-creole", ["README.creole"])], # README used in unittest test_setup_utils.py
     zip_safe=True, # http://packages.python.org/distribute/setuptools.html#setting-the-zip-safe-flag
     keywords="creole markup creole2html html2creole rest2html html2rest html2textile",
     classifiers=[
