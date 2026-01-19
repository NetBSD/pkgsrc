$NetBSD: patch-content_browser_accessibility_browser__accessibility__state__impl__auralinux.cc,v 1.13 2026/01/19 16:14:14 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- content/browser/accessibility/browser_accessibility_state_impl_auralinux.cc.orig	2026-01-07 00:50:30.000000000 +0000
+++ content/browser/accessibility/browser_accessibility_state_impl_auralinux.cc
@@ -12,6 +12,7 @@
 #include <sstream>
 #include <string>
 
+#include "base/notimplemented.h"
 #include "base/debug/crash_logging.h"
 #include "base/metrics/histogram_macros.h"
 #include "base/task/thread_pool.h"
@@ -43,6 +44,10 @@ bool CheckCmdlineForOrca(const std::stri
 
 // Returns true if Orca is active.
 bool DiscoverOrca() {
+#if BUILDFLAG(IS_BSD)
+  NOTIMPLEMENTED();
+  return false;
+#else
   // NOTE: this method is run from another thread to reduce jank, since
   // there's no guarantee these system calls will return quickly.
   std::unique_ptr<DIR, decltype(&CloseDir)> proc_dir(opendir("/proc"),
@@ -80,6 +85,7 @@ bool DiscoverOrca() {
   }
 
   return is_orca_active;
+#endif
 }
 
 }  // namespace
