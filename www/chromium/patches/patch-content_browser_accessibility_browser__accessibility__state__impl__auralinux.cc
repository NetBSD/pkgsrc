$NetBSD: patch-content_browser_accessibility_browser__accessibility__state__impl__auralinux.cc,v 1.2 2025/07/07 09:23:32 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- content/browser/accessibility/browser_accessibility_state_impl_auralinux.cc.orig	2025-06-30 06:54:11.000000000 +0000
+++ content/browser/accessibility/browser_accessibility_state_impl_auralinux.cc
@@ -33,7 +33,15 @@ bool CheckCmdlineForOrca(const std::stri
   std::string cmdline;
   std::stringstream ss(cmdline_all);
   while (std::getline(ss, cmdline, '\0')) {
+#if BUILDFLAG(IS_BSD)
+#if BUILDFLAG(IS_NETBSD)
+    re2::RE2 orca_regex(R"((^|/)(usr/)?(pkg/)?bin/orca(\s|$))");
+#else
+    re2::RE2 orca_regex(R"((^|/)(usr/)?(local/)?bin/orca(\s|$))");
+#endif
+#else
     re2::RE2 orca_regex(R"((^|/)(usr/)?bin/orca(\s|$))");
+#endif
     if (re2::RE2::PartialMatch(cmdline, orca_regex)) {
       return true;  // Orca was found
     }
@@ -43,6 +51,10 @@ bool CheckCmdlineForOrca(const std::stri
 
 // Returns true if Orca is active.
 bool DiscoverOrca() {
+#if BUILDFLAG(IS_BSD)
+  NOTIMPLEMENTED();
+  return false;
+#else
   // NOTE: this method is run from another thread to reduce jank, since
   // there's no guarantee these system calls will return quickly.
   std::unique_ptr<DIR, decltype(&CloseDir)> proc_dir(opendir("/proc"),
@@ -80,6 +92,7 @@ bool DiscoverOrca() {
   }
 
   return is_orca_active;
+#endif
 }
 
 }  // namespace
