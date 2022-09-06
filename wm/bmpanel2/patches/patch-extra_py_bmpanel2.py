$NetBSD: patch-extra_py_bmpanel2.py,v 1.1 2022/09/06 09:26:27 nia Exp $

Python 3 fix.

https://github.com/SpartanJ/bmpanel2/commit/9d67757d915c7b707cc48a50c8cf97aa7c7a3513

--- extra/py/bmpanel2.py.orig	2022-09-06 08:51:15.418160728 +0000
+++ extra/py/bmpanel2.py
@@ -140,7 +140,7 @@ class ConfigNode:
 		for c in self.children:
 			if c.name == item:
 				return c
-		raise KeyError, item
+		raise KeyError
 
 #----------------------------------------------------------------------
 # ConfigFormat
