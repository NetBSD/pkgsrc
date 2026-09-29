$NetBSD: patch-components_device__signals_core_common_platform__utils.cc,v 1.1 2026/09/29 07:42:54 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- components/device_signals/core/common/platform_utils.cc.orig	2026-09-22 00:09:16.000000000 +0000
+++ components/device_signals/core/common/platform_utils.cc
@@ -78,7 +78,7 @@ std::vector<std::string> GetMacAddresses
     mac_addresses = test_addresses.value();
   } else {
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
     mac_addresses = internal::GetMacAddressesImpl();
 #endif
   }
