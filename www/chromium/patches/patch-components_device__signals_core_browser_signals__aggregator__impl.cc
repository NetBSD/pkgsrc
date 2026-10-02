$NetBSD: patch-components_device__signals_core_browser_signals__aggregator__impl.cc,v 1.28 2026/10/02 11:43:27 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- components/device_signals/core/browser/signals_aggregator_impl.cc.orig	2026-09-22 00:09:16.000000000 +0000
+++ components/device_signals/core/browser/signals_aggregator_impl.cc
@@ -64,7 +64,7 @@ SignalsAggregatorImpl::SignalsAggregator
 
 SignalsAggregatorImpl::~SignalsAggregatorImpl() = default;
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 void SignalsAggregatorImpl::GetSignalsForUser(
     const UserContext& user_context,
     const SignalsAggregationRequest& request,
