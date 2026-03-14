$NetBSD: patch-third__party_dawn_src_dawn_common_Platform.h,v 1.16 2026/03/14 12:40:41 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- third_party/dawn/src/dawn/common/Platform.h.orig	2026-03-11 22:12:25.000000000 +0000
+++ third_party/dawn/src/dawn/common/Platform.h
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
