$NetBSD: patch-chrome_browser_ui_sharing__hub_sharing__hub__bubble__controller.h,v 1.6 2025/09/08 13:24:20 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/ui/sharing_hub/sharing_hub_bubble_controller.h.orig	2025-08-29 18:50:09.000000000 +0000
+++ chrome/browser/ui/sharing_hub/sharing_hub_bubble_controller.h
@@ -36,7 +36,7 @@ class SharingHubBubbleController {
   // Returns true if the omnibox icon should be shown.
   virtual bool ShouldOfferOmniboxIcon() = 0;
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // This method returns the set of first-party actions, which are actions
   // internal to Chrome. Third-party actions (those outside Chrome) are
   // currently not supported.
