$NetBSD: patch-daemon_gdm-x-session.c,v 1.1 2021/04/16 13:57:52 cirnatdan Exp $

Replace unsupported HOST_NAME_MAX with _POSIX_HOST_NAME_MAX

--- daemon/gdm-x-session.c.orig	2020-12-15 18:16:43.000000000 +0000
+++ daemon/gdm-x-session.c
@@ -114,7 +114,7 @@ prepare_auth_file (void)
         GError   *error = NULL;
         gboolean  prepared = FALSE;
         Xauth     auth_entry = { 0 };
-        char      localhost[HOST_NAME_MAX + 1] = "";
+        char      localhost[_POSIX_HOST_NAME_MAX + 1] = "";
 
         g_debug ("Preparing auth file for X server");
 
@@ -124,7 +124,7 @@ prepare_auth_file (void)
                 return NULL;
         }
 
-        if (gethostname (localhost, HOST_NAME_MAX) < 0) {
+        if (gethostname (localhost, _POSIX_HOST_NAME_MAX) < 0) {
                 strncpy (localhost, "localhost", sizeof (localhost) - 1);
         }
 
