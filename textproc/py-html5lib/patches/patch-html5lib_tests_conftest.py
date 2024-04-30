$NetBSD: patch-html5lib_tests_conftest.py,v 1.1 2024/04/30 09:01:14 wiz Exp $

https://github.com/html5lib/html5lib-python/pull/506

--- html5lib/tests/conftest.py.orig	2020-06-22 23:23:02.000000000 +0000
+++ html5lib/tests/conftest.py
@@ -99,10 +99,19 @@ def pytest_collect_file(path, parent):
 
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
