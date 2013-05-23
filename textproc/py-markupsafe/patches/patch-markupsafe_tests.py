$NetBSD: patch-markupsafe_tests.py,v 1.1 2013/05/23 15:08:26 joerg Exp $

--- markupsafe/tests.py.orig	2013-05-23 10:40:08.000000000 +0000
+++ markupsafe/tests.py
@@ -48,16 +48,16 @@ class MarkupTestCase(unittest.TestCase):
         self.assertEqual(Markup('<em>%s:%s</em>') % (
             '<foo>',
             '<bar>',
-        ), Markup(u'<em>&lt;foo&gt;:&lt;bar&gt;</em>'))
+        ), Markup('<em>&lt;foo&gt;:&lt;bar&gt;</em>'))
 
     def test_dict_interpol(self):
         self.assertEqual(Markup('<em>%(foo)s</em>') % {
             'foo': '<foo>',
-        }, Markup(u'<em>&lt;foo&gt;</em>'))
+        }, Markup('<em>&lt;foo&gt;</em>'))
         self.assertEqual(Markup('<em>%(foo)s:%(bar)s</em>') % {
             'foo': '<foo>',
             'bar': '<bar>',
-        }, Markup(u'<em>&lt;foo&gt;:&lt;bar&gt;</em>'))
+        }, Markup('<em>&lt;foo&gt;:&lt;bar&gt;</em>'))
 
     def test_escaping(self):
         # escaping and unescaping
@@ -73,7 +73,7 @@ class MarkupTestCase(unittest.TestCase):
     def test_escape_silent(self):
         assert escape_silent(None) == Markup()
         assert escape(None) == Markup(None)
-        assert escape_silent('<foo>') == Markup(u'&lt;foo&gt;')
+        assert escape_silent('<foo>') == Markup('&lt;foo&gt;')
 
     def test_splitting(self):
         self.assertEqual(Markup('a b').split(), [
@@ -101,8 +101,8 @@ class MarkupLeakTestCase(unittest.TestCa
             for item in range(1000):
                 escape("foo")
                 escape("<foo>")
-                escape(u"foo")
-                escape(u"<foo>")
+                escape("foo")
+                escape("<foo>")
             counts.add(len(gc.get_objects()))
         assert len(counts) == 1, 'ouch, c extension seems to leak objects'
 
