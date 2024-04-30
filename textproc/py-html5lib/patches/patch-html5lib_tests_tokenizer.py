$NetBSD: patch-html5lib_tests_tokenizer.py,v 1.1 2024/04/30 09:01:14 wiz Exp $

https://github.com/html5lib/html5lib-python/pull/506

--- html5lib/tests/tokenizer.py.orig	2020-06-22 23:23:02.000000000 +0000
+++ html5lib/tests/tokenizer.py
@@ -192,7 +192,7 @@ class TokenizerFile(pytest.File):
             tests = json.load(fp)
         if 'tests' in tests:
             for i, test in enumerate(tests['tests']):
-                yield TokenizerTestCollector(str(i), self, testdata=test)
+                yield TokenizerTestCollector.from_parent(self, name=str(i), testdata=test)
 
 
 class TokenizerTestCollector(pytest.Collector):
@@ -207,10 +207,10 @@ class TokenizerTestCollector(pytest.Coll
     def collect(self):
         for initialState in self.testdata["initialStates"]:
             initialState = capitalize(initialState)
-            item = TokenizerTest(initialState,
-                                 self,
-                                 self.testdata,
-                                 initialState)
+            item = TokenizerTest.from_parent(self,
+                                             name=initialState,
+                                             test=self.testdata,
+                                             initialState=initialState)
             if self.testdata["input"] is None:
                 item.add_marker(pytest.mark.skipif(True, reason="Relies on lone surrogates"))
             yield item
