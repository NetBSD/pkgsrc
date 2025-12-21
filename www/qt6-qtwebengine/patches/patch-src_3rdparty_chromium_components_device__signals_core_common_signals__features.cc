$NetBSD: patch-src_3rdparty_chromium_components_device__signals_core_common_signals__features.cc,v 1.1 2025/12/21 09:38:21 markd Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- src/3rdparty/chromium/components/device_signals/core/common/signals_features.cc.orig	2025-11-14 07:55:10.000000000 +0000
+++ src/3rdparty/chromium/components/device_signals/core/common/signals_features.cc
@@ -11,7 +11,7 @@ BASE_FEATURE(kAllowClientCertificateRepo
              base::FEATURE_ENABLED_BY_DEFAULT);
 
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 // Enables the triggering of device signals consent dialog when conditions met
 // This feature also requires UnmanagedDeviceSignalsConsentFlowEnabled policy to
 // be enabled
