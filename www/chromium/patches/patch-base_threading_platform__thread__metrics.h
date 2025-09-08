$NetBSD: patch-base_threading_platform__thread__metrics.h,v 1.2 2025/09/08 13:24:16 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- base/threading/platform_thread_metrics.h.orig	2025-08-29 18:50:09.000000000 +0000
+++ base/threading/platform_thread_metrics.h
@@ -51,7 +51,7 @@ class BASE_EXPORT PlatformThreadMetrics 
       PlatformThreadHandle handle);
 #endif
 
-#if BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_CHROMEOS) || \
+#if BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD) || \
     BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN)
   static std::unique_ptr<PlatformThreadMetrics> CreateFromId(
       PlatformThreadId tid);
@@ -93,7 +93,7 @@ class BASE_EXPORT PlatformThreadMetrics 
 
   PlatformThreadHandle handle_;
 #elif BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_CHROMEOS) || \
-    BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_LINUX)
+    BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   explicit PlatformThreadMetrics(PlatformThreadId tid) : tid_(tid) {}
 
   PlatformThreadId tid_;
