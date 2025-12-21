$NetBSD: patch-src_3rdparty_chromium_third__party_fontconfig_include_config.h,v 1.1 2025/12/21 09:38:42 markd Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- src/3rdparty/chromium/third_party/fontconfig/include/config.h.orig	2025-05-29 01:27:28.000000000 +0000
+++ src/3rdparty/chromium/third_party/fontconfig/include/config.h
@@ -13,7 +13,7 @@
 
 #define FC_CACHEDIR "/var/cache/fontconfig"
 
-#define FC_DEFAULT_FONTS "\t<dir>/usr/share/fonts</dir>\n\t<dir>/usr/local/share/fonts</dir>\n"
+#define FC_DEFAULT_FONTS "\t<dir>/usr/X11R6/lib/X11/fonts</dir>\n"
 
 #define FC_FONTPATH ""
 
@@ -66,7 +66,7 @@
 
 #define HAVE_MMAP 1
 
-#define HAVE_POSIX_FADVISE 1
+#define HAVE_POSIX_FADVISE 0
 
 #define HAVE_PTHREAD 1
 
@@ -74,7 +74,10 @@
 
 #define HAVE_RANDOM 1
 
-#define HAVE_RANDOM_R 1
+/* #undef HAVE_RANDOM_R */
+
+/* Define to 1 if you have the `arc4_random' function. */
+#define HAVE_ARC4RANDOM 1
 
 #define HAVE_RAND_R 1
 
@@ -92,11 +95,11 @@
 
 #define HAVE_SYS_PARAM_H 1
 
-#define HAVE_SYS_STATFS_H 1
+/* #undef HAVE_SYS_STATFS_H */
 
 #define HAVE_SYS_STATVFS_H 1
 
-#define HAVE_SYS_VFS_H 1
+/* #undef HAVE_SYS_VFS_H */
 
 #define HAVE_UNISTD_H 1
 
