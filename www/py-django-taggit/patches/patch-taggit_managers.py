$NetBSD: patch-taggit_managers.py,v 1.1 2020/08/11 18:41:26 joerg Exp $

Allow building with Python 2.

--- taggit/managers.py.orig	2020-08-10 00:00:37.878508159 +0000
+++ taggit/managers.py
@@ -234,11 +234,12 @@ class _TaggableManager(models.Manager):
 
         for new_tag in tags_to_create:
             if case_insensitive:
-                lookup = {"name__iexact": new_tag, **tag_kwargs}
+                lookup = {"name__iexact": new_tag}
             else:
-                lookup = {"name": new_tag, **tag_kwargs}
+                lookup = {"name": new_tag}
+            lookup.update(tag_kwargs)
 
-            tag, create = manager.get_or_create(**lookup, defaults={"name": new_tag})
+            tag, create = manager.get_or_create(defaults={"name": new_tag}, **lookup)
             tag_objs.add(tag)
 
         return tag_objs
