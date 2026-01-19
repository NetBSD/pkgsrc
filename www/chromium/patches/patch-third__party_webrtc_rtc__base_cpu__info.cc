$NetBSD: patch-third__party_webrtc_rtc__base_cpu__info.cc,v 1.10 2026/01/19 16:14:21 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- third_party/webrtc/rtc_base/cpu_info.cc.orig	2026-01-07 00:50:30.000000000 +0000
+++ third_party/webrtc/rtc_base/cpu_info.cc
@@ -37,7 +37,9 @@
 #include <intrin.h>
 #endif
 #if defined(WEBRTC_ARCH_ARM_FAMILY) && defined(WEBRTC_LINUX)
+#if !defined(WEBRTC_BSD)
 #include <asm/hwcap.h>
+#endif
 #include <sys/auxv.h>
 #endif
 
@@ -178,7 +180,11 @@ bool Supports(ISA instruction_set_archit
     return 0 != (android_getCpuFeatures() & ANDROID_CPU_ARM_FEATURE_NEON);
 #elif defined(WEBRTC_LINUX)
     uint64_t hwcap = 0;
+#if defined(WEBRTC_BSD)
+    elf_aux_info(AT_HWCAP, &hwcap, sizeof(hwcap));
+#else
     hwcap = getauxval(AT_HWCAP);
+#endif
 #if defined(__aarch64__)
     if ((hwcap & HWCAP_ASIMD) != 0) {
       return true;
