$NetBSD: patch-third__party_dawn_src_utils_platform.h,v 1.3 2026/08/09 06:31:22 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- third_party/dawn/src/utils/platform.h.orig	2026-08-05 20:17:42.000000000 +0000
+++ third_party/dawn/src/utils/platform.h
@@ -60,6 +60,11 @@
 #error "Unsupported Windows platform."
 #endif
 
+#elif defined(__OpenBSD__) || defined(__FreeBSD__) || defined(__NetBSD__)
+#define DAWN_PLATFORM_IS_LINUX 1
+#define DAWN_PLATFORM_IS_BSD 1
+#define DAWN_PLATFORM_IS_POSIX 1
+
 #elif defined(__linux__)
 #define DAWN_PLATFORM_IS_LINUX 1
 #define DAWN_PLATFORM_IS_POSIX 1
