$NetBSD: patch-mozilla_media_mtransport_third__party_nICEr_src_stun_addrs.c,v 1.2 2013/07/12 12:24:10 ryoon Exp $

--- mozilla/media/mtransport/third_party/nICEr/src/stun/addrs.c.orig	2013-06-20 04:35:15.000000000 +0000
+++ mozilla/media/mtransport/third_party/nICEr/src/stun/addrs.c
@@ -54,11 +54,15 @@ static char *RCSSTRING __UNUSED__="$Id: 
 #include <linux/sysctl.h>
 #endif
 #include <net/if.h>
-#ifndef LINUX
+#if defined(__FreeBSD__)
 #include <net/if_var.h>
 #include <net/if_dl.h>
 #include <net/if_types.h>
 #include <sys/sockio.h>
+#elif defined(__NetBSD__)
+#include <net/if_dl.h>
+#include <net/if_types.h>
+#include <sys/sockio.h>
 #else
 #include <linux/if.h>
 #endif
