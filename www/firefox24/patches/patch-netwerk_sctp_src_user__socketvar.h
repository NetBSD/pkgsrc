$NetBSD: patch-netwerk_sctp_src_user__socketvar.h,v 1.1 2013/11/03 04:52:00 ryoon Exp $

--- netwerk/sctp/src/user_socketvar.h.orig	2013-06-17 22:13:23.000000000 +0000
+++ netwerk/sctp/src/user_socketvar.h
@@ -47,7 +47,7 @@
 /* #include <sys/_lock.h>  was 0 byte file */
 /* #include <sys/_mutex.h> was 0 byte file */
 /* #include <sys/_sx.h> */ /*__Userspace__ alternative?*/
-#if !defined(__Userspace_os_Windows) && !defined(__Userspace_os_FreeBSD)
+#if !defined(__Userspace_os_Windows) && !defined(__Userspace_os_FreeBSD) && !defined(__Userspace_os_NetBSD)
 #include <sys/uio.h>
 #endif
 #define SOCK_MAXADDRLEN 255
@@ -64,11 +64,11 @@
 #define ERESTART (-1)
 #endif
 
-#if !defined(__Userspace_os_Darwin) && !defined(__Userspace_os_OpenBSD)
+#if !defined(__Userspace_os_Darwin) && !defined(__Userspace_os_OpenBSD) && !defined(__Userspace_os_NetBSD)
 enum	uio_rw { UIO_READ, UIO_WRITE };
 #endif
 
-#if !defined(__Userspace_os_OpenBSD)
+#if !defined(__Userspace_os_OpenBSD) && !defined(__Userspace_os_NetBSD)
 /* Segment flag values. */
 enum uio_seg {
 	UIO_USERSPACE,		/* from user data space */
