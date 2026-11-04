$NetBSD: patch-setup.py,v 1.3 2026/11/04 07:09:15 adam Exp $

Skip data_files as they conflict between Python versions.

--- setup.py.orig	2026-11-03 15:12:20.121489000 +0000
+++ setup.py
@@ -37,17 +37,4 @@ use.""",
     ],
     python_requires=">=3.9",
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
