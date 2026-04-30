$NetBSD: patch-src_3rdparty_chromium_third__party_libaom_source_libaom_aom__ports_aarch64__cpudetect.c,v 1.3 2026/04/30 06:39:43 adam Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- src/3rdparty/chromium/third_party/libaom/source/libaom/aom_ports/aarch64_cpudetect.c.orig	2026-03-16 11:40:07.000000000 +0000
+++ src/3rdparty/chromium/third_party/libaom/source/libaom/aom_ports/aarch64_cpudetect.c
@@ -127,10 +127,98 @@ static int arm_get_cpu_caps(void) {
   return flags;
 }
 
-#elif defined(__linux__)  // end defined(AOM_USE_ANDROID_CPU_FEATURES)
+#elif defined(__OpenBSD__)
+#include <sys/sysctl.h>
+#include <machine/cpu.h>
+#include <machine/armreg.h>
+
+static int arm_get_cpu_caps(void) {
+  int flags = 0;
+  int isar0_mib[] = { CTL_MACHDEP, CPU_ID_AA64ISAR0 };
+  uint64_t cpu_id = 0;
+  size_t len = sizeof(cpu_id);
+
+  flags |= HAS_NEON;  // Neon is mandatory in Armv8.0-A.
+
+  if (sysctl(isar0_mib, 2, &cpu_id, &len, NULL, 0) < 0)
+    return flags;
+
+  if (ID_AA64ISAR0_CRC32(cpu_id) >= ID_AA64ISAR0_CRC32_BASE)
+    flags |= HAS_ARM_CRC32;
+
+  return flags;
+}
+
+#elif defined(__NetBSD__)
+#include <sys/param.h>
+#include <sys/sysctl.h>
+#include <machine/armreg.h>
+#include <stdio.h>
+
+
+static int arm_get_cpu_caps(void) {
+  size_t len;
+  unsigned int curcpu;
+  int mib[] = { CTL_HW, HW_NCPU };
+  int ncpu;
+  struct aarch64_sysctl_cpu_id id;
+  char path[32];
+  int num_crc32 = 0;
+  int num_dp = 0;
+  int num_i8mm = 0;
+  int num_sve = 0;
+  int flags = HAS_NEON;
+
+  len = sizeof(ncpu);
+  if (sysctl(mib, 2, &ncpu, &len, NULL, 0) < 0)
+    return flags;
+
+  for (curcpu = 0; curcpu < ncpu; curcpu++) {
+    len = sizeof(id);
+    snprintf(path, sizeof(path), "machdep.cpu%d.cpu_id", curcpu);
+    if (sysctlbyname(path, &id, &len, NULL, 0) < 0)
+      continue;
+
+    if (__SHIFTOUT(id.ac_aa64isar0, ID_AA64ISAR0_EL1_CRC32) >= ID_AA64ISAR0_EL1_CRC32_CRC32X)
+      num_crc32++;
+    if (__SHIFTOUT(id.ac_aa64isar0, ID_AA64ISAR0_EL1_DP) >= ID_AA64ISAR0_EL1_DP_UDOT)
+      num_dp++;
+    if (__SHIFTOUT(id.ac_aa64isar1, ID_AA64ISAR1_EL1_I8MM) >= ID_AA64ISAR1_EL1_I8MM_SUPPORTED)
+      num_i8mm++;
+    if (__SHIFTOUT(id.ac_aa64pfr0, ID_AA64PFR0_EL1_SVE) >= ID_AA64PFR0_EL1_SVE_IMPL)
+      num_sve++;
+  }
+
+  if (num_crc32 == ncpu)
+    flags |= HAS_ARM_CRC32;
+  if (num_dp == ncpu)
+    flags |= HAS_NEON_DOTPROD;
+  if (num_i8mm == ncpu)
+    flags |= HAS_NEON_I8MM;
+  if (num_sve == ncpu)
+    flags |= HAS_SVE;
+
+  return flags;
+}
+
+#elif defined(__linux__) || defined(__FreeBSD__)  // end defined(AOM_USE_ANDROID_CPU_FEATURES)
 
 #include <sys/auxv.h>
 
+#if defined(__FreeBSD__)
+static unsigned long getauxval(unsigned long type)
+{
+    /* Only AT_HWCAP* return unsigned long */
+    if (type != AT_HWCAP && type != AT_HWCAP2) {
+        return 0;
+    }
+
+    unsigned long ret = 0;
+    elf_aux_info(type, &ret, sizeof(ret));
+    return ret;
+}
+#endif
+
 // Define hwcap values ourselves: building with an old auxv header where these
 // hwcap values are not defined should not prevent features from being enabled.
 #define AOM_AARCH64_HWCAP_CRC32 (1 << 7)
