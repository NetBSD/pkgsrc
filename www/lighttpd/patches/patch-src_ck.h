$NetBSD: patch-src_ck.h,v 1.1 2021/10/10 21:09:55 schmonz Exp $

Fix macOS build ("error: unknown type name 'errno_t'") with upstream
patch 2a3cca7.

--- src/ck.h.orig	2021-10-04 01:38:52.000000000 +0000
+++ src/ck.h
@@ -12,6 +12,11 @@
 #ifndef __STDC_WANT_LIB_EXT1__ /*(enable C11 Annex K ext1 *_s functions)*/
 #define __STDC_WANT_LIB_EXT1__ 1
 #endif
+#if defined(__APPLE__) && defined(__MACH__)
+#ifndef _DARWIN_C_SOURCE
+#define _DARWIN_C_SOURCE
+#endif
+#endif
 #include "first.h"
 #ifdef __FreeBSD__
 #ifndef _RSIZE_T_DEFINED /* expecting __EXT1_VISIBLE 1 and _RSIZE_T_DEFINED */
