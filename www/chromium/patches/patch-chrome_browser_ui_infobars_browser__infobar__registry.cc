$NetBSD: patch-chrome_browser_ui_infobars_browser__infobar__registry.cc,v 1.4 2026/10/16 15:30:47 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/ui/infobars/browser_infobar_registry.cc.orig	2026-10-14 21:09:54.000000000 +0000
+++ chrome/browser/ui/infobars/browser_infobar_registry.cc
@@ -49,7 +49,7 @@
 #include "chrome/browser/ui/startup/default_browser_prompt/pin_infobar/pin_infobar_controller.h"
 #endif
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/ui/views/session_restore_infobar/session_restore_infobar_manager.h"
 #endif
 
@@ -310,7 +310,7 @@ void RegisterInfoBars() {
   }
 #endif
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (IsInfoBarMigrated(InfoBarDelegate::DEFAULT_BROWSER_INFOBAR_DELEGATE)) {
     auto spec =
         InfoBarSpec::Builder(InfoBarDelegate::DEFAULT_BROWSER_INFOBAR_DELEGATE)
