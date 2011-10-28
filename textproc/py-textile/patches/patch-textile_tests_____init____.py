$NetBSD: patch-textile_tests_____init____.py,v 1.1 2011/10/28 02:15:10 obache Exp $

* python24 compatibility fix.
 (for python>=25, the list of base classes in a class definition can be empty)

--- textile/tests/__init__.py.orig	2011-05-04 02:19:09.000000000 +0000
+++ textile/tests/__init__.py
@@ -11,7 +11,7 @@ from nose.plugins.skip import SkipTest
 """
 
 
-class TestKnownValues():
+class TestKnownValues:
     xhtml_known_values = (
         ('hello, world', '\t<p>hello, world</p>'),
 
@@ -277,7 +277,7 @@ class TestKnownValues():
         eq_(output, expected_output)
 
 
-class Tests():
+class Tests:
     def testFootnoteReference(self):
         html = textile.textile('YACC[1]')
         assert_true(re.search('^\t<p>YACC<sup class="footnote"><a href="#fn[a-z0-9-]+">1</a></sup></p>', html))
