$NetBSD: patch-acinclude_os-deps.m4,v 1.2 2020/04/09 16:27:15 sborrill Exp $

Fix detection of IPv6 NAT in IPFilter by including correct headers
Generate correct #defines without trailing underscores

https://github.com/squid-cache/squid/pull/596

--- acinclude/os-deps.m4.orig	2020-01-20 02:51:40.000000000 +0000
+++ acinclude/os-deps.m4	2020-04-09 15:59:34.000000000 +0100
@@ -925,11 +925,13 @@
 ## Solaris 10+ backported IPv6 NAT to their IPFilter v4.1 instead of using v5
   AC_CHECK_MEMBERS([
     struct natlookup.nl_inipaddr.in6,
-    struct natlookup.nl_realipaddr.in6
-  ],,,[
+    struct natlookup.nl_realipaddr.in6],,,[
 #if USE_SOLARIS_IPFILTER_MINOR_T_HACK
 #define minor_t fubar
 #endif
+#if HAVE_SYS_PARAM_H
+#include <sys/param.h>
+#endif
 #if HAVE_SYS_TYPES_H
 #include <sys/types.h>
 #endif
@@ -955,7 +957,11 @@
 #elif HAVE_NETINET_IP_FIL_H
 #include <netinet/ip_fil.h>
 #endif
+#if HAVE_IP_NAT_H
 #include <ip_nat.h>
+#elif HAVE_NETINET_IP_NAT_H
+#include <netinet/ip_nat.h>
+#endif
   ])
 
 ])
