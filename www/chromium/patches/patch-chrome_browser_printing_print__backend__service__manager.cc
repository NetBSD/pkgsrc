$NetBSD: patch-chrome_browser_printing_print__backend__service__manager.cc,v 1.14 2026/01/19 16:14:09 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/printing/print_backend_service_manager.cc.orig	2026-01-07 00:50:30.000000000 +0000
+++ chrome/browser/printing/print_backend_service_manager.cc
@@ -36,7 +36,7 @@
 #include "printing/printing_context.h"
 #include "printing/printing_features.h"
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "content/public/common/content_switches.h"
 #include "ui/linux/linux_ui.h"
 #endif
@@ -886,7 +886,7 @@ PrintBackendServiceManager::GetServiceFr
             << remote_id << "`";
 
     std::vector<std::string> extra_switches;
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     if (auto* linux_ui = ui::LinuxUi::instance()) {
       extra_switches = linux_ui->GetCmdLineFlagsForCopy();
     }
@@ -1072,7 +1072,7 @@ PrintBackendServiceManager::DetermineIdl
       return kNoClientsRegisteredResetOnIdleTimeout;
 
     case ClientType::kQueryWithUi:
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
       // No need to update if there were other query with UI clients.
       if (HasQueryWithUiClientForRemoteId(remote_id)) {
         return std::nullopt;
