$NetBSD: patch-netwerk_sctp_src_user__recv__thread.c,v 1.2 2014/02/08 09:36:00 ryoon Exp $

--- netwerk/sctp/src/user_recv_thread.c.orig	2014-01-28 04:04:00.000000000 +0000
+++ netwerk/sctp/src/user_recv_thread.c
@@ -35,7 +35,7 @@
 #include <netinet/in.h>
 #include <unistd.h>
 #include <pthread.h>
-#if !defined(__Userspace_os_FreeBSD)
+#if !defined(__Userspace_os_FreeBSD) && !defined(__Userspace_os_NetBSD)
 #include <sys/uio.h>
 #else
 #include <user_ip6_var.h>
