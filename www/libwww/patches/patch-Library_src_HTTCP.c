$NetBSD: patch-Library_src_HTTCP.c,v 1.1 2026/06/14 12:57:43 nia Exp $

Use correct types. sizeof returns size_t and the next function takes
size_t as its argument. Fixes a warning.

--- Library/src/HTTCP.c.orig	2026-06-14 12:52:26.297871273 +0000
+++ Library/src/HTTCP.c
@@ -471,7 +471,7 @@ PUBLIC int HTDoAccept (HTNet * listening, HTNet * acce
 {
     HTHost * host = HTNet_host(listening);
     HTRequest * request = HTNet_request(accepting);
-    int size = sizeof(host->sock_addr);
+    size_t size = sizeof(host->sock_addr);
     int status;
     if (!request || HTNet_socket(listening)==INVSOC) {
 	HTTRACE(PROT_TRACE, "HTDoAccept.. Invalid socket\n");
