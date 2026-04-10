$NetBSD: patch-base_threading_platform__thread.h,v 1.17 2026/04/10 17:31:47 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- base/threading/platform_thread.h.orig	2026-04-06 16:25:54.000000000 +0000
+++ base/threading/platform_thread.h
@@ -67,6 +67,8 @@ class BASE_EXPORT PlatformThreadId {
   using UnderlyingType = zx_koid_t;
 #elif BUILDFLAG(IS_APPLE)
   using UnderlyingType = uint64_t;
+#elif BUILDFLAG(IS_BSD)
+  using UnderlyingType = uint64_t;
 #elif BUILDFLAG(IS_POSIX)
   using UnderlyingType = pid_t;
 #endif
