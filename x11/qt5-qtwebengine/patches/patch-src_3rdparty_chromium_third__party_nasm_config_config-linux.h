$NetBSD: patch-src_3rdparty_chromium_third__party_nasm_config_config-linux.h,v 1.2 2022/04/18 11:18:19 adam Exp $

--- src/3rdparty/chromium/third_party/nasm/config/config-linux.h.orig	2021-02-19 16:41:59.000000000 +0000
+++ src/3rdparty/chromium/third_party/nasm/config/config-linux.h
@@ -139,7 +139,7 @@
 #define HAVE_ACCESS 1
 
 /* Define to 1 if you have the `canonicalize_file_name' function. */
-#define HAVE_CANONICALIZE_FILE_NAME 1
+/* #undef HAVE_CANONICALIZE_FILE_NAME */
 
 /* Define to 1 if you have the `cpu_to_le16' intrinsic function. */
 /* #undef HAVE_CPU_TO_LE16 */
@@ -336,7 +336,7 @@
 #define HAVE_MEMORY_H 1
 
 /* Define to 1 if you have the `mempcpy' function. */
-#define HAVE_MEMPCPY 1
+/* #undef HAVE_MEMPCPY */
 
 /* Define to 1 if you have a working `mmap' system call. */
 #define HAVE_MMAP 1
