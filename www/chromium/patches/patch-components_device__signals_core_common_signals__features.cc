$NetBSD: patch-components_device__signals_core_common_signals__features.cc,v 1.23 2026/07/08 13:42:20 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- components/device_signals/core/common/signals_features.cc.orig	2026-07-06 22:58:46.000000000 +0000
+++ components/device_signals/core/common/signals_features.cc
@@ -69,7 +69,7 @@ bool IsContentBindingVersioningEnabled()
 }
 
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 // Enables the triggering of device signals consent dialog when conditions met
 // This feature also requires UnmanagedDeviceSignalsConsentFlowEnabled policy to
 // be enabled
