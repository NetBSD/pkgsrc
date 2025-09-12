$NetBSD: patch-components_supervised__user_core_browser_supervised__user__metrics__service.cc,v 1.7 2025/09/12 16:02:27 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- components/supervised_user/core/browser/supervised_user_metrics_service.cc.orig	2025-09-08 23:21:33.000000000 +0000
+++ components/supervised_user/core/browser/supervised_user_metrics_service.cc
@@ -103,7 +103,7 @@ SupervisedUserMetricsService::Supervised
           std::move(metrics_service_accessor_delegate)) {
   DCHECK(pref_service_);
   supervised_user_service_observation_.Observe(&supervised_user_service);
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   CHECK(extensions_metrics_delegate_)
       << "Extensions metrics delegate must exist on Win/Linux/Mac";
 #endif  // BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
