$NetBSD: patch-components_device__signals_core_common_signals__features.h,v 1.15 2026/02/15 09:04:02 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- components/device_signals/core/common/signals_features.h.orig	2026-02-03 22:07:10.000000000 +0000
+++ components/device_signals/core/common/signals_features.h
@@ -40,7 +40,7 @@ bool IsSystemSignalCollectionImprovement
 bool IsPolicyDataCollectionEnabled();
 
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 BASE_DECLARE_FEATURE(kDeviceSignalsConsentDialog);
 
 // Returns true if device signals consent dialog has been enabled for
