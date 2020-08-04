$NetBSD: patch-binary__database__files_management_commands_database__files__dump.py,v 1.1 2020/08/04 01:14:36 joerg Exp $

PR #26

--- binary_database_files/management/commands/database_files_dump.py.orig	2020-08-03 11:40:23.568616679 +0000
+++ binary_database_files/management/commands/database_files_dump.py
@@ -4,11 +4,6 @@ from binary_database_files.models import
 
 
 class Command(BaseCommand):
-    option_list = BaseCommand.option_list + (
-        #        make_option('-w', '--overwrite', action='store_true',
-        #            dest='overwrite', default=False,
-        #            help='If given, overwrites any existing files.'),
-    )
     help = (
         "Dumps all files in the database referenced by FileFields "
         "or ImageFields onto the filesystem in the directory specified by "
