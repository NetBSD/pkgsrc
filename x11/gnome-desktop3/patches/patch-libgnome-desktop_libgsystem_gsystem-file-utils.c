$NetBSD: patch-libgnome-desktop_libgsystem_gsystem-file-utils.c,v 1.4 2014/11/08 23:15:06 prlw1 Exp $

https://bugzilla.gnome.org/show_bug.cgi?id=737369

--- libgnome-desktop/libgsystem/gsystem-file-utils.c.orig	2014-06-03 15:05:13.000000000 +0000
+++ libgnome-desktop/libgsystem/gsystem-file-utils.c
@@ -453,6 +453,9 @@ gs_file_open_dir_fd (GFile         *path
                      GCancellable  *cancellable,
                      GError       **error)
 {
+#ifndef O_DIRECTORY
+#define O_DIRECTORY 0
+#endif
   /* Linux specific probably */
   *out_fd = open (gs_file_get_path_cached (path), O_RDONLY | O_NONBLOCK | O_DIRECTORY | O_CLOEXEC);
   if (*out_fd == -1)
