$NetBSD: patch-smbencrypt.inc.c,v 1.2 2009/06/05 08:13:48 hasso Exp $
--- smbval/smbencrypt.inc.c.orig	2003-06-05 20:21:26.000000000 +0100
+++ smbval/smbencrypt.inc.c	2008-10-17 17:47:37.000000000 +0100
@@ -19,7 +19,9 @@
 #include <arpa/inet.h>
 #include <dirent.h>
 #include <string.h>
+#if !defined(__NetBSD__) && !defined(__DragonFly__)
 #include <sys/vfs.h>
+#endif
 #include <netinet/in.h>
 
 #include "smblib-priv.h"
