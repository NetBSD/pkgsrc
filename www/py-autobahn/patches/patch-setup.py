$NetBSD: patch-setup.py,v 1.2 2020/01/23 14:33:18 adam Exp $

Relax test requirements.

--- setup.py.orig	2020-01-14 15:21:43.000000000 +0000
+++ setup.py
@@ -155,7 +155,7 @@ extras_require_dev = [
 
     # pytest 3.3.0 has dropped support for Python 3.3
     # https://docs.pytest.org/en/latest/changelog.html#pytest-3-3-0-2017-11-23
-    "pytest>=2.8.6,<3.3.0",             # MIT license
+    "pytest>=2.8.6",                    # MIT license
 
     "twine>=1.6.5",                     # Apache 2.0
     'sphinx>=1.2.3',                    # BSD
