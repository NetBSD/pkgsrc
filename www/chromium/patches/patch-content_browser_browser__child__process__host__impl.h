$NetBSD: patch-content_browser_browser__child__process__host__impl.h,v 1.14 2026/01/19 16:14:14 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- content/browser/browser_child_process_host_impl.h.orig	2026-01-07 00:50:30.000000000 +0000
+++ content/browser/browser_child_process_host_impl.h
@@ -36,7 +36,7 @@
 #include "base/win/object_watcher.h"
 #endif
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 #include "content/browser/child_thread_type_switcher_linux.h"
 #endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
 
@@ -273,7 +273,7 @@ class BrowserChildProcessHostImpl
   std::unique_ptr<tracing::SystemTracingService> system_tracing_service_;
 #endif
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   ChildThreadTypeSwitcher child_thread_type_switcher_;
 #endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
 
