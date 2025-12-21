$NetBSD: patch-src_3rdparty_chromium_content_browser_child__process__launcher__helper.h,v 1.1 2025/12/21 09:38:26 markd Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- src/3rdparty/chromium/content/browser/child_process_launcher_helper.h.orig	2025-05-29 01:27:28.000000000 +0000
+++ src/3rdparty/chromium/content/browser/child_process_launcher_helper.h
@@ -293,7 +293,7 @@ class ChildProcessLauncherHelper
   std::optional<base::ProcessId> process_id_ = std::nullopt;
 #endif  // BUILDFLAG(IS_CHROMEOS)
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   // The priority of the process. The state is stored to avoid changing the
   // setting repeatedly.
   std::optional<base::Process::Priority> priority_;
