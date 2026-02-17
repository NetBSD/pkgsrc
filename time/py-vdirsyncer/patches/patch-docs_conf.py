$NetBSD: patch-docs_conf.py,v 1.3 2026/02/17 08:41:47 wiz Exp $

Fix setuptools 82 compat.
https://github.com/pimutils/vdirsyncer/issues/1062

--- docs/conf.py.orig	2025-08-28 20:57:38.000000000 +0000
+++ docs/conf.py
@@ -3,7 +3,7 @@ import os
 import datetime
 import os
 
-from pkg_resources import get_distribution
+from importlib.metadata import version
 
 extensions = ["sphinx.ext.autodoc"]
 
@@ -17,7 +17,7 @@ copyright = "2014-{}, Markus Unterwaditzer & contribut
     datetime.date.today().strftime("%Y")
 )
 
-release = get_distribution("vdirsyncer").version
+release = version('vdirsyncer')
 version = ".".join(release.split(".")[:2])  # The short X.Y version.
 
 rst_epilog = ".. |vdirsyncer_version| replace:: %s" % release
