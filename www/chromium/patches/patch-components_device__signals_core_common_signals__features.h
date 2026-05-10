$NetBSD: patch-components_device__signals_core_common_signals__features.h,v 1.19 2026/05/10 15:29:55 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- components/device_signals/core/common/signals_features.h.orig	2026-04-28 23:05:57.000000000 +0200
+++ components/device_signals/core/common/signals_features.h
@@ -36,7 +36,7 @@ bool IsDetectedAgentSignalCollectionEnab
 bool IsPolicyDataCollectionEnabled();
 
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 BASE_DECLARE_FEATURE(kDeviceSignalsConsentDialog);
 
 // Returns true if device signals consent dialog has been enabled for
