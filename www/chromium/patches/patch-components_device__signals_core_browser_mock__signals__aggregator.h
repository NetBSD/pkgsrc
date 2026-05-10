$NetBSD: patch-components_device__signals_core_browser_mock__signals__aggregator.h,v 1.19 2026/05/10 15:29:54 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- components/device_signals/core/browser/mock_signals_aggregator.h.orig	2026-04-28 23:05:57.000000000 +0200
+++ components/device_signals/core/browser/mock_signals_aggregator.h
@@ -17,7 +17,7 @@ class MockSignalsAggregator : public Sig
   MockSignalsAggregator();
   ~MockSignalsAggregator() override;
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   MOCK_METHOD(void,
               GetSignalsForUser,
               (const UserContext&,
