$NetBSD: patch-src_first.h,v 1.1 2021/10/10 21:09:55 schmonz Exp $

Fix macOS build ("error: unknown type name 'errno_t'") with upstream
patch 2a3cca7.

--- src/first.h.orig	2021-10-04 01:38:52.000000000 +0000
+++ src/first.h
@@ -13,6 +13,12 @@
 #define _DEFAULT_SOURCE
 #endif
 
+#if defined(__APPLE__) && defined(__MACH__)
+#ifndef _DARWIN_C_SOURCE
+#define _DARWIN_C_SOURCE
+#endif
+#endif
+
 #ifndef __STDC_WANT_LIB_EXT1__
 #define __STDC_WANT_LIB_EXT1__ 1
 #endif
