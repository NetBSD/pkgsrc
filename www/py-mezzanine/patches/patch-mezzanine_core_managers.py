$NetBSD: patch-mezzanine_core_managers.py,v 1.1 2017/12/30 13:44:21 adam Exp $

Django 1.11 support.
https://github.com/stephenmcd/mezzanine/pull/1750

--- mezzanine/core/managers.py.orig	2016-08-12 00:47:57.000000000 +0000
+++ mezzanine/core/managers.py
@@ -187,7 +187,7 @@ class SearchableQuerySet(QuerySet):
             self._search_ordered = len(self._search_terms) > 0
         return super(SearchableQuerySet, self).order_by(*field_names)
 
-    def iterator(self):
+    def annotate_scores(self):
         """
         If search has occurred and no ordering has occurred, decorate
         each result with the number of search terms so that it can be
@@ -351,7 +351,8 @@ class SearchableManager(Manager):
                 queryset = model.objects.published(for_user=user)
             except AttributeError:
                 queryset = model.objects.get_queryset()
-            all_results.extend(queryset.search(*args, **kwargs))
+            all_results.extend(
+                queryset.search(*args, **kwargs).annotate_scores())
         return sorted(all_results, key=lambda r: r.result_count, reverse=True)
 
 
