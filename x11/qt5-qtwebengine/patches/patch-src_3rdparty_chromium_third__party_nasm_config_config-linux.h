$NetBSD: patch-src_3rdparty_chromium_third__party_nasm_config_config-linux.h,v 1.1 2021/08/03 21:04:36 markd Exp $

--- src/3rdparty/chromium/third_party/nasm/config/config-linux.h.orig	2020-07-15 19:01:37.000000000 +0000
+++ src/3rdparty/chromium/third_party/nasm/config/config-linux.h
@@ -117,7 +117,7 @@
 #define HAVE_ACCESS 1
 
 /* Define to 1 if you have the `canonicalize_file_name' function. */
-#define HAVE_CANONICALIZE_FILE_NAME 1
+/* #undef HAVE_CANONICALIZE_FILE_NAME */
 
 /* Define to 1 if you have the `cpu_to_le16' intrinsic function. */
 /* #undef HAVE_CPU_TO_LE16 */
