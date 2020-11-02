$NetBSD: patch-lib_core_context.c,v 1.1 2020/11/02 12:32:20 nia Exp $

Add more stuff to the ifdef mess.

--- lib/core/context.c.orig	2020-10-26 11:31:31.000000000 +0000
+++ lib/core/context.c
@@ -30,7 +30,7 @@
 
 static const char *library_version = LWS_LIBRARY_VERSION;
 
-#if defined(__linux__) || defined(__FreeBSD__) || defined(__illumos__)
+#if defined(__linux__) || defined(__FreeBSD__) || defined(__NetBSD__) || defined(__illumos__)
 /* for setrlimit */
 #include <sys/resource.h>
 #endif
