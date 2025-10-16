$NetBSD: patch-third__party_webrtc_rtc__base_network.cc,v 1.8 2025/10/16 19:43:36 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- third_party/webrtc/rtc_base/network.cc.orig	2025-10-13 21:41:26.000000000 +0000
+++ third_party/webrtc/rtc_base/network.cc
@@ -303,7 +303,12 @@ AdapterType GetAdapterTypeFromName(absl:
   }
 #endif
 
+#if defined(WEBRTC_BSD)
+  // Treat all other network interface names as ethernet on BSD
+  return webrtc::ADAPTER_TYPE_ETHERNET;
+#else
   return ADAPTER_TYPE_UNKNOWN;
+#endif
 }
 
 NetworkManager::EnumerationPermission NetworkManager::enumeration_permission()
