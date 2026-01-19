$NetBSD: patch-chrome_browser_enterprise_signals_signals__aggregator__factory.cc,v 1.10 2026/01/19 16:14:08 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/enterprise/signals/signals_aggregator_factory.cc.orig	2026-01-07 00:50:30.000000000 +0000
+++ chrome/browser/enterprise/signals/signals_aggregator_factory.cc
@@ -49,7 +49,7 @@
 #include "components/device_signals/core/browser/settings_client.h"
 #endif  // BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC)
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "components/device_signals/core/browser/agent_signals_collector.h"
 #include "components/device_signals/core/browser/crowdstrike_client.h"
 #endif  // BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
@@ -113,7 +113,7 @@ SignalsAggregatorFactory::BuildServiceIn
           service_host));
 #endif  // !BUILDFLAG(IS_ANDROID)
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   collectors.push_back(std::make_unique<device_signals::AgentSignalsCollector>(
       device_signals::CrowdStrikeClient::Create()));
 #endif  // BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
