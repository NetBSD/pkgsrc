$NetBSD: patch-platform_nsprpub_pr_include_md__netbsd.h,v 1.1 2024/08/05 22:29:56 nia Exp $

Add NetBSD/arm64 support.

--- platform/nsprpub/pr/include/md/_netbsd.h.orig	2024-07-10 01:54:53.000000000 -0700
+++ platform/nsprpub/pr/include/md/_netbsd.h	2024-08-05 12:48:09.663633172 -0700
@@ -27,6 +27,8 @@
 #define _PR_SI_ARCHITECTURE "sparc"
 #elif defined(__mips__)
 #define _PR_SI_ARCHITECTURE "mips"
+#elif defined(__aarch64__)
+#define _PR_SI_ARCHITECTURE "aarch64"
 #elif defined(__arm32__) || defined(__arm__) || defined(__armel__) \
     || defined(__armeb__)
 #define _PR_SI_ARCHITECTURE "arm"
