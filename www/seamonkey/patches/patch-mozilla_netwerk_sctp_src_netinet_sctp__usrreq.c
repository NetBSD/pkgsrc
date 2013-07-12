$NetBSD: patch-mozilla_netwerk_sctp_src_netinet_sctp__usrreq.c,v 1.1 2013/07/12 12:24:11 ryoon Exp $

--- mozilla/netwerk/sctp/src/netinet/sctp_usrreq.c.orig	2013-06-20 04:35:18.000000000 +0000
+++ mozilla/netwerk/sctp/src/netinet/sctp_usrreq.c
@@ -414,6 +414,8 @@ sctp_notify(struct sctp_inpcb *inp,
 	    (icmph->icmp_code == ICMP_UNREACH_HOST_PROHIB) ||
 #ifdef __Panda__
 	    (icmph->icmp_code == ICMP_UNREACH_ADMIN)) {
+#elif defined(__Userspace_os_NetBSD)
+	    (icmph->icmp_code == ICMP_UNREACH_ADMIN_PROHIBIT)) {
 #else
 	    (icmph->icmp_code == ICMP_UNREACH_FILTER_PROHIB)) {
 #endif
