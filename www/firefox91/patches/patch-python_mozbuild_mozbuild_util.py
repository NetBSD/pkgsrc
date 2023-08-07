$NetBSD: patch-python_mozbuild_mozbuild_util.py,v 1.1 2023/08/07 13:28:04 abs Exp $

Update for modern (>3.9) python open() mode

--- python/mozbuild/mozbuild/util.py.orig	2022-08-15 18:05:01.000000000 +0000
+++ python/mozbuild/mozbuild/util.py
@@ -225,7 +225,7 @@ class FileAvoidWrite(BytesIO):
     still occur, as well as diff capture if requested.
     """
 
-    def __init__(self, filename, capture_diff=False, dry_run=False, readmode="rU"):
+    def __init__(self, filename, capture_diff=False, dry_run=False, readmode="r"):
         BytesIO.__init__(self)
         self.name = filename
         assert type(capture_diff) == bool
@@ -1447,7 +1447,7 @@ def patch_main():
 
         def my_get_command_line():
             with open(
-                os.path.join(os.path.dirname(__file__), "fork_interpose.py"), "rU"
+                os.path.join(os.path.dirname(__file__), "fork_interpose.py"), "r"
             ) as fork_file:
                 fork_code = fork_file.read()
             # Add our relevant globals.
