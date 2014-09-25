$NetBSD: patch-libgnome-desktop_libgsystem_gsystem-file-utils.c,v 1.3 2014/09/25 15:10:21 prlw1 Exp $

https://bugzilla.gnome.org/show_bug.cgi?id=737369

--- libgnome-desktop/libgsystem/gsystem-file-utils.c.orig	2013-10-04 22:18:43.000000000 +0000
+++ libgnome-desktop/libgsystem/gsystem-file-utils.c
@@ -444,7 +444,11 @@ gs_file_open_dir_fd (GFile         *path
                      GError       **error)
 {
   /* Linux specific probably */
+#ifdef O_DIRECTORY
   *out_fd = open (gs_file_get_path_cached (path), O_RDONLY | O_NONBLOCK | O_DIRECTORY | O_CLOEXEC);
+#else
+  *out_fd = open (gs_file_get_path_cached (path), O_RDONLY | O_NONBLOCK | O_CLOEXEC);
+#endif
   if (*out_fd == -1)
     {
       _set_error_from_errno (error);
