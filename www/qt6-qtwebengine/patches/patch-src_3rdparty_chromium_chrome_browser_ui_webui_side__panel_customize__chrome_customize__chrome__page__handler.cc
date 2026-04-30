$NetBSD: patch-src_3rdparty_chromium_chrome_browser_ui_webui_side__panel_customize__chrome_customize__chrome__page__handler.cc,v 1.1 2026/04/30 06:39:36 adam Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- src/3rdparty/chromium/chrome/browser/ui/webui/side_panel/customize_chrome/customize_chrome_page_handler.cc.orig	2026-03-16 11:40:07.000000000 +0000
+++ src/3rdparty/chromium/chrome/browser/ui/webui/side_panel/customize_chrome/customize_chrome_page_handler.cc
@@ -516,7 +516,7 @@ void CustomizeChromePageHandler::UpdateF
       side_panel::mojom::ManagementNoticeState::New();
   management_notice_state->can_be_shown = false;
   management_notice_state->enabled_by_policy = false;
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   enterprise_util::BrowserManagementNoticeState state =
       enterprise_util::GetManagementNoticeStateForNTPFooter(profile_);
   switch (state) {
