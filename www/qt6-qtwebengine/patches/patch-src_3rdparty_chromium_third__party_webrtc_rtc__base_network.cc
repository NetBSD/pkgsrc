$NetBSD: patch-src_3rdparty_chromium_third__party_webrtc_rtc__base_network.cc,v 1.1 2025/12/21 09:38:45 markd Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- src/3rdparty/chromium/third_party/webrtc/rtc_base/network.cc.orig	2024-12-17 17:58:49.000000000 +0000
+++ src/3rdparty/chromium/third_party/webrtc/rtc_base/network.cc
@@ -290,7 +290,12 @@ AdapterType GetAdapterTypeFromName(absl:
   }
 #endif
 
+#if defined(WEBRTC_BSD)
+  // Treat all other network interface names as ethernet on BSD
+  return ADAPTER_TYPE_ETHERNET;
+#else
   return ADAPTER_TYPE_UNKNOWN;
+#endif
 }
 
 NetworkManager::EnumerationPermission NetworkManager::enumeration_permission()
