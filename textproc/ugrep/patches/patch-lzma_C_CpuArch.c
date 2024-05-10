$NetBSD: patch-lzma_C_CpuArch.c,v 1.1 2024/05/10 16:06:28 pho Exp $

Fix build on non-Linux arm32/aarch64 platforms. Especially on NetBSD the
kernel currently only provides information about optional CPU features to
userland via /proc/cpuinfo. Providing AT_SUN_HWCAP via auxv would be
nice. Adding getauxval(3) to crt would also be nice.

--- lzma/C/CpuArch.c.orig	2024-05-10 15:18:53.793198757 +0000
+++ lzma/C/CpuArch.c
@@ -760,12 +760,13 @@ BoolInt CPU_IsSupported_AES (void) { ret
 
 #else // __APPLE__
 
-#include <sys/auxv.h>
-
-#define USE_HWCAP
+#if defined(__linux__)
+#  define USE_HWCAP
+#endif
 
 #ifdef USE_HWCAP
 
+#include <sys/auxv.h>
 #include <asm/hwcap.h>
 
   #define MY_HWCAP_CHECK_FUNC_2(name1, name2) \
