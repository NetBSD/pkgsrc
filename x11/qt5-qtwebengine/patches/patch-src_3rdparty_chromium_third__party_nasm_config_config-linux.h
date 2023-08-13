$NetBSD: patch-src_3rdparty_chromium_third__party_nasm_config_config-linux.h,v 1.3 2023/08/13 18:35:14 wiz Exp $

--- src/3rdparty/chromium/third_party/nasm/config/config-linux.h.orig	2022-04-06 13:32:17.000000000 +0000
+++ src/3rdparty/chromium/third_party/nasm/config/config-linux.h
@@ -139,7 +139,7 @@
 #define HAVE_ACCESS 1
 
 /* Define to 1 if you have the `canonicalize_file_name' function. */
-#define HAVE_CANONICALIZE_FILE_NAME 1
+/* #undef HAVE_CANONICALIZE_FILE_NAME */
 
 /* Define to 1 if you have the `cpu_to_le16' intrinsic function. */
 /* #undef HAVE_CPU_TO_LE16 */
@@ -336,7 +336,13 @@
 #define HAVE_MEMORY_H 1
 
 /* Define to 1 if you have the `mempcpy' function. */
+#if defined(__NetBSD__)
+#include <sys/param.h>
+#if __NetBSD_Version__ >= 1099000700
 #define HAVE_MEMPCPY 1
+#endif
+#endif
+/* #undef HAVE_MEMPCPY */
 
 /* Define to 1 if you have a working `mmap' system call. */
 #define HAVE_MMAP 1
