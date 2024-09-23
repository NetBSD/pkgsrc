$NetBSD: patch-platform_media_libjpeg_simd_powerpc_jsimd.c,v 1.1 2024/09/23 11:12:10 martin Exp $

Add support for NetBSD/powerpc ALTIVEC cpu feature detection
https://repo.palemoon.org/MoonchildProductions/UXP/pulls/2591

--- platform/media/libjpeg/simd/powerpc/jsimd.c.orig
+++ platform/media/libjpeg/simd/powerpc/jsimd.c
@@ -38,6 +38,9 @@
 #elif defined(__FreeBSD__)
 #include <machine/cpu.h>
 #include <sys/auxv.h>
+#elif defined(__NetBSD__)
+#include <sys/param.h>
+#include <sys/sysctl.h>
 #endif
 
 static unsigned int simd_support = ~0;
@@ -127,6 +130,9 @@ init_simd(void)
   size_t len = sizeof(altivec);
 #elif defined(__FreeBSD__)
   unsigned long cpufeatures = 0;
+#elif defined(__NetBSD__)
+  int ret, av;
+  size_t len;
 #endif
 
   if (simd_support != ~0U)
@@ -149,6 +155,11 @@ init_simd(void)
 #elif defined(__OpenBSD__)
   if (sysctl(mib, 2, &altivec, &len, NULL, 0) == 0 && altivec != 0)
     simd_support |= JSIMD_ALTIVEC;
+#elif defined(__NetBSD__)
+  len = sizeof(av);
+  ret = sysctlbyname("machdep.altivec", &av, &len, NULL, 0);
+  if (!ret && av)
+    simd_support |= JSIMD_ALTIVEC;
 #elif defined(__FreeBSD__)
   elf_aux_info(AT_HWCAP, &cpufeatures, sizeof(cpufeatures));
   if (cpufeatures & PPC_FEATURE_HAS_ALTIVEC)
