$NetBSD: patch-components_device__signals_core_browser_signals__aggregator__impl.h,v 1.3 2025/07/07 09:23:30 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- components/device_signals/core/browser/signals_aggregator_impl.h.orig	2025-06-30 06:54:11.000000000 +0000
+++ components/device_signals/core/browser/signals_aggregator_impl.h
@@ -30,7 +30,7 @@ class SignalsAggregatorImpl : public Sig
   ~SignalsAggregatorImpl() override;
 
   // SignalsAggregator:
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   void GetSignalsForUser(const UserContext& user_context,
                          const SignalsAggregationRequest& request,
                          GetSignalsCallback callback) override;
