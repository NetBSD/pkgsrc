$NetBSD: patch-setup.py,v 1.3 2023/05/05 11:58:17 wiz Exp $

Relax test requirements.

--- setup.py.orig	2023-02-08 01:57:37.000000000 +0000
+++ setup.py
@@ -225,7 +225,7 @@ with open('requirements-dev.txt') as f:
 
 # for testing by users with "python setup.py test" (not Tox, which we use)
 test_requirements = [
-    "pytest>=2.8.6,<3.3.0",             # MIT license
+    "pytest",             # MIT license
 ]
 
 
