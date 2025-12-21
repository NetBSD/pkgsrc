$NetBSD: patch-src_3rdparty_chromium_components_device__signals_core_common_signals__features.h,v 1.1 2025/12/21 09:38:21 markd Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- src/3rdparty/chromium/components/device_signals/core/common/signals_features.h.orig	2025-11-14 07:55:10.000000000 +0000
+++ src/3rdparty/chromium/components/device_signals/core/common/signals_features.h
@@ -14,7 +14,7 @@ namespace enterprise_signals::features {
 BASE_DECLARE_FEATURE(kAllowClientCertificateReportingForUsers);
 
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 BASE_DECLARE_FEATURE(kDeviceSignalsConsentDialog);
 
 // Returns true if device signals consent dialog has been enabled for
