$NetBSD: patch-netwerk_sctp_src_netinet_sctp__os__userspace.h,v 1.1 2013/11/03 04:51:59 ryoon Exp $

--- netwerk/sctp/src/netinet/sctp_os_userspace.h.orig	2013-06-17 22:13:23.000000000 +0000
+++ netwerk/sctp/src/netinet/sctp_os_userspace.h
@@ -383,7 +383,7 @@ struct udphdr {
 #else /* !defined(Userspace_os_Windows) */
 #include <sys/cdefs.h> /* needed? added from old __FreeBSD__ */
 #include <sys/socket.h>
-#if defined(__Userspace_os_FreeBSD) || defined(__Userspace_os_OpenBSD) || defined(ANDROID)
+#if defined(__Userspace_os_FreeBSD) || defined(__Userspace_os_OpenBSD) || defined(ANDROID) || defined(__Userspace_os_NetBSD)
 #include <pthread.h>
 #endif
 typedef pthread_mutex_t userland_mutex_t;
@@ -397,7 +397,9 @@ typedef pthread_t userland_thread_t;
 #define MA_OWNED 7 /* sys/mutex.h typically on FreeBSD */
 #if !defined(__Userspace_os_FreeBSD)
 struct mtx {int dummy;};
+#if !defined(__Userspace_os_NetBSD)
 struct selinfo {int dummy;};
+#endif
 struct sx {int dummy;};
 #endif
 
@@ -500,7 +502,7 @@ struct sx {int dummy;};
 #include <netinet/ip6.h>
 #include <netinet/icmp6.h>
 #endif
-#if defined(__Userspace_os_Linux) || defined(__Userspace_os_Darwin) || defined(__Userspace_os_FreeBSD) || defined(__Userspace_os_OpenBSD) ||defined(__Userspace_os_Windows)
+#if defined(__Userspace_os_Linux) || defined(__Userspace_os_Darwin) || defined(__Userspace_os_FreeBSD) || defined(__Userspace_os_OpenBSD) ||defined(__Userspace_os_Windows) || defined(__Userspace_os_NetBSD)
 #include "user_ip6_var.h"
 #else
 #include <netinet6/ip6_var.h>
@@ -1120,6 +1122,8 @@ sctp_get_mbuf_for_msg(unsigned int space
 #if defined(__Userspace_os_FreeBSD) || defined(__Userspace_os_OpenBSD)
 /* stolen from /usr/include/sys/socket.h */
 #define CMSG_ALIGN(n)   _ALIGN(n)
+#elif defined(__Userspace_os_NetBSD)
+#define CMSG_ALIGN(n)   (((n) + __ALIGNBYTES) & ~__ALIGNBYTES)
 #elif defined(__Userspace_os_Darwin)
 #if !defined(__DARWIN_ALIGNBYTES)
 #define	__DARWIN_ALIGNBYTES	(sizeof(__darwin_size_t) - 1)
