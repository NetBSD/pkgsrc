$NetBSD: patch-src_3rdparty_chromium_third__party_boringssl_src_crypto_cpu__aarch64__openbsd.cc,v 1.2 2026/04/30 06:39:43 adam Exp $

Add NetBSD support.

--- src/3rdparty/chromium/third_party/boringssl/src/crypto/cpu_aarch64_openbsd.cc.orig	2026-03-16 11:40:07.000000000 +0000
+++ src/3rdparty/chromium/third_party/boringssl/src/crypto/cpu_aarch64_openbsd.cc
@@ -57,3 +57,65 @@ void OPENSSL_cpuid_setup(void) {
 }
 
 #endif  // OPENSSL_AARCH64 && OPENSSL_OPENBSD && !OPENSSL_STATIC_ARMCAP
+
+#if defined(OPENSSL_AARCH64) && defined(OPENSSL_NETBSD) && \
+    !defined(OPENSSL_STATIC_ARMCAP) && !defined(OPENSSL_NO_ASM)
+
+#include <sys/param.h>
+#include <sys/sysctl.h>
+#include <machine/armreg.h>
+#include <stdio.h>
+
+#include "internal.h"
+
+
+void OPENSSL_cpuid_setup() {
+  size_t len;
+  unsigned int curcpu;
+  int mib[] = { CTL_HW, HW_NCPU };
+  int ncpu;
+  struct aarch64_sysctl_cpu_id id;
+  char path[32];
+  int num_aes = 0;
+  int num_pmull = 0;
+  int num_sha1 = 0;
+  int num_sha256 = 0;
+  int num_sha512 = 0;
+
+  OPENSSL_armcap_P |= ARMV7_NEON;
+
+  len = sizeof(ncpu);
+  if (sysctl(mib, 2, &ncpu, &len, NULL, 0) < 0)
+    return;
+
+  for (curcpu = 0; curcpu < ncpu; curcpu++) {
+    len = sizeof(id);
+    snprintf(path, sizeof(path), "machdep.cpu%d.cpu_id", curcpu);
+    if (sysctlbyname(path, &id, &len, NULL, 0) < 0)
+      continue;
+
+    if (__SHIFTOUT(id.ac_aa64isar0, ID_AA64ISAR0_EL1_AES) >= ID_AA64ISAR0_EL1_AES_AES)
+      num_aes++;
+    if (__SHIFTOUT(id.ac_aa64isar0, ID_AA64ISAR0_EL1_AES) >= ID_AA64ISAR0_EL1_AES_PMUL)
+      num_pmull++;
+    if (__SHIFTOUT(id.ac_aa64isar0, ID_AA64ISAR0_EL1_SHA1) >= ID_AA64ISAR0_EL1_SHA1_SHA1CPMHSU)
+      num_sha1++;
+    if (__SHIFTOUT(id.ac_aa64isar0, ID_AA64ISAR0_EL1_SHA2) >= ID_AA64ISAR0_EL1_SHA2_SHA256HSU)
+      num_sha256++;
+    if (__SHIFTOUT(id.ac_aa64isar0, ID_AA64ISAR0_EL1_SHA2) >= ID_AA64ISAR0_EL1_SHA2_SHA512HSU)
+      num_sha512++;
+  }
+
+  if (num_aes == ncpu)
+    OPENSSL_armcap_P |= ARMV8_AES;
+  if (num_pmull == ncpu)
+    OPENSSL_armcap_P |= ARMV8_PMULL;
+  if (num_sha1 == ncpu)
+    OPENSSL_armcap_P |= ARMV8_SHA1;
+  if (num_sha256 == ncpu)
+    OPENSSL_armcap_P |= ARMV8_SHA256;
+  if (num_sha512 == ncpu)
+    OPENSSL_armcap_P |= ARMV8_SHA512;
+}
+
+#endif  // OPENSSL_AARCH64 && OPENSSL_NETBSD && !OPENSSL_STATIC_ARMCAP
