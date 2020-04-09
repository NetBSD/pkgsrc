$NetBSD: patch-acinclude_os-deps.m4,v 1.1 2020/04/09 09:45:20 sborrill Exp $

Fix detection of IPv6 NAT in IPFilter by including correct headers

--- acinclude/os-deps.m4.orig	2020-01-20 02:51:40.000000000 +0000
+++ acinclude/os-deps.m4	2020-04-09 09:06:37.000000000 +0100
@@ -930,6 +930,9 @@
 #if USE_SOLARIS_IPFILTER_MINOR_T_HACK
 #define minor_t fubar
 #endif
+#if HAVE_SYS_PARAM_H
+#include <sys/param.h>
+#endif
 #if HAVE_SYS_TYPES_H
 #include <sys/types.h>
 #endif
@@ -955,7 +958,11 @@
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
