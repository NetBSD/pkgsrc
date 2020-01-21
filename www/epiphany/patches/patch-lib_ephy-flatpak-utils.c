$NetBSD: patch-lib_ephy-flatpak-utils.c,v 1.1 2020/01/21 15:02:08 nia Exp $

Add missing stub for !linux.

--- lib/ephy-flatpak-utils.c.orig	2019-11-22 21:24:16.000000000 +0000
+++ lib/ephy-flatpak-utils.c
@@ -285,4 +285,9 @@ ephy_open_file_via_flatpak_portal_finish
   g_assert_not_reached ();
 }
 
+void
+ephy_flatpak_utils_set_is_web_process_extension (void)
+{
+}
+
 #endif /* __linux__ */
