$NetBSD: patch-chrome_browser_ui_views_omnibox_omnibox__view__views.cc,v 1.8 2025/10/16 19:43:24 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/ui/views/omnibox/omnibox_view_views.cc.orig	2025-10-13 21:41:26.000000000 +0000
+++ chrome/browser/ui/views/omnibox/omnibox_view_views.cc
@@ -2335,7 +2335,7 @@ void OmniboxViewViews::MaybeAddSendTabTo
 }
 
 void OmniboxViewViews::OnPopupOpened() {
-#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // It's not great for promos to overlap the omnibox if the user opens the
   // drop-down after showing the promo. This especially causes issues on Mac and
   // Linux due to z-order/rendering issues, see crbug.com/1225046 and
