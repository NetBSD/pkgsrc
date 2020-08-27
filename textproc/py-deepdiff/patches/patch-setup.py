$NetBSD: patch-setup.py,v 1.1 2020/08/27 12:28:47 joerg Exp $

--- setup.py.orig	2020-08-26 11:48:18.731049062 +0000
+++ setup.py
@@ -22,7 +22,7 @@ def get_reqs(filename):
 
 reqs = get_reqs("requirements.txt")
 
-with open('README.md') as file:
+with open('README.md', **({'encoding': 'UTF-8'} if sys.version_info.major>=3 else {})) as file:
     long_description = file.read()
 
 
