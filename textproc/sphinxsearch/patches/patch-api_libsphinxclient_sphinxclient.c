$NetBSD: patch-api_libsphinxclient_sphinxclient.c,v 1.1 2026/03/22 13:09:44 nia Exp $

Fix implicit declaration of fcntl(2) on SunOS.

--- api/libsphinxclient/sphinxclient.c.orig	2026-03-22 12:38:35.689296706 +0000
+++ api/libsphinxclient/sphinxclient.c
@@ -54,6 +54,7 @@
 #else
 	// UNIX-specific headers and calls
 	#include <unistd.h>
+	#include <fcntl.h>
 	#include <netinet/in.h>
 	#include <sys/file.h>
 	#include <sys/socket.h>
@@ -62,7 +63,6 @@
 	#include <netdb.h>
 	#include <errno.h>
 	#include <sys/un.h>
-	#include <sys/fcntl.h>
 #endif
 
 //////////////////////////////////////////////////////////////////////////
