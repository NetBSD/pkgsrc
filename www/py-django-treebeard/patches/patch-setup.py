$NetBSD: patch-setup.py,v 1.1 2021/01/30 07:23:29 mef Exp $

Fix build for py36:

raceback (most recent call last):
  File "setup.py", line 10, in <module>
    long_description = fh.read()
  File "/usr/pkg/lib/python3.6/encodings/ascii.py", line 26, in decode
    return codecs.ascii_decode(input, self.errors)[0]
UnicodeDecodeError: 'ascii' codec can't decode byte 0xc3 in position 175: ordinal not in range(128)
*** Error code 1

--- setup.py.orig	2021-01-13 18:18:36.000000000 +0900
+++ setup.py	2021-01-30 16:15:37.800803620 +0900
@@ -1,12 +1,13 @@
 #!/usr/bin/env python
 # -*- coding: utf-8 -*-
 import os
+import sys
 from setuptools import setup, find_packages
 from treebeard import __version__
 import codecs
 
 
-with open('README.md') as fh:
+with open("README.md", **({'encoding': 'UTF-8'} if sys.version_info.major>=3 else {})) as fh:
     long_description = fh.read()
 
 
