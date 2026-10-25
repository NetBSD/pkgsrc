$NetBSD: patch-src_sawfish.h,v 1.1 2026/10/25 00:16:44 gutteridge Exp $

Remove 'typedef int bool' to comply with C23.
https://github.com/SawfishWM/sawfish/commit/6b15c776ea1654ee7f68e4a7f4256dd4976beb3f

--- src/sawfish.h.orig	2021-12-24 19:22:59.000000000 +0000
+++ src/sawfish.h
@@ -49,7 +49,9 @@
 # define rep_INTERFACE 7		/* rep 0.10 */
 #endif
 
+#if !defined(__STDC_VERSION__) || __STDC_VERSION__ < 202311L
 typedef int bool;
+#endif
 
 #ifdef rep_HAVE_UNIX
 # define HAVE_UNIX 1
