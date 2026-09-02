$NetBSD: patch-content_browser_accessibility_browser__accessibility__state__impl__auralinux.cc,v 1.24 2026/09/02 13:13:30 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- content/browser/accessibility/browser_accessibility_state_impl_auralinux.cc.orig	2026-08-31 22:47:51.000000000 +0000
+++ content/browser/accessibility/browser_accessibility_state_impl_auralinux.cc
@@ -14,6 +14,7 @@
 #include <sstream>
 #include <string>
 
+#include "base/notimplemented.h"
 #include "base/debug/crash_logging.h"
 #include "base/logging.h"
 #include "base/metrics/histogram_macros.h"
@@ -57,6 +58,10 @@ namespace {
 
 // Returns true if Orca is active.
 bool DiscoverOrca() {
+#if BUILDFLAG(IS_BSD)
+  NOTIMPLEMENTED();
+  return false;
+#else
   // NOTE: this method is run from another thread to reduce jank, since
   // there's no guarantee these system calls will return quickly.
   std::unique_ptr<DIR, decltype(&CloseDir)> proc_dir(opendir("/proc"),
@@ -103,6 +108,7 @@ bool DiscoverOrca() {
   }
 
   return is_orca_active;
+#endif
 }
 
 }  // namespace
