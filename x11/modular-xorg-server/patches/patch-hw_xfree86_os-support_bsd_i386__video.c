$NetBSD: patch-hw_xfree86_os-support_bsd_i386__video.c,v 1.2 2023/03/30 08:25:06 wiz Exp $

Use correct symbol and amd64.

--- hw/xfree86/os-support/bsd/i386_video.c.orig	2015-01-17 23:42:52.000000000 +0000
+++ hw/xfree86/os-support/bsd/i386_video.c
@@ -42,6 +42,9 @@
 #else
 #define MAP_FLAGS (MAP_FILE | MAP_SHARED)
 #endif
+#if defined(__NetBSD__) && defined(USE_AMD64_IOPL)
+#define amd64_iopl x86_64_iopl
+#endif
 
 #ifdef __OpenBSD__
 #define SYSCTL_MSG "\tCheck that you have set 'machdep.allowaperture=1'\n"\
