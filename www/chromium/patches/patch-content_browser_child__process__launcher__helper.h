$NetBSD: patch-content_browser_child__process__launcher__helper.h,v 1.1 2025/02/06 09:58:05 wiz Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- content/browser/child_process_launcher_helper.h.orig	2024-12-17 17:58:49.000000000 +0000
+++ content/browser/child_process_launcher_helper.h
@@ -304,7 +304,7 @@ class ChildProcessLauncherHelper
   std::optional<base::ProcessId> process_id_ = std::nullopt;
 #endif  // BUILDFLAG(IS_CHROMEOS)
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   // The priority of the process. The state is stored to avoid changing the
   // setting repeatedly.
   std::optional<base::Process::Priority> priority_;
