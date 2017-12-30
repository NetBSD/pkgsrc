$NetBSD: patch-mezzanine_template_____init____.py,v 1.1 2017/12/30 13:44:21 adam Exp $

Django 1.11 support.
https://github.com/stephenmcd/mezzanine/pull/1750

--- mezzanine/template/__init__.py.orig	2017-03-10 16:47:14.000000000 +0000
+++ mezzanine/template/__init__.py
@@ -7,6 +7,7 @@ from django import template
 from django import VERSION as DJANGO_VERSION
 from django.template.context import Context
 from django.template.loader import get_template, select_template
+from django.utils.html import conditional_escape
 
 from mezzanine.utils.device import templates_for_device
 
@@ -127,9 +128,9 @@ class Library(template.Library):
                         if takes_context:
                             parts.insert(0, context)
                         result = tag_func(*parts)
-                        autoescape = context.autoescape
-                        context = context_class(result, autoescape=autoescape)
-                        return self.template.render(context)
+                        if context.autoescape:
+                            result = conditional_escape(result)
+                        return self.template.render(context.flatten())
 
                 return InclusionTagNode()
             return self.tag(tag_wrapper)
