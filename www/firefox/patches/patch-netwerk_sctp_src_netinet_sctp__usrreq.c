$NetBSD: patch-netwerk_sctp_src_netinet_sctp__usrreq.c,v 1.3 2014/02/20 13:19:03 ryoon Exp $

--- netwerk/sctp/src/netinet/sctp_usrreq.c.orig	2013-06-17 22:13:23.000000000 +0000
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
