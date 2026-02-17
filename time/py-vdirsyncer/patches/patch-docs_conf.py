$NetBSD: patch-docs_conf.py,v 1.4 2026/02/17 10:47:28 wiz Exp $

Fix setuptools 82 compat.
https://github.com/pimutils/vdirsyncer/commit/5c470a0933d4dcd291fb38f62cff1a504277762a

--- docs/conf.py.orig	2025-08-28 20:57:38.000000000 +0000
+++ docs/conf.py
@@ -3,7 +3,7 @@ import os
 import datetime
 import os
 
-from pkg_resources import get_distribution
+import vdirsyncer
 
 extensions = ["sphinx.ext.autodoc"]
 
@@ -17,7 +17,7 @@ copyright = "2014-{}, Markus Unterwaditzer & contribut
     datetime.date.today().strftime("%Y")
 )
 
-release = get_distribution("vdirsyncer").version
+release = vdirsyncer.__version__
 version = ".".join(release.split(".")[:2])  # The short X.Y version.
 
 rst_epilog = ".. |vdirsyncer_version| replace:: %s" % release
