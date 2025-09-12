$NetBSD: patch-components_device__signals_core_browser_signals__aggregator__impl.cc,v 1.7 2025/09/12 16:02:26 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- components/device_signals/core/browser/signals_aggregator_impl.cc.orig	2025-09-08 23:21:33.000000000 +0000
+++ components/device_signals/core/browser/signals_aggregator_impl.cc
@@ -64,7 +64,7 @@ SignalsAggregatorImpl::SignalsAggregator
 
 SignalsAggregatorImpl::~SignalsAggregatorImpl() = default;
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 void SignalsAggregatorImpl::GetSignalsForUser(
     const UserContext& user_context,
     const SignalsAggregationRequest& request,
