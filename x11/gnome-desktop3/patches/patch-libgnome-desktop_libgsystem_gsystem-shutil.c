$NetBSD: patch-libgnome-desktop_libgsystem_gsystem-shutil.c,v 1.2 2014/11/08 23:15:06 prlw1 Exp $

https://bugzilla.gnome.org/show_bug.cgi?id=737369

--- libgnome-desktop/libgsystem/gsystem-shutil.c.orig	2014-06-03 15:05:13.000000000 +0000
+++ libgnome-desktop/libgsystem/gsystem-shutil.c
@@ -322,6 +322,9 @@ gs_shutil_rm_rf_children (DIR           
           
       if (dent->d_type == DT_DIR)
         {
+#ifndef O_DIRECTORY
+#define O_DIRECTORY 0
+#endif
           int child_dfd = openat (dfd, dent->d_name, O_RDONLY | O_NONBLOCK | O_DIRECTORY | O_CLOEXEC | O_NOFOLLOW);
 
           if (child_dfd == -1)
