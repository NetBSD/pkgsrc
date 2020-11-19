$NetBSD: patch-src_dbus.c,v 1.1 2020/11/19 11:03:04 nia Exp $

Arguments to ctype functions must be unsigned char.

--- src/dbus.c.orig	2020-10-24 08:44:12.000000000 +0000
+++ src/dbus.c
@@ -129,7 +129,7 @@ bool cdbus_init(session_t *ps, const cha
 		// underscore
 		char *tmp = service + strlen(CDBUS_SERVICE_NAME) + 1;
 		while (*tmp) {
-			if (!isalnum(*tmp)) {
+			if (!isalnum((unsigned char)*tmp)) {
 				*tmp = '_';
 			}
 			tmp++;
