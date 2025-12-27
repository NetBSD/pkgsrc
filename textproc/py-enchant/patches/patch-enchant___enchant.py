$NetBSD: patch-enchant___enchant.py,v 1.2 2025/12/27 14:27:04 adam Exp $

Always return a path to libenchant2 from pkgsrc.

--- enchant/_enchant.py.orig	2025-09-14 16:18:17.000000000 +0000
+++ enchant/_enchant.py
@@ -134,24 +134,7 @@ def find_message(*args: str) -> None:
 
 
 def find_c_enchant_lib() -> Optional[str]:
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
