$NetBSD: patch-html5lib_tests_sanitizer.py,v 1.1 2024/04/30 09:01:14 wiz Exp $

https://github.com/html5lib/html5lib-python/pull/506

--- html5lib/tests/sanitizer.py.orig	2020-06-22 23:23:02.000000000 +0000
+++ html5lib/tests/sanitizer.py
@@ -13,7 +13,7 @@ class SanitizerFile(pytest.File):
         with codecs.open(str(self.fspath), "r", encoding="utf-8") as fp:
             tests = json.load(fp)
         for i, test in enumerate(tests):
-            yield SanitizerTest(str(i), self, test=test)
+            yield SanitizerTest.from_parent(self, name=str(i), test=test)
 
 
 class SanitizerTest(pytest.Item):
