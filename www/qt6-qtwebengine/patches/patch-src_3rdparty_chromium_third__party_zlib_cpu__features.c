$NetBSD: patch-src_3rdparty_chromium_third__party_zlib_cpu__features.c,v 1.2 2026/03/29 16:57:04 tnn Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- src/3rdparty/chromium/third_party/zlib/cpu_features.c.orig	2026-01-23 19:06:19.000000000 +0000
+++ src/3rdparty/chromium/third_party/zlib/cpu_features.c
@@ -39,7 +39,9 @@ int ZLIB_INTERNAL riscv_cpu_enable_vclmul = 0;
 #ifndef CPU_NO_SIMD
 
 #if defined(ARMV8_OS_ANDROID) || defined(ARMV8_OS_LINUX) || \
-    defined(ARMV8_OS_FUCHSIA) || defined(ARMV8_OS_IOS)
+    defined(ARMV8_OS_FUCHSIA) || defined(ARMV8_OS_IOS) || \
+    defined(ARMV8_OS_OPENBSD) || defined(ARMV8_OS_FREEBSD) || \
+    defined(ARMV8_OS_NETBSD)
 #include <pthread.h>
 #endif
 
@@ -56,6 +58,14 @@ int ZLIB_INTERNAL riscv_cpu_enable_vclmul = 0;
 #include <windows.h>
 #elif defined(ARMV8_OS_IOS)
 #include <sys/sysctl.h>
+#elif defined(ARMV8_OS_OPENBSD)
+#include <sys/sysctl.h>
+#include <machine/cpu.h>
+#include <machine/armreg.h>
+#elif defined(ARMV8_OS_NETBSD)
+#include <sys/sysctl.h>
+#include <machine/armreg.h>
+#include <stdio.h>
 #elif !defined(_MSC_VER)
 #include <pthread.h>
 #else
@@ -81,7 +91,7 @@ void ZLIB_INTERNAL cpu_check_features(void)
 #elif defined(ARMV8_OS_ANDROID) || defined(ARMV8_OS_LINUX) || \
     defined(ARMV8_OS_MACOS) || defined(ARMV8_OS_FUCHSIA) || \
     defined(X86_NOT_WINDOWS) || defined(ARMV8_OS_IOS) || \
-    defined(RISCV_RVV) || defined(__ARM_NEON__) || defined(__ARM_NEON)
+    defined(RISCV_RVV) || defined(__ARM_NEON__) || defined(__ARM_NEON) || defined(ARMV8_OS_OPENBSD) || defined(ARMV8_OS_FREEBSD) || defined(ARMV8_OS_NETBSD)
 #if !defined(ARMV8_OS_MACOS)
 // _cpu_check_features() doesn't need to do anything on mac/arm since all
 // features are known at build time, so don't call it.
@@ -122,6 +132,47 @@ static void _cpu_check_features(void)
     unsigned long features = getauxval(AT_HWCAP2);
     arm_cpu_enable_crc32 = !!(features & HWCAP2_CRC32);
     arm_cpu_enable_pmull = !!(features & HWCAP2_PMULL);
+#elif defined(ARMV8_OS_OPENBSD)
+    int isar0_mib[] = { CTL_MACHDEP, CPU_ID_AA64ISAR0 };
+    uint64_t cpu_id = 0;
+    size_t len = sizeof(cpu_id);
+    if (sysctl(isar0_mib, 2, &cpu_id, &len, NULL, 0) < 0)
+        return;
+    if (ID_AA64ISAR0_AES(cpu_id) >= ID_AA64ISAR0_AES_PMULL)
+        arm_cpu_enable_pmull = 1;
+
+    if (ID_AA64ISAR0_CRC32(cpu_id) >= ID_AA64ISAR0_CRC32_BASE)
+        arm_cpu_enable_crc32 = 1;
+#elif defined(ARMV8_OS_NETBSD)
+    size_t len;
+    unsigned int curcpu;
+    int mib[] = { CTL_HW, HW_NCPU };
+    int ncpu;
+    struct aarch64_sysctl_cpu_id id;
+    char path[32];
+    int num_pmull = 0;
+    int num_crc32 = 0;
+
+    len = sizeof(ncpu);
+    if (sysctl(mib, 2, &ncpu, &len, NULL, 0) < 0)
+        return;
+
+    for (curcpu = 0; curcpu < ncpu; curcpu++) {
+        len = sizeof(id);
+        snprintf(path, sizeof(path), "machdep.cpu%d.cpu_id", curcpu);
+        if (sysctlbyname(path, &id, &len, NULL, 0) < 0)
+            continue;
+
+        if (__SHIFTOUT(id.ac_aa64isar0, ID_AA64ISAR0_EL1_AES) >= ID_AA64ISAR0_EL1_AES_PMUL)
+           num_pmull++;
+        if (__SHIFTOUT(id.ac_aa64isar0, ID_AA64ISAR0_EL1_CRC32) >= ID_AA64ISAR0_EL1_CRC32_CRC32X)
+           num_crc32++;
+    }
+
+    if (num_pmull == ncpu)
+        arm_cpu_enable_pmull = 1;
+    if (num_crc32 == ncpu)
+        arm_cpu_enable_crc32 = 1;
 #elif defined(ARMV8_OS_FUCHSIA)
     uint32_t features;
     zx_status_t rc = zx_system_get_features(ZX_FEATURE_KIND_CPU, &features);
