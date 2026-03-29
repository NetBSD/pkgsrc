$NetBSD: patch-src_3rdparty_chromium_third__party_dav1d_libdav1d_src_arm_cpu.c,v 1.1 2026/03/29 16:57:04 tnn Exp $

--- src/3rdparty/chromium/third_party/dav1d/libdav1d/src/arm/cpu.c.orig	2026-01-23 19:06:19.000000000 +0000
+++ src/3rdparty/chromium/third_party/dav1d/libdav1d/src/arm/cpu.c
@@ -131,6 +131,48 @@ COLD unsigned dav1d_get_cpu_flags_arm(void) {
      return flags;
 }
 
+#elif defined(__NetBSD__) && ARCH_AARCH64
+#define _NETBSD_SOURCE 1 /* XXX may be too late for this */
+#include <sys/param.h>
+#include <sys/sysctl.h>
+#include <machine/armreg.h>
+#include <stdio.h>
+
+COLD unsigned dav1d_get_cpu_flags_arm(void) {
+    unsigned flags = dav1d_get_default_cpu_flags();
+
+    size_t len;
+    unsigned int curcpu;
+    int mib[] = { CTL_HW, HW_NCPU };
+    int ncpu;
+    struct aarch64_sysctl_cpu_id id;
+    char path[32];
+    int num_dotprod = 0;
+    int num_i8mm = 0;
+
+    len = sizeof(ncpu);
+    if (sysctl(mib, 2, &ncpu, &len, NULL, 0) < 0)
+        return flags;
+
+    for (curcpu = 0; curcpu < ncpu; curcpu++) {
+        len = sizeof(id);
+        snprintf(path, sizeof(path), "machdep.cpu%d.cpu_id", curcpu);
+        if (sysctlbyname(path, &id, &len, NULL, 0) < 0)
+            continue;
+        if (__SHIFTOUT(id.ac_aa64isar0, ID_AA64ISAR0_EL1_DP) >= ID_AA64ISAR0_EL1_DP_UDOT)
+            num_dotprod++;
+        if (__SHIFTOUT(id.ac_aa64isar1, ID_AA64ISAR1_EL1_I8MM) >= ID_AA64ISAR1_EL1_I8MM_SUPPORTED)
+            num_i8mm++;
+    }
+
+    if (num_dotprod == ncpu)
+        flags |= DAV1D_ARM_CPU_FLAG_DOTPROD;
+    if (num_i8mm == ncpu)
+        flags |= DAV1D_ARM_CPU_FLAG_I8MM;
+
+    return flags;
+}
+
 #elif defined(_WIN32)
 #include <windows.h>
 
