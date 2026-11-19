$NetBSD: patch-chrome_browser_ui_toasts_toast__service.cc,v 1.5 2026/11/19 19:45:55 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/ui/toasts/toast_service.cc.orig	2026-11-11 21:01:38.000000000 +0000
+++ chrome/browser/ui/toasts/toast_service.cc
@@ -142,7 +142,7 @@ void ToastService::RegisterToasts() {
                                   IDS_CLEAR_BROWSING_DATA_TOAST_BODY)
           .Build());
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   toast_registry_->RegisterToast(
       ToastId::kScheduledRestartOnIdle,
       ToastSpecification::Builder(features::IsRoundedIconsEnabled()
