$NetBSD: patch-src_scandir.c,v 1.1 2016/12/01 11:13:04 leot Exp $

DragonFlyBSD dirent(3) does not have dirent.d_reclen entry.

--- src/scandir.c.orig	2016-05-10 17:39:42.000000000 +0000
+++ src/scandir.c
@@ -38,7 +38,7 @@ int ag_scandir(const char *dirname,
             }
         }
 
-#if defined(__MINGW32__) || defined(__CYGWIN__)
+#if defined(__MINGW32__) || defined(__CYGWIN__) || defined(__DragonFly__)
         d = malloc(sizeof(struct dirent));
 #else
         d = malloc(entry->d_reclen);
@@ -47,7 +47,7 @@ int ag_scandir(const char *dirname,
         if (d == NULL) {
             goto fail;
         }
-#if defined(__MINGW32__) || defined(__CYGWIN__)
+#if defined(__MINGW32__) || defined(__CYGWIN__) || defined(__DragonFly__)
         memcpy(d, entry, sizeof(struct dirent));
 #else
         memcpy(d, entry, entry->d_reclen);
