$NetBSD: patch-binary__database__files_management_commands_database__files__cleanup.py,v 1.1 2020/08/04 01:14:36 joerg Exp $

PR #26

--- binary_database_files/management/commands/database_files_cleanup.py.orig	2020-05-20 16:29:28.000000000 +0000
+++ binary_database_files/management/commands/database_files_cleanup.py
@@ -4,7 +4,7 @@ from django.conf import settings
 from django.core.files.storage import default_storage
 from django.core.management.base import BaseCommand
 from django.db.models import FileField, ImageField
-from django.apps.apps import get_models
+from django.apps import apps
 
 from binary_database_files.models import File
 
@@ -15,8 +15,9 @@ class Command(BaseCommand):
         "Deletes all files in the database that are not referenced by "
         "any model fields."
     )
-    option_list = BaseCommand.option_list + (
-        make_option(
+
+    def add_arguments(self, parser):
+        parser.add_argument(
             "--dryrun",
             action="store_true",
             dest="dryrun",
@@ -24,14 +25,13 @@ class Command(BaseCommand):
             help=(
                 "If given, only displays the names of orphaned files "
                 "and does not delete them."
-            ),
-        ),
-        make_option(
+            )
+        )
+        parser.add_argument(
             "--filenames",
             default="",
             help="If given, only files with these names will be checked",
-        ),
-    )
+        )
 
     def handle(self, *args, **options):
         tmp_debug = settings.DEBUG
@@ -40,7 +40,7 @@ class Command(BaseCommand):
         dryrun = options["dryrun"]
         filenames = {_.strip() for _ in options["filenames"].split(",") if _.strip()}
         try:
-            for model in get_models():
+            for model in apps.get_models():
                 print("Checking model %s..." % (model,))
                 for field in model._meta.fields:
                     if not isinstance(field, (FileField, ImageField)):
