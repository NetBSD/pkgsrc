$NetBSD: patch-chrome_browser_supervised__user_supervised__user__metrics__service__factory.cc,v 1.14 2026/01/19 16:14:10 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/supervised_user/supervised_user_metrics_service_factory.cc.orig	2026-01-07 00:50:30.000000000 +0000
+++ chrome/browser/supervised_user/supervised_user_metrics_service_factory.cc
@@ -15,7 +15,7 @@
 #include "content/public/browser/browser_context.h"
 #include "chrome/browser/supervised_user/metrics_service_accessor_delegate.h"
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/supervised_user/linux_mac_windows/supervised_user_extensions_metrics_delegate_impl.h"
 #endif
 
@@ -63,7 +63,7 @@ SupervisedUserMetricsServiceFactory::Bui
   std::unique_ptr<supervised_user::SupervisedUserMetricsService ::
                       SupervisedUserMetricsServiceExtensionDelegate>
       extensions_metrics_delegate = nullptr;
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   extensions_metrics_delegate =
       std::make_unique<SupervisedUserExtensionsMetricsDelegateImpl>(
           extensions::ExtensionRegistry::Get(profile), profile);
