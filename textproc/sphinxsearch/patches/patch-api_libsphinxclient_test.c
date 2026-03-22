$NetBSD: patch-api_libsphinxclient_test.c,v 1.1 2026/03/22 13:09:44 nia Exp $

Fix implicit declaration of memcpy(3).

--- api/libsphinxclient/test.c.orig	2026-03-22 12:40:48.630160803 +0000
+++ api/libsphinxclient/test.c
@@ -16,6 +16,7 @@
 #include <stdarg.h>
 #include <stdio.h>
 #include <stdlib.h>
+#include <string.h>
 
 #if _WIN32
 #include <winsock2.h>
