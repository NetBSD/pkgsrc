$NetBSD: patch-html5lib_tests_tree__construction.py,v 1.1 2024/04/30 09:01:14 wiz Exp $

https://github.com/html5lib/html5lib-python/pull/506

--- html5lib/tests/tree_construction.py.orig	2020-06-22 23:23:02.000000000 +0000
+++ html5lib/tests/tree_construction.py
@@ -26,7 +26,7 @@ class TreeConstructionFile(pytest.File):
     def collect(self):
         tests = TestData(str(self.fspath), "data")
         for i, test in enumerate(tests):
-            yield TreeConstructionTest(str(i), self, testdata=test)
+            yield TreeConstructionTest.from_parent(self, name=str(i), testdata=test)
 
 
 class TreeConstructionTest(pytest.Collector):
@@ -48,11 +48,11 @@ class TreeConstructionTest(pytest.Collec
                 nodeid = "%s::parser::namespaced" % treeName
             else:
                 nodeid = "%s::parser::void-namespace" % treeName
-            item = ParserTest(nodeid,
-                              self,
-                              self.testdata,
-                              treeAPIs["builder"] if treeAPIs is not None else None,
-                              namespaceHTMLElements)
+            item = ParserTest.from_parent(self,
+                                          name=nodeid,
+                                          test=self.testdata,
+                                          treeClass=treeAPIs["builder"] if treeAPIs is not None else None,
+                                          namespaceHTMLElements=namespaceHTMLElements)
             item.add_marker(getattr(pytest.mark, treeName))
             item.add_marker(pytest.mark.parser)
             if namespaceHTMLElements:
@@ -61,10 +61,10 @@ class TreeConstructionTest(pytest.Collec
 
     def _getTreeWalkerTests(self, treeName, treeAPIs):
         nodeid = "%s::treewalker" % treeName
-        item = TreeWalkerTest(nodeid,
-                              self,
-                              self.testdata,
-                              treeAPIs)
+        item = TreeWalkerTest.from_parent(self,
+                                          name=nodeid,
+                                          test=self.testdata,
+                                          treeAPIs=treeAPIs)
         item.add_marker(getattr(pytest.mark, treeName))
         item.add_marker(pytest.mark.treewalker)
         yield item
