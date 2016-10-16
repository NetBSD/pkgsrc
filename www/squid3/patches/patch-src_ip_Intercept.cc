$NetBSD: patch-src_ip_Intercept.cc,v 1.7 2016/10/16 15:58:15 taca Exp $

Fix build problem when PKG_OPTIONS contains squid-ipf.

--- src/ip/Intercept.cc.orig	2016-10-09 19:58:01.000000000 +0000
+++ src/ip/Intercept.cc
@@ -25,6 +25,9 @@
 #define IPFILTER_VERSION        5000004
 #endif
 
+#if HAVE_SYS_PARAM_H
+#include <sys/param.h>
+#endif
 #if HAVE_SYS_IOCCOM_H
 #include <sys/ioccom.h>
 #endif
