$NetBSD: patch-mezzanine_pages_templatetags_pages__tags.py,v 1.1 2017/12/30 13:44:21 adam Exp $

Django 1.11 support.
https://github.com/stephenmcd/mezzanine/pull/1750

--- mezzanine/pages/templatetags/pages_tags.py.orig	2016-01-17 01:21:39.000000000 +0000
+++ mezzanine/pages/templatetags/pages_tags.py
@@ -4,7 +4,7 @@ from future.builtins import str
 from collections import defaultdict
 
 from django.core.exceptions import ImproperlyConfigured
-from django.template import Context, TemplateSyntaxError, Variable
+from django.template import TemplateSyntaxError, Variable
 from django.template.loader import get_template
 from django.utils.translation import ugettext_lazy as _
 
@@ -131,7 +131,7 @@ def page_menu(context, token):
             context["page_branch_in_footer"] = True
 
     t = get_template(template_name)
-    return t.render(Context(context))
+    return t.render(context.flatten())
 
 
 @register.as_tag
