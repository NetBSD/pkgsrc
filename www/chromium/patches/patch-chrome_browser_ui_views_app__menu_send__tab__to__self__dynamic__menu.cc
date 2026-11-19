$NetBSD: patch-chrome_browser_ui_views_app__menu_send__tab__to__self__dynamic__menu.cc,v 1.2 2026/11/19 19:45:55 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/ui/views/app_menu/send_tab_to_self_dynamic_menu.cc.orig	2026-11-11 21:01:38.000000000 +0000
+++ chrome/browser/ui/views/app_menu/send_tab_to_self_dynamic_menu.cc
@@ -103,7 +103,7 @@ bool SendTabToSelfDynamicMenu::ShouldSho
       return base::FeatureList::IsEnabled(
           send_tab_to_self::kSendTabToSelfSubmenuSigninPromos);
     case send_tab_to_self::EntryPointDisplayReason::kInformNoTargetDevice:
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
       return base::FeatureList::IsEnabled(
                  send_tab_to_self::kSendTabToSelfSubmenuSigninPromos) &&
              base::FeatureList::IsEnabled(
