$NetBSD: patch-chrome_browser_ui_views_app__menu_send__tab__to__self__dynamic__menu.cc,v 1.1 2026/11/08 15:38:56 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/ui/views/app_menu/send_tab_to_self_dynamic_menu.cc.orig	2026-11-02 23:22:33.000000000 +0000
+++ chrome/browser/ui/views/app_menu/send_tab_to_self_dynamic_menu.cc
@@ -149,7 +149,7 @@ bool SendTabToSelfDynamicMenu::ShouldSho
       return base::FeatureList::IsEnabled(
           send_tab_to_self::kSendTabToSelfSubmenuSigninPromos);
     case send_tab_to_self::EntryPointDisplayReason::kInformNoTargetDevice:
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
       return base::FeatureList::IsEnabled(
                  send_tab_to_self::kSendTabToSelfSubmenuSigninPromos) &&
              base::FeatureList::IsEnabled(
