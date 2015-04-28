$NetBSD: patch-media_libtheora_lib_arm_armcpu.c,v 1.1 2015/04/28 12:06:34 joerg Exp $

--- media/libtheora/lib/arm/armcpu.c.orig	2015-04-10 12:39:09.000000000 +0000
+++ media/libtheora/lib/arm/armcpu.c
@@ -106,6 +106,28 @@ ogg_uint32_t oc_cpu_flags_get(void){
   }
   return flags;
 }
+#elif defined(__NetBSD__)
+#include <sys/sysctl.h>
+#include <stdlib.h>
+
+ogg_uint32_t oc_cpu_flags_get(void){
+  ogg_uint32_t flags = 0;
+  int val = 0;
+  char arch_buf[16];
+  size_t lenp;
+  /* XXX EDSP? */
+  lenp = sizeof(val);
+  if (sysctlbyname("machdep.neon_present", &val, &lenp, NULL, 0) == 0 && val)
+    flags|=OC_CPU_ARM_NEON;
+  lenp = sizeof(arch_buf) - 1;
+  if (sysctlbyname("machdep.cpu_arch", arch_buf, &lenp, NULL, 0) == 0) {
+    arch_buf[lenp] = '\0';
+    val = atoi(arch_buf);
+    if (val >= 6)
+      flags |= OC_CPU_ARM_MEDIA;
+  }
+  return flags;
+}
 
 #else
 /*The feature registers which can tell us what the processor supports are
