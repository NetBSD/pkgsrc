$NetBSD: patch-src_3rdparty_chromium_third__party_dav1d_config_linux_arm64_config.h,v 1.1 2026/03/29 16:57:04 tnn Exp $

Add NetBSD support via kludge. Since it uses pregenerated config.

--- src/3rdparty/chromium/third_party/dav1d/config/linux/arm64/config.h.orig	2026-03-29 09:29:22.523216258 +0000
+++ src/3rdparty/chromium/third_party/dav1d/config/linux/arm64/config.h
@@ -67,7 +67,11 @@
 
 #define HAVE_ELF_AUX_INFO 0
 
+#if defined(__NetBSD__)
+#define HAVE_GETAUXVAL 0
+#else
 #define HAVE_GETAUXVAL 1
+#endif
 
 #define HAVE_I8MM 1
 
