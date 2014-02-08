$NetBSD: patch-netwerk_sctp_src_netinet_sctp__usrreq.c,v 1.2 2014/02/08 09:36:00 ryoon Exp $

--- netwerk/sctp/src/netinet/sctp_usrreq.c.orig	2014-01-28 04:04:00.000000000 +0000
+++ netwerk/sctp/src/netinet/sctp_usrreq.c
@@ -414,6 +414,8 @@ sctp_notify(struct sctp_inpcb *inp,
 	    (icmph->icmp_code == ICMP_UNREACH_HOST_PROHIB) ||
 #ifdef __Panda__
 	    (icmph->icmp_code == ICMP_UNREACH_ADMIN)) {
+#elif defined(__Userspace_os_NetBSD)
+	    (icmph->icmp_code == ICMP_UNREACH_ADMIN_PROHIBIT)) {
 #else
 	    (icmph->icmp_code == ICMP_UNREACH_FILTER_PROHIB)) {
 #endif
