$NetBSD: patch-components_device__signals_core_common_signals__features.cc,v 1.10 2025/11/20 08:36:12 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- components/device_signals/core/common/signals_features.cc.orig	2025-11-14 20:31:45.000000000 +0000
+++ components/device_signals/core/common/signals_features.cc
@@ -51,7 +51,7 @@ bool IsDetectedAgentSignalCollectionEnab
 }
 
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 // Enables the triggering of device signals consent dialog when conditions met
 // This feature also requires UnmanagedDeviceSignalsConsentFlowEnabled policy to
 // be enabled
