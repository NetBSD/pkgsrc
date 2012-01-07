$NetBSD: patch-mozilla_media_libvpx_vpx_config.h,v 1.1 2012/01/07 20:44:32 marino Exp $

--- mozilla/media/libvpx/vpx_config.h.orig	2011-11-07 21:08:15.000000000 +0000
+++ mozilla/media/libvpx/vpx_config.h
@@ -12,11 +12,11 @@
 /* 32 bit MacOS. */
 #include "vpx_config_x86-darwin9-gcc.h"
 
-#elif defined(__linux__) && defined(__i386__)
+#elif (defined(__linux__) || defined(__DragonFly__)) && defined(__i386__)
 /* 32 bit Linux. */
 #include "vpx_config_x86-linux-gcc.h"
 
-#elif defined(__linux__) && defined(__x86_64__)
+#elif (defined(__linux__) || defined(__DragonFly__)) && defined(__x86_64__)
 /* 64 bit Linux. */
 #include "vpx_config_x86_64-linux-gcc.h"
 
