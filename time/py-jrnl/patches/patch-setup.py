$NetBSD: patch-setup.py,v 1.1 2017/12/19 14:26:21 leot Exp $

Be more permissive regarding version requirements.

--- setup.py.orig	2014-11-06 10:33:36.000000000 +0000
+++ setup.py
@@ -70,7 +70,7 @@ conditional_dependencies = {
     "readline>=6.2": not readline_available and "win32" not in sys.platform,
     "colorama>=0.2.5": "win32" in sys.platform,
     "argparse>=1.1.0": sys.version.startswith("2.6"),
-    "python-dateutil==1.5": sys.version.startswith("2."),
+    "python-dateutil>=1.5": sys.version.startswith("2."),
     "python-dateutil>=2.2": sys.version.startswith("3."),
 }
 
