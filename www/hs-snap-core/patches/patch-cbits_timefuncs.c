$NetBSD: patch-cbits_timefuncs.c,v 1.1 2025/03/08 04:14:00 pho Exp $

Fix linkage on NetBSD: timegm(3) is only declared when _NETBSD_SOURCE is
defined.

--- cbits/timefuncs.c.orig	2025-03-08 04:09:40.645065639 +0000
+++ cbits/timefuncs.c
@@ -1,6 +1,7 @@
 #define _DEFAULT_SOURCE
 #define _XOPEN_SOURCE
 #define _BSD_SOURCE
+#define _NETBSD_SOURCE
 #include <time.h>
 #include <locale.h>
 
