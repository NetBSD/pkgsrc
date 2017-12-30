$NetBSD: patch-mezzanine_generic_templatetags_comment__tags.py,v 1.1 2017/12/30 13:44:21 adam Exp $

Django 1.11 support.
https://github.com/stephenmcd/mezzanine/pull/1750

--- mezzanine/generic/templatetags/comment_tags.py.orig	2016-08-12 01:16:03.000000000 +0000
+++ mezzanine/generic/templatetags/comment_tags.py
@@ -31,7 +31,7 @@ def comments_for(context, obj):
         'comment_url': reverse("comment"),
         'object_for_comments': obj,
     })
-    return context
+    return context.flatten()
 
 
 @register.inclusion_tag("generic/includes/comment.html", takes_context=True)
@@ -61,7 +61,7 @@ def comment_thread(context, parent):
         "no_comments": parent_id is None and not context["all_comments"],
         "replied_to": replied_to,
     })
-    return context
+    return context.flatten()
 
 
 @register.inclusion_tag("admin/includes/recent_comments.html",
@@ -73,7 +73,7 @@ def recent_comments(context):
     latest = context["settings"].COMMENTS_NUM_LATEST
     comments = ThreadedComment.objects.all().select_related("user")
     context["comments"] = comments.order_by("-id")[:latest]
-    return context
+    return context.flatten()
 
 
 @register.filter
