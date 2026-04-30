$NetBSD: patch-src_3rdparty_chromium_content_browser_accessibility_browser__accessibility__state__impl__auralinux.cc,v 1.1 2026/04/30 06:39:40 adam Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- src/3rdparty/chromium/content/browser/accessibility/browser_accessibility_state_impl_auralinux.cc.orig	2026-03-16 11:40:07.000000000 +0000
+++ src/3rdparty/chromium/content/browser/accessibility/browser_accessibility_state_impl_auralinux.cc
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
