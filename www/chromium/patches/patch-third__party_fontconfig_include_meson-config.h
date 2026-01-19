$NetBSD: patch-third__party_fontconfig_include_meson-config.h,v 1.12 2026/01/19 16:14:20 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- third_party/fontconfig/include/meson-config.h.orig	2026-01-07 00:50:30.000000000 +0000
+++ third_party/fontconfig/include/meson-config.h
@@ -17,7 +17,7 @@
 
 #define FC_CACHEDIR "/var/cache/fontconfig"
 
-#define FC_DEFAULT_FONTS "\t<dir>/usr/share/fonts</dir>\n\t<dir>/usr/local/share/fonts</dir>\n"
+#define FC_DEFAULT_FONTS "\t<dir>@X11BASE@/lib/X11/fonts</dir>\n"
 
 #define FC_FONTPATH ""
 
@@ -98,10 +98,13 @@
 
 #define HAVE_RANDOM 1
 
-#define HAVE_RANDOM_R 1
+/* #undef HAVE_RANDOM_R */
 
 #define HAVE_RAND_R 1
 
+/* Define to 1 if you have the `arc4_random' function. */
+#define HAVE_ARC4RANDOM 1
+
 #define HAVE_READLINK 1
 
 #define HAVE_STDATOMIC_PRIMITIVES 1
@@ -128,7 +131,7 @@
 
 #define HAVE_SYS_PARAM_H 1
 
-#define HAVE_SYS_STATFS_H 1
+/* #undef HAVE_SYS_STATFS_H */
 
 #define HAVE_SYS_STATVFS_H 1
 
@@ -136,7 +139,7 @@
 
 #define HAVE_SYS_TYPES_H 1
 
-#define HAVE_SYS_VFS_H 1
+/* #undef HAVE_SYS_VFS_H */
 
 #define HAVE_TIME_H 1
 
