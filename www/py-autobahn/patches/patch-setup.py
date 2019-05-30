$NetBSD: patch-setup.py,v 1.1 2019/05/30 09:10:13 adam Exp $

Relax test requirements.

--- setup.py.orig	2018-08-19 10:45:51.000000000 +0000
+++ setup.py
@@ -167,7 +167,7 @@ if PY3:
 
 # for testing by users with "python setup.py test" (not Tox, which we use)
 test_requirements = [
-    "pytest>=2.8.6,<3.3.0",             # MIT license
+    "pytest>=2.8.6",                    # MIT license
     "mock>=1.3.0",                      # BSD license
 ]
 
