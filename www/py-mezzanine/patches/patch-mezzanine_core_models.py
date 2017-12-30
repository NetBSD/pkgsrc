$NetBSD: patch-mezzanine_core_models.py,v 1.1 2017/12/30 13:44:21 adam Exp $

Django 1.11 support.
https://github.com/stephenmcd/mezzanine/pull/1750

--- mezzanine/core/models.py.orig	2017-03-10 16:47:14.000000000 +0000
+++ mezzanine/core/models.py
@@ -46,7 +46,8 @@ class SiteRelated(models.Model):
     class Meta:
         abstract = True
 
-    site = models.ForeignKey("sites.Site", editable=False)
+    site = models.ForeignKey("sites.Site", on_delete=models.CASCADE,
+        editable=False)
 
     def save(self, update_site=False, *args, **kwargs):
         """
@@ -67,7 +68,7 @@ class Slugged(SiteRelated):
     """
 
     title = models.CharField(_("Title"), max_length=500)
-    slug = models.CharField(_("URL"), max_length=2000, blank=True, null=True,
+    slug = models.CharField(_("URL"), max_length=2000, blank=True,
             help_text=_("Leave blank to have the URL auto-generated from "
                         "the title."))
 
@@ -485,8 +486,8 @@ class Ownable(models.Model):
     Abstract model that provides ownership of an object for a user.
     """
 
-    user = models.ForeignKey(user_model_name, verbose_name=_("Author"),
-        related_name="%(class)ss")
+    user = models.ForeignKey(user_model_name, on_delete=models.CASCADE,
+        verbose_name=_("Author"), related_name="%(class)ss")
 
     class Meta:
         abstract = True
@@ -555,8 +556,8 @@ class SitePermission(models.Model):
     access.
     """
 
-    user = models.OneToOneField(user_model_name, verbose_name=_("Author"),
-        related_name="%(class)ss")
+    user = models.OneToOneField(user_model_name, on_delete=models.CASCADE,
+        verbose_name=_("Author"), related_name="%(class)ss")
     sites = models.ManyToManyField("sites.Site", blank=True,
                                    verbose_name=_("Sites"))
 
