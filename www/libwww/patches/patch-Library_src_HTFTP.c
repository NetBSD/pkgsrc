$NetBSD: patch-Library_src_HTFTP.c,v 1.1 2026/06/14 12:57:43 nia Exp $

Use correct types. sizeof returns size_t and the next function takes
size_t as its argument. Fixes a warning.

--- Library/src/HTFTP.c.orig	2026-06-14 12:53:17.373693538 +0000
+++ Library/src/HTFTP.c
@@ -498,7 +498,7 @@ PRIVATE BOOL AcceptDataSocket (HTNet *cnet, HTNet *dne
     */
     {
 	SockA local_port, local_host;
-	int addr_size = sizeof(local_port);
+	size_t addr_size = sizeof(local_port);
 	memset((void *) &local_host, '\0', addr_size);
 	memset((void *) &local_port, '\0', addr_size);
 	if (getsockname(HTNet_socket(cnet),
