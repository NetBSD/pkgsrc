$NetBSD: patch-components_device__signals_core_browser_desktop_desktop__os__signals__collector.cc,v 1.15 2026/05/10 15:29:54 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- components/device_signals/core/browser/desktop/desktop_os_signals_collector.cc.orig	2026-04-28 23:05:57.000000000 +0200
+++ components/device_signals/core/browser/desktop/desktop_os_signals_collector.cc
@@ -44,7 +44,7 @@ std::unique_ptr<OsSignalsResponse> AddAs
     os_signals_response->disk_encryption = device_signals::GetDiskEncrypted();
     os_signals_response->os_firewall = device_signals::GetOSFirewall();
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     os_signals_response->distribution_version =
         device_signals::GetDistributionVersion();
 #endif  // BUILDFLAG(IS_LINUX)
