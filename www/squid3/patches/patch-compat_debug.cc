$NetBSD: patch-compat_debug.cc,v 1.1 2015/09/23 03:59:04 taca Exp $

Build fix with IP Filter 4.1.34 (NetBSD 6.1 and may be older).

* Avoid to define debug CPP macro.
* Make the proto typoe of debug() match with IP Filter 4.1.34.

--- compat/debug.cc.orig	2015-09-17 13:06:28.000000000 +0000
+++ compat/debug.cc
@@ -12,11 +12,11 @@
 /* default off */
 int debug_enabled = 0;
 
-#ifndef __GNUC__
+#if defined(__GNUC__) && defined(HAVE_NETINET_IP_FIL_H)
 /* under gcc a macro define in compat/debug.h is used instead */
 
 void
-debug(const char *format,...)
+debug(char *format,...)
 {
     if (!debug_enabled)
         return;
