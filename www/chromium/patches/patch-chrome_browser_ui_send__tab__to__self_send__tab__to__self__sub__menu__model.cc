$NetBSD: patch-chrome_browser_ui_send__tab__to__self_send__tab__to__self__sub__menu__model.cc,v 1.2 2026/11/19 19:45:55 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/ui/send_tab_to_self/send_tab_to_self_sub_menu_model.cc.orig	2026-11-11 21:01:38.000000000 +0000
+++ chrome/browser/ui/send_tab_to_self/send_tab_to_self_sub_menu_model.cc
@@ -141,7 +141,7 @@ bool ShouldShowSubmenu(ShareEntryPoint e
     case EntryPointDisplayReason::kOfferReauth:
       return base::FeatureList::IsEnabled(kSendTabToSelfSubmenuSigninPromos);
     case EntryPointDisplayReason::kInformNoTargetDevice:
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
       return base::FeatureList::IsEnabled(kSendTabToSelfSubmenuSigninPromos) &&
              base::FeatureList::IsEnabled(kSendTabToSelfNoTargetDeviceQrCode);
 #else
