$NetBSD: patch-panel-plugin_model__user.c,v 1.1 2015/04/21 08:56:45 jperkin Exp $

Fix inline use.
--- panel-plugin/model_user.c.orig	2013-11-10 14:34:13.000000000 +0000
+++ panel-plugin/model_user.c
@@ -60,7 +60,7 @@ typedef struct
 
 } PBUserData;
 
-static inline time_t
+static time_t
 pbuser_get_mtime(const gchar *filename)
 {
     struct stat buf;
@@ -70,7 +70,7 @@ pbuser_get_mtime(const gchar *filename)
         return 1;
 }
 
-static inline gboolean
+static gboolean
 pbuser_dir_exists(const gchar *path)
 {
     return g_file_test(path, G_FILE_TEST_IS_DIR);
