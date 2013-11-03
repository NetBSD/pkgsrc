$NetBSD: patch-media_mtransport_third__party_nICEr_src_stun_stun.h,v 1.1 2013/11/03 04:51:59 ryoon Exp $

--- media/mtransport/third_party/nICEr/src/stun/stun.h.orig	2013-05-11 19:19:43.000000000 +0000
+++ media/mtransport/third_party/nICEr/src/stun/stun.h
@@ -41,11 +41,15 @@ OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 #include <sys/socket.h>
 #include <net/if.h>
 #ifndef LINUX
+#if !defined(__OpenBSD__) && !defined(__NetBSD__)
 #include <net/if_var.h>
+#endif
 #include <net/if_dl.h>
 #include <net/if_types.h>
 #endif
+#ifndef BSD
 #include <net/route.h>
+#endif
 #include <netinet/in.h>
 #ifndef LINUX
 #include <netinet/in_var.h>
