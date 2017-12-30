$NetBSD: patch-mezzanine_generic_templatetags_rating__tags.py,v 1.1 2017/12/30 13:44:21 adam Exp $

Django 1.11 support.
https://github.com/stephenmcd/mezzanine/pull/1750

--- mezzanine/generic/templatetags/rating_tags.py.orig	2016-01-17 01:21:39.000000000 +0000
+++ mezzanine/generic/templatetags/rating_tags.py
@@ -21,4 +21,4 @@ def rating_for(context, obj):
     rating_name = obj.get_ratingfield_name()
     for f in ("average", "count", "sum"):
         context["rating_" + f] = getattr(obj, "%s_%s" % (rating_name, f))
-    return context
+    return context.flatten()
