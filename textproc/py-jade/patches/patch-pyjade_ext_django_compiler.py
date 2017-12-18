$NetBSD: patch-pyjade_ext_django_compiler.py,v 1.1 2017/12/18 11:09:14 adam Exp $

Django 1.11 compatibility fix:
https://github.com/DMOJ/pyjade/commit/bc21f900e9041c85f3989252881aef4a4bf1132d

--- pyjade/ext/django/compiler.py.orig	2017-12-18 10:52:52.000000000 +0000
+++ pyjade/ext/django/compiler.py
@@ -88,8 +88,13 @@ def decorate_templatize(func):
         return func(html, origin)
 
     return templatize
+try:
+    trans_real.templatize = decorate_templatize(trans_real.templatize)
+except AttributeError:
+    # Django 1.11 moved templatize to separate module
+    from django.utils.translation import template
 
-trans_real.templatize = decorate_templatize(trans_real.templatize)
+    template.templatize = decorate_templatize(template.templatize)
 
 try:
     from django.contrib.markup.templatetags.markup import markdown
