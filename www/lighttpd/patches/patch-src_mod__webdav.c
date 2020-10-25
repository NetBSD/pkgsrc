$NetBSD: patch-src_mod__webdav.c,v 1.1 2020/10/25 14:59:14 schmonz Exp $

Add upstream commit ad62991 to define _NETBSD_SOURCE on NetBSD:

NetBSD dirent.h improperly hides fdopendir() (POSIX.1-2008) declaration
which should be visible w/ _XOPEN_SOURCE 700 or _POSIX_C_SOURCE 200809L

--- src/mod_webdav.c.orig	2020-02-01 02:49:09.000000000 +0000
+++ src/mod_webdav.c
@@ -155,6 +155,11 @@
 #if !defined(_XOPEN_SOURCE) || _XOPEN_SOURCE-0 < 700
 #undef  _XOPEN_SOURCE
 #define _XOPEN_SOURCE 700
+/* NetBSD dirent.h improperly hides fdopendir() (POSIX.1-2008) declaration
+ * which should be visible with _XOPEN_SOURCE 700 or _POSIX_C_SOURCE 200809L */
+#ifdef __NetBSD__
+#define _NETBSD_SOURCE
+#endif
 #endif
 /* DT_UNKNOWN DTTOIF() */
 #ifndef _GNU_SOURCE
