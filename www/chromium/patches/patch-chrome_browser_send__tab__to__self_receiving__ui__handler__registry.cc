$NetBSD: patch-chrome_browser_send__tab__to__self_receiving__ui__handler__registry.cc,v 1.1 2025/02/06 09:57:51 wiz Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/send_tab_to_self/receiving_ui_handler_registry.cc.orig	2024-12-17 17:58:49.000000000 +0000
+++ chrome/browser/send_tab_to_self/receiving_ui_handler_registry.cc
@@ -15,7 +15,7 @@
 #include "components/send_tab_to_self/features.h"
 
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_MAC) || \
-    BUILDFLAG(IS_WIN)
+    BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/send_tab_to_self/desktop_notification_handler.h"
 #include "chrome/browser/ui/send_tab_to_self/send_tab_to_self_toolbar_icon_controller.h"
 #endif
@@ -47,7 +47,7 @@ SendTabToSelfToolbarIconController*
 ReceivingUiHandlerRegistry::GetToolbarButtonControllerForProfile(
     Profile* profile) {
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_MAC) || \
-    BUILDFLAG(IS_WIN)
+    BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
   for (const std::unique_ptr<ReceivingUiHandler>& handler :
        applicable_handlers_) {
     auto* button_controller =
