$NetBSD: patch-chrome_browser_ui_webui_side__panel_customize__chrome_customize__chrome__page__handler.cc,v 1.9 2025/12/23 13:22:15 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/ui/webui/side_panel/customize_chrome/customize_chrome_page_handler.cc.orig	2025-12-17 23:05:18.000000000 +0000
+++ chrome/browser/ui/webui/side_panel/customize_chrome/customize_chrome_page_handler.cc
@@ -572,7 +572,7 @@ void CustomizeChromePageHandler::UpdateF
       side_panel::mojom::ManagementNoticeState::New();
   management_notice_state->can_be_shown = false;
   management_notice_state->enabled_by_policy = false;
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   enterprise_util::BrowserManagementNoticeState state =
       enterprise_util::GetManagementNoticeStateForNTPFooter(profile_);
   switch (state) {
