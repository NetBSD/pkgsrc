$NetBSD: patch-setup.py,v 1.1 2017/10/31 09:22:22 jperkin Exp $

Fix python27.

--- setup.py.orig	2017-07-27 20:19:27.000000000 +0000
+++ setup.py
@@ -1,6 +1,7 @@
 #!/usr/bin/env python
 # -*- coding: utf-8 -*-
 
+import io
 import os
 import sys
 import codecs
@@ -39,7 +40,7 @@ packages = [
 
 # About dict to store version and package info
 about = dict()
-with open(os.path.join(here, 'maya', '__version__.py'), 'r', encoding='utf-8') as f:
+with io.open(os.path.join(here, 'maya', '__version__.py'), mode='r', encoding='utf-8') as f:
     exec(f.read(), about)
 
 setup(
