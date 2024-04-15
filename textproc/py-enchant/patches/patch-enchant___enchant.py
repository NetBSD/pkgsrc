$NetBSD: patch-enchant___enchant.py,v 1.1 2024/04/15 05:27:47 adam Exp $

Always return a path to libenchant2 from pkgsrc.

--- enchant/_enchant.py.orig	2024-04-15 05:19:38.294407367 +0000
+++ enchant/_enchant.py
@@ -124,24 +124,7 @@ def find_message(*args):
 
 
 def find_c_enchant_lib():
-    verbose = os.environ.get("PYENCHANT_VERBOSE_FIND")
-    if verbose:
-        global VERBOSE_FIND
-        VERBOSE_FIND = True
-    prefix = os.environ.get("PYENCHANT_ENCHANT_PREFIX")
-    if prefix:
-        return from_prefix(prefix)
-
-    library_path = os.environ.get("PYENCHANT_LIBRARY_PATH")
-    if library_path:
-        return from_env_var(library_path)
-
-    from_package = from_package_resources()
-    if from_package:
-        return from_package
-
-    # Last chance
-    return from_system()
+    return "@PYENCHANT_LIBRARY_PATH@"
 
 
 enchant_lib_path = find_c_enchant_lib()
