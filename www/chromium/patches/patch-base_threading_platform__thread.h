$NetBSD: patch-base_threading_platform__thread.h,v 1.14 2026/01/19 16:14:07 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- base/threading/platform_thread.h.orig	2026-01-07 00:50:30.000000000 +0000
+++ base/threading/platform_thread.h
@@ -56,6 +56,8 @@ class BASE_EXPORT PlatformThreadId {
   using UnderlyingType = zx_koid_t;
 #elif BUILDFLAG(IS_APPLE)
   using UnderlyingType = uint64_t;
+#elif BUILDFLAG(IS_BSD)
+  using UnderlyingType = uint64_t;
 #elif BUILDFLAG(IS_POSIX)
   using UnderlyingType = pid_t;
 #endif
