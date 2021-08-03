$NetBSD: patch-src_3rdparty_chromium_components_security__interstitials_content_captive__portal__blocking__page.cc,v 1.1 2021/08/03 21:04:35 markd Exp $

--- src/3rdparty/chromium/components/security_interstitials/content/captive_portal_blocking_page.cc.orig	2020-07-08 21:40:41.000000000 +0000
+++ src/3rdparty/chromium/components/security_interstitials/content/captive_portal_blocking_page.cc
@@ -106,7 +106,7 @@ std::string CaptivePortalBlockingPage::G
   wifi_service->GetConnectedNetworkSSID(&ssid, &error);
   if (!error.empty())
     return std::string();
-#elif defined(OS_LINUX)
+#elif defined(OS_LINUX) || defined(OS_BSD)
   ssid = net::GetWifiSSID();
 #elif defined(OS_ANDROID)
   ssid = net::android::GetWifiSSID();
@@ -236,4 +236,4 @@ void CaptivePortalBlockingPage::CommandR
       NOTREACHED() << "Command " << cmd
                    << " isn't handled by the captive portal interstitial.";
   }
-}
\ No newline at end of file
+}
