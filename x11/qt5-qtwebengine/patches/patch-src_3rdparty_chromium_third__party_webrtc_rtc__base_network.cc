$NetBSD: patch-src_3rdparty_chromium_third__party_webrtc_rtc__base_network.cc,v 1.1 2021/08/03 21:04:36 markd Exp $

--- src/3rdparty/chromium/third_party/webrtc/rtc_base/network.cc.orig	2020-07-15 19:01:42.000000000 +0000
+++ src/3rdparty/chromium/third_party/webrtc/rtc_base/network.cc
@@ -244,7 +244,12 @@ AdapterType GetAdapterTypeFromName(const
   }
 #endif
 
+#if defined(WEBRTC_BSD)
+  // Treat all other network interface names as ethernet on BSD
+  return ADAPTER_TYPE_ETHERNET;
+#else
   return ADAPTER_TYPE_UNKNOWN;
+#endif
 }
 
 NetworkManager::NetworkManager() {}
