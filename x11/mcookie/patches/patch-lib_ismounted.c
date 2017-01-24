$NetBSD: patch-lib_ismounted.c,v 1.2 2017/01/24 21:42:26 bsiegert Exp $

Fix build on NetBSD.

--- lib/ismounted.c.orig	2016-11-02 12:57:31.000000000 +0000
+++ lib/ismounted.c
@@ -214,7 +214,11 @@ static int check_mntent(const char *file
 static int check_getmntinfo(const char *file, int *mount_flags,
 				  char *mtpt, int mtlen)
 {
+#ifdef __NetBSD__
+	struct statvfs *mp;
+#else
 	struct statfs *mp;
+#endif
         int    len, n;
         const  char   *s1;
 	char	*s2;
