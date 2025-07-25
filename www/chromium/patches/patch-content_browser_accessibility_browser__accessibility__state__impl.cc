$NetBSD: patch-content_browser_accessibility_browser__accessibility__state__impl.cc,v 1.3 2025/07/25 16:17:16 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- content/browser/accessibility/browser_accessibility_state_impl.cc.orig	2025-07-21 19:32:31.000000000 +0000
+++ content/browser/accessibility/browser_accessibility_state_impl.cc
@@ -278,7 +278,7 @@ BrowserAccessibilityStateImpl* BrowserAc
 
 // On Android, Mac, Windows and Linux there are platform-specific subclasses.
 #if !BUILDFLAG(IS_ANDROID) && !BUILDFLAG(IS_WIN) && !BUILDFLAG(IS_MAC) && \
-    !BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_CHROMEOS)
+    !BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_CHROMEOS) && !BUILDFLAG(IS_BSD)
 // static
 std::unique_ptr<BrowserAccessibilityStateImpl>
 BrowserAccessibilityStateImpl::Create() {
