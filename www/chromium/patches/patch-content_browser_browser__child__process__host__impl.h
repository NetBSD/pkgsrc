$NetBSD: patch-content_browser_browser__child__process__host__impl.h,v 1.1 2025/02/06 09:58:04 wiz Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- content/browser/browser_child_process_host_impl.h.orig	2024-12-17 17:58:49.000000000 +0000
+++ content/browser/browser_child_process_host_impl.h
@@ -35,7 +35,7 @@
 #include "base/win/object_watcher.h"
 #endif
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 #include "content/browser/child_thread_type_switcher_linux.h"
 #endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
 
@@ -269,7 +269,7 @@ class BrowserChildProcessHostImpl
   std::unique_ptr<tracing::SystemTracingService> system_tracing_service_;
 #endif
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   ChildThreadTypeSwitcher child_thread_type_switcher_;
 #endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
 
