$NetBSD: patch-hatch_build.py,v 1.1 2023/11/09 19:12:11 adam Exp $

Do not fetch files.

--- hatch_build.py.orig	2023-11-09 19:09:41.226235299 +0000
+++ hatch_build.py
@@ -82,4 +82,3 @@ class CustomHook(BuildHookInterface):
         """Initialize the hook."""
         if self.target_name not in ["wheel", "sdist"]:
             return
-        _get_css_files()
