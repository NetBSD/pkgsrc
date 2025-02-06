$NetBSD: patch-chrome_browser_printing_print__backend__service__manager.cc,v 1.1 2025/02/06 09:57:50 wiz Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/printing/print_backend_service_manager.cc.orig	2024-12-17 17:58:49.000000000 +0000
+++ chrome/browser/printing/print_backend_service_manager.cc
@@ -36,7 +36,7 @@
 #include "printing/printing_context.h"
 #include "printing/printing_features.h"
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "content/public/common/content_switches.h"
 #endif
 
@@ -884,7 +884,7 @@ PrintBackendServiceManager::GetServiceFr
         host.BindNewPipeAndPassReceiver(),
         content::ServiceProcessHost::Options()
             .WithDisplayName(IDS_UTILITY_PROCESS_PRINT_BACKEND_SERVICE_NAME)
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
             .WithExtraCommandLineSwitches({switches::kMessageLoopTypeUi})
 #endif
             .Pass());
@@ -1061,7 +1061,7 @@ PrintBackendServiceManager::DetermineIdl
       return kNoClientsRegisteredResetOnIdleTimeout;
 
     case ClientType::kQueryWithUi:
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
       // No need to update if there were other query with UI clients.
       if (HasQueryWithUiClientForRemoteId(remote_id)) {
         return std::nullopt;
