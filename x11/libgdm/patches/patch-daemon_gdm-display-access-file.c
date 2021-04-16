$NetBSD: patch-daemon_gdm-display-access-file.c,v 1.1 2021/04/16 13:57:52 cirnatdan Exp $

HOST_NAME_MAX is not available on NetBSD
Maybe replace this with MAXHOSTNAMELEN?

--- daemon/gdm-display-access-file.c.orig	2020-12-15 18:16:43.000000000 +0000
+++ daemon/gdm-display-access-file.c
@@ -441,9 +441,9 @@ _get_auth_info_for_display (GdmDisplayAc
                  *
                  * https://bugs.freedesktop.org/show_bug.cgi?id=43425
                  */
-                char localhost[HOST_NAME_MAX + 1] = "";
+                char localhost[_POSIX_HOST_NAME_MAX + 1] = "";
                 *family = FamilyLocal;
-                if (gethostname (localhost, HOST_NAME_MAX) == 0) {
+                if (gethostname (localhost, _POSIX_HOST_NAME_MAX) == 0) {
                         *address = g_strdup (localhost);
                 } else {
                         *address = g_strdup ("localhost");
