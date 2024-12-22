$NetBSD: patch-nsprpub_pr_include_md___netbsd.h,v 1.1 2024/12/22 21:31:44 nia Exp $

Improve NetBSD support.
https://bugzilla.mozilla.org/show_bug.cgi?id=1718836

--- nsprpub/pr/include/md/_netbsd.h.orig	2024-09-30 19:54:44.000000000 +0000
+++ nsprpub/pr/include/md/_netbsd.h
@@ -30,6 +30,8 @@
 #elif defined(__arm32__) || defined(__arm__) || defined(__armel__) \
     || defined(__armeb__)
 #define _PR_SI_ARCHITECTURE "arm"
+#elif defined(__aarch64__)
+#define _PR_SI_ARCHITECTURE "aarch64"
 #endif
 
 #if defined(__ELF__)
@@ -47,7 +49,7 @@
 #define HAVE_DLL
 #define USE_DLFCN
 #define _PR_HAVE_SOCKADDR_LEN
-#define _PR_NO_LARGE_FILES
+#define _PR_HAVE_LARGE_OFF_T
 #define _PR_STAT_HAS_ST_ATIMESPEC
 #define _PR_POLL_AVAILABLE
 #define _PR_USE_POLL
@@ -75,6 +77,8 @@
 #define JB_SP_INDEX 2
 #elif defined(__mips__)
 #define JB_SP_INDEX 4
+#elif defined(__amd64__)
+#define JB_SP_INDEX 6
 #elif defined(__alpha__)
 #define JB_SP_INDEX 34
 #elif defined(__arm32__)
@@ -86,6 +90,8 @@
 #else
 #define JB_SP_INDEX _JB_REG_R13
 #endif
+#elif defined(__aarch64__)
+#define JB_SP_INDEX _JB_SP
 #else
 #error "Need to define SP index in jmp_buf here"
 #endif
