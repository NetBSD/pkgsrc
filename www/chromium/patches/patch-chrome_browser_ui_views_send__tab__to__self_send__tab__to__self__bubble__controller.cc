$NetBSD: patch-chrome_browser_ui_views_send__tab__to__self_send__tab__to__self__bubble__controller.cc,v 1.1 2026/11/08 15:38:57 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/ui/views/send_tab_to_self/send_tab_to_self_bubble_controller.cc.orig	2026-11-02 23:22:33.000000000 +0000
+++ chrome/browser/ui/views/send_tab_to_self/send_tab_to_self_bubble_controller.cc
@@ -45,7 +45,7 @@
 #include "ui/events/event.h"
 #include "ui/views/bubble/bubble_dialog_delegate_view.h"
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/signin/cross_device_signin_promo_manager.h"
 #include "chrome/browser/signin/signin_util.h"
 #include "components/signin/public/base/signin_switches.h"
@@ -95,7 +95,7 @@ void SendTabToSelfBubbleController::Show
       GlobalBrowserCollection::GetInstance()->FindBrowserWithTab(
           &GetWebContents());
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (ShouldShowNoTargetDeviceQrBubble(reason, browser)) {
     // Note: `entry_point_` should always be populated here, since it's set in
     // ShowBubble() which must've been called earlier. If it's not (e.g. in some
@@ -317,7 +317,7 @@ void SendTabToSelfBubbleController::OnWi
 bool SendTabToSelfBubbleController::ShouldShowNoTargetDeviceQrBubble(
     EntryPointDisplayReason reason,
     BrowserWindowInterface* browser) {
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (reason != EntryPointDisplayReason::kInformNoTargetDevice || !browser ||
       !base::FeatureList::IsEnabled(switches::kCrossDeviceSigninFromDesktop) ||
       !base::FeatureList::IsEnabled(
