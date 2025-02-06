$NetBSD: patch-third__party_libvpx_source_libvpx_vpx__ports_aarch64__cpudetect.c,v 1.1 2025/02/06 09:58:26 wiz Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- third_party/libvpx/source/libvpx/vpx_ports/aarch64_cpudetect.c.orig	2024-12-17 17:58:49.000000000 +0000
+++ third_party/libvpx/source/libvpx/vpx_ports/aarch64_cpudetect.c
@@ -120,10 +120,24 @@ static int arm_get_cpu_caps(void) {
   return flags;
 }
 
-#elif defined(__linux__)  // end defined(VPX_USE_ANDROID_CPU_FEATURES)
+#elif defined(__linux__) || defined(__FreeBSD__)  // end defined(VPX_USE_ANDROID_CPU_FEATURES)
 
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
 #define VPX_AARCH64_HWCAP_ASIMDDP (1 << 20)
