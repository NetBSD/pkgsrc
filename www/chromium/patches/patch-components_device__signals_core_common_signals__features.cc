$NetBSD: patch-components_device__signals_core_common_signals__features.cc,v 1.4 2025/07/25 16:17:14 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- components/device_signals/core/common/signals_features.cc.orig	2025-07-21 19:32:31.000000000 +0000
+++ components/device_signals/core/common/signals_features.cc
@@ -43,7 +43,7 @@ bool IsBrowserSignalsReportingEnabled() 
 }
 
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 // Enables the triggering of device signals consent dialog when conditions met
 // This feature also requires UnmanagedDeviceSignalsConsentFlowEnabled policy to
 // be enabled
