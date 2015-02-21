$NetBSD: patch-compat_compat.h,v 1.1.2.2 2015/02/21 12:53:08 tron Exp $

Fix building.

--- compat/compat.h.orig	2015-02-18 11:05:44.000000000 +0000
+++ compat/compat.h
@@ -38,7 +38,7 @@
  * We must pre-define before doing anything with OS headers so the OS
  * do not. Then un-define it before using the IPFilter *_compat.h headers.
  */
-#if IPF_TRANSPARENT && USE_SOLARIS_IPFILTER_MINOR_T_HACK
+#if IPF_TRANSPARENT && defined(USE_SOLARIS_IPFILTER_MINOR_T_HACK)
 /* But we only need do this nasty thing for src/ip/Intercept.cc */
 #if BUILDING_SQUID_IP_INTERCEPT_CC
 #define minor_t solaris_minor_t_fubar
