$NetBSD: patch-setup.py,v 1.1 2021/09/26 15:21:30 mef Exp $

UnicodeDecodeError: 'ascii' codec can't decode byte 0xc3 in position 356: ordinal not in range(128)
*** Error code 1

--- setup.py.orig	2021-09-27 00:10:19.151518709 +0900
+++ setup.py	2021-09-27 00:16:39.319538592 +0900
@@ -3,6 +3,7 @@
 """Setup package."""
 from setuptools import setup, find_packages
 import os
+import sys
 import importlib
 
 
@@ -31,7 +32,7 @@ def get_requirements(req):
 def get_description():
     """Get long description."""
 
-    with open("README.md", 'r') as f:
+    with open("README.md", **({'encoding': 'UTF-8'} if sys.version_info.major>=3 else {})) as f:
         desc = f.read()
     return desc
 
