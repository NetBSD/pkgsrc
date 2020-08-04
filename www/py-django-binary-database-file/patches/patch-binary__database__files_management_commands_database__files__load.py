$NetBSD: patch-binary__database__files_management_commands_database__files__load.py,v 1.1 2020/08/04 01:14:36 joerg Exp $

PR #26

--- binary_database_files/management/commands/database_files_load.py.orig	2020-05-20 16:29:28.000000000 +0000
+++ binary_database_files/management/commands/database_files_load.py
@@ -1,28 +1,27 @@
 import os
-from optparse import make_option
 
 from django.conf import settings
 from django.core.management.base import BaseCommand
 from django.db.models import FileField, ImageField
-from django.apps.apps import get_models
+from django.apps import apps
 
 
 class Command(BaseCommand):
-    option_list = BaseCommand.option_list + (
-        make_option(
-            "-m",
-            "--models",
-            dest="models",
-            default="",
-            help="A list of models to search for file fields. Default is all.",
-        ),
-    )
     help = (
         "Loads all files on the filesystem referenced by FileFields "
         "or ImageFields into the database. This should only need to be "
         "done once, when initially migrating a legacy system."
     )
 
+    def add_arguments(self, parser):
+        parser.add_argument(
+            "-m",
+            "--models",
+            dest="models",
+            default="",
+            help="A list of models to search for file fields. Default is all."
+        )
+
     def handle(self, *args, **options):
         show_files = int(options.get("verbosity", 1)) >= 2
         all_models = [
@@ -32,8 +31,8 @@ class Command(BaseCommand):
         settings.DEBUG = False
         try:
             broken = 0  # Number of db records referencing missing files.
-            for model in get_models():
-                key = "%s.%s" % (model._meta.app_label, model._meta.module_name)
+            for model in apps.get_models():
+                key = "%s.%s" % (model._meta.app_label, model._meta.model_name)
                 key = key.lower()
                 if all_models and key not in all_models:
                     continue
