$NetBSD: patch-libgnome-desktop_libgsystem_gsystem-shutil.c,v 1.1 2014/09/25 15:10:21 prlw1 Exp $

https://bugzilla.gnome.org/show_bug.cgi?id=737369

--- libgnome-desktop/libgsystem/gsystem-shutil.c.orig	2013-10-04 22:18:43.000000000 +0000
+++ libgnome-desktop/libgsystem/gsystem-shutil.c
@@ -271,7 +271,11 @@ gs_shutil_rm_rf_children (DIR           
           
       if (dent->d_type == DT_DIR)
         {
+#ifdef O_DIRECTORY
           int child_dfd = openat (dfd, dent->d_name, O_RDONLY | O_NONBLOCK | O_DIRECTORY | O_CLOEXEC | O_NOFOLLOW);
+#else
+          int child_dfd = openat (dfd, dent->d_name, O_RDONLY | O_NONBLOCK | O_CLOEXEC | O_NOFOLLOW);
+#endif
 
           if (child_dfd == -1)
             {
