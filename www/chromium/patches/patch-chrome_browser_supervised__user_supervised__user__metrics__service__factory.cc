$NetBSD: patch-chrome_browser_supervised__user_supervised__user__metrics__service__factory.cc,v 1.18 2026/04/21 15:21:10 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/supervised_user/supervised_user_metrics_service_factory.cc.orig	2026-04-14 23:31:37.000000000 +0200
+++ chrome/browser/supervised_user/supervised_user_metrics_service_factory.cc
@@ -19,7 +19,7 @@
 #include "components/supervised_user/core/browser/supervised_user_service.h"
 #include "content/public/browser/browser_context.h"
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/supervised_user/linux_mac_windows/supervised_user_extensions_metrics_delegate_impl.h"
 #endif
 
@@ -73,7 +73,7 @@ SupervisedUserMetricsServiceFactory::Bui
   std::unique_ptr<supervised_user::SupervisedUserMetricsService ::
                       SupervisedUserMetricsServiceExtensionDelegate>
       extensions_metrics_delegate = nullptr;
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   extensions_metrics_delegate =
       std::make_unique<SupervisedUserExtensionsMetricsDelegateImpl>(
           extensions::ExtensionRegistry::Get(profile), profile);
