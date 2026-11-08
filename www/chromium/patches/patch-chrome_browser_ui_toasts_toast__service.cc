$NetBSD: patch-chrome_browser_ui_toasts_toast__service.cc,v 1.4 2026/11/08 15:38:56 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/ui/toasts/toast_service.cc.orig	2026-11-02 23:22:33.000000000 +0000
+++ chrome/browser/ui/toasts/toast_service.cc
@@ -143,7 +143,7 @@ void ToastService::RegisterToasts() {
                                   IDS_CLEAR_BROWSING_DATA_TOAST_BODY)
           .Build());
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   toast_registry_->RegisterToast(
       ToastId::kScheduledRestartOnIdle,
       ToastSpecification::Builder(features::IsRoundedIconsEnabled()
