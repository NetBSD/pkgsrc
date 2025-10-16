$NetBSD: patch-components_device__signals_core_common_signals__features.h,v 1.8 2025/10/16 19:43:26 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- components/device_signals/core/common/signals_features.h.orig	2025-10-13 21:41:26.000000000 +0000
+++ components/device_signals/core/common/signals_features.h
@@ -33,7 +33,7 @@ bool IsBrowserSignalsReportingEnabled();
 bool IsDetectedAgentSignalCollectionEnabled();
 
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 BASE_DECLARE_FEATURE(kDeviceSignalsConsentDialog);
 
 // Returns true if device signals consent dialog has been enabled for
