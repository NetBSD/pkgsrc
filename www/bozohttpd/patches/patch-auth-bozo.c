$NetBSD: patch-auth-bozo.c,v 1.1 2018/11/23 21:30:27 mrg Exp $

--- auth-bozo.c.orig	2018-11-23 13:10:04.000000000 -0800
+++ auth-bozo.c	2018-11-23 13:15:02.729491334 -0800
@@ -40,6 +40,10 @@
 #include <stdlib.h>
 #include <unistd.h>
 
+#ifndef NO_SSL_SUPPORT
+#include <openssl/des.h>
+#endif
+
 #include "bozohttpd.h"
 
 static	ssize_t	base64_decode(const unsigned char *, size_t,
@@ -101,7 +105,7 @@
 			    request->hr_authpass));
 			if (strcmp(request->hr_authuser, user) != 0)
 				continue;
-			if (strcmp(crypt(request->hr_authpass, pass),
+			if (strcmp(DES_crypt(request->hr_authpass, pass),
 					pass) != 0)
 				break;
 			fclose(fp);
