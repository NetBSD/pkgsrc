$NetBSD: patch-lib_ismounted.c,v 1.1 2016/09/20 08:00:51 wiz Exp $

Fix build on NetBSD.

--- lib/ismounted.c.orig	2016-03-08 13:26:33.000000000 +0000
+++ lib/ismounted.c
@@ -214,7 +214,7 @@ static int check_mntent(const char *file
 static int check_getmntinfo(const char *file, int *mount_flags,
 				  char *mtpt, int mtlen)
 {
-	struct statfs *mp;
+	struct statvfs *mp;
         int    len, n;
         const  char   *s1;
 	char	*s2;
