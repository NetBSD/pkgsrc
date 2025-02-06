$NetBSD: patch-third__party_brotli_common_platform.h,v 1.1 2025/02/06 09:58:24 wiz Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- third_party/brotli/common/platform.h.orig	2024-12-17 17:58:49.000000000 +0000
+++ third_party/brotli/common/platform.h
@@ -28,7 +28,7 @@
 #include <brotli/port.h>
 #include <brotli/types.h>
 
-#if defined(OS_LINUX) || defined(OS_CYGWIN) || defined(__EMSCRIPTEN__)
+#if defined(OS_LINUX) || defined(OS_CYGWIN) || defined(__EMSCRIPTEN__) || defined(OS_BSD)
 #include <endian.h>
 #elif defined(OS_FREEBSD)
 #include <machine/endian.h>
