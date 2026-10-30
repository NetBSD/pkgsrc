$NetBSD: patch-setup.py,v 1.2 2026/10/30 19:28:43 adam Exp $

Skip data_files as they conflict between Python versions.

--- setup.py.orig	2026-10-29 16:09:29.000000000 +0000
+++ setup.py
@@ -39,17 +39,4 @@ use.""",
         "Topic :: Software Development :: Libraries :: Python Modules",
     ],
     packages=["iniparse"],
-    data_files=[
-        (
-            "share/doc/iniparse-%s" % VERSION,
-            [
-                "README.md",
-                "LICENSE-PSF",
-                "LICENSE",
-                "Changelog",
-                "html/index.html",
-                "html/style.css",
-            ],
-        ),
-    ],
 )
