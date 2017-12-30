$NetBSD: patch-mezzanine_blog_templatetags_blog__tags.py,v 1.1 2017/12/30 13:44:21 adam Exp $

Django 1.11 support.
https://github.com/stephenmcd/mezzanine/pull/1750

--- mezzanine/blog/templatetags/blog_tags.py.orig	2017-12-25 08:31:08.000000000 +0000
+++ mezzanine/blog/templatetags/blog_tags.py
@@ -94,4 +94,4 @@ def quick_blog(context):
     Admin dashboard tag for the quick blog form.
     """
     context["form"] = BlogPostForm()
-    return context
+    return context.flatten()
