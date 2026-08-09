$NetBSD: patch-chrome_browser_ui_webui_cr__components_searchbox_searchbox__handler.cc,v 1.11 2026/08/09 06:31:12 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/ui/webui/cr_components/searchbox/searchbox_handler.cc.orig	2026-08-05 20:17:42.000000000 +0000
+++ chrome/browser/ui/webui/cr_components/searchbox/searchbox_handler.cc
@@ -219,7 +219,7 @@ constexpr char kMacShareIconResourceName
 #elif BUILDFLAG(IS_WIN)
 constexpr char kWinShareIconResourceName[] =
     "//resources/cr_components/searchbox/icons/win_share_cr23.svg";
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 constexpr char kLinuxShareIconResourceName[] =
     "//resources/cr_components/searchbox/icons/share_cr23.svg";
 #else
@@ -740,7 +740,7 @@ std::string SearchboxHandler::Autocomple
                         : omnibox::kShareWinChromeRefreshOldIcon.name)) {
     return kWinShareIconResourceName;
   }
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (icon.name == (features::IsRoundedIconsEnabled()
                         ? omnibox::kSendIcon.name
                         : omnibox::kShareLinuxChromeRefreshOldIcon.name)) {
