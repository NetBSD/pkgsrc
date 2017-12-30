$NetBSD: patch-mezzanine_generic_tests.py,v 1.1 2017/12/30 13:44:21 adam Exp $

Django 1.11 support.
https://github.com/stephenmcd/mezzanine/pull/1750

--- mezzanine/generic/tests.py.orig	2017-12-25 08:42:20.000000000 +0000
+++ mezzanine/generic/tests.py
@@ -170,7 +170,7 @@ class GenericTests(TestCase):
 
         result = template.render(Context(context))
 
-        self.assertIn(
+        self.assertInHTML(
             '<input id="id_object_pk" name="object_pk" '
             'type="hidden" value="%d" />' % context['post2'].pk,
             result
