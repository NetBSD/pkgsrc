$NetBSD: patch-plugins_corerouter_corerouter.c,v 1.1 2024/06/04 11:50:46 joerg Exp $

Use same non-blocking handling on NetBSD as on Linux.

--- plugins/corerouter/corerouter.c.orig	2024-02-08 16:35:28.000000000 +0000
+++ plugins/corerouter/corerouter.c
@@ -822,7 +822,7 @@ void uwsgi_corerouter_loop(int id, void
 			while (ugs) {
 				if (ugs->gateway == &ushared->gateways[id] && ucr->interesting_fd == ugs->fd) {
 					if (!ugs->subscription) {
-#if defined(__linux__) && defined(SOCK_NONBLOCK) && !defined(OBSOLETE_LINUX_KERNEL)
+#if (defined(__linux__) || defined(__NetBSD__)) && defined(SOCK_NONBLOCK) && !defined(OBSOLETE_LINUX_KERNEL)
 						new_connection = accept4(ucr->interesting_fd, (struct sockaddr *) &cr_addr, &cr_addr_len, SOCK_NONBLOCK);
 						if (new_connection < 0) {
 							taken = 1;
