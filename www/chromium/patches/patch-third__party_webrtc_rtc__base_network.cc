$NetBSD: patch-third__party_webrtc_rtc__base_network.cc,v 1.2 2025/05/16 16:08:33 wiz Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- third_party/webrtc/rtc_base/network.cc.orig	2025-05-05 19:21:24.000000000 +0000
+++ third_party/webrtc/rtc_base/network.cc
@@ -314,7 +314,12 @@ webrtc::AdapterType GetAdapterTypeFromNa
   }
 #endif
 
+#if defined(WEBRTC_BSD)
+  // Treat all other network interface names as ethernet on BSD
+  return webrtc::ADAPTER_TYPE_ETHERNET;
+#else
   return webrtc::ADAPTER_TYPE_UNKNOWN;
+#endif
 }
 
 NetworkManager::EnumerationPermission NetworkManager::enumeration_permission()
