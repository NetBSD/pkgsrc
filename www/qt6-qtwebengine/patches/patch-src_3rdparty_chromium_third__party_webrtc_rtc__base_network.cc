$NetBSD: patch-src_3rdparty_chromium_third__party_webrtc_rtc__base_network.cc,v 1.2 2026/04/30 06:39:44 adam Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- src/3rdparty/chromium/third_party/webrtc/rtc_base/network.cc.orig	2026-03-16 11:40:07.000000000 +0000
+++ src/3rdparty/chromium/third_party/webrtc/rtc_base/network.cc
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
