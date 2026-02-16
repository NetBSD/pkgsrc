$NetBSD: patch-html5lib_tests_conftest.py,v 1.2 2026/02/16 19:01:02 wiz Exp $

https://github.com/html5lib/html5lib-python/pull/506

--- html5lib/tests/conftest.py.orig	2020-06-22 23:23:02.000000000 +0000
+++ html5lib/tests/conftest.py
@@ -2,7 +2,6 @@ import sys
 import os.path
 import sys
 
-import pkg_resources
 import pytest
 
 from .tree_construction import TreeConstructionFile
@@ -63,17 +62,6 @@ def pytest_configure(config):
                             spec, marker = line.strip().split(";", 1)
                         else:
                             spec, marker = line.strip(), None
-                        req = pkg_resources.Requirement.parse(spec)
-                        if marker and not pkg_resources.evaluate_marker(marker):
-                            msgs.append("%s not available in this environment" % spec)
-                        else:
-                            try:
-                                installed = pkg_resources.working_set.find(req)
-                            except pkg_resources.VersionConflict:
-                                msgs.append("Outdated version of %s installed, need %s" % (req.name, spec))
-                            else:
-                                if not installed:
-                                    msgs.append("Need %s" % spec)
 
         # Check cElementTree
         import xml.etree.ElementTree as ElementTree
@@ -99,10 +87,19 @@ def pytest_collect_file(path, parent):
 
     if _tree_construction in dir_and_parents:
         if path.ext == ".dat":
-            return TreeConstructionFile(path, parent)
+            return TreeConstructionFile.from_parent(parent, fspath=path)
     elif _tokenizer in dir_and_parents:
         if path.ext == ".test":
-            return TokenizerFile(path, parent)
+            return TokenizerFile.from_parent(parent, fspath=path)
     elif _sanitizer_testdata in dir_and_parents:
         if path.ext == ".dat":
-            return SanitizerFile(path, parent)
+            return SanitizerFile.from_parent(parent, fspath=path)
+
+
+# Tiny wrapper to allow .from_parent constructors on older pytest for PY27
+if not hasattr(pytest.Item.__base__, "from_parent"):
+    @classmethod
+    def from_parent(cls, parent, **kwargs):
+        return cls(parent=parent, **kwargs)
+
+    pytest.Item.__base__.from_parent = from_parent
