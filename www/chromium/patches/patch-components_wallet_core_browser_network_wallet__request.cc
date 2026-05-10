$NetBSD: patch-components_wallet_core_browser_network_wallet__request.cc,v 1.1 2026/05/10 15:29:57 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- components/wallet/core/browser/network/wallet_request.cc.orig	2026-04-28 23:05:57.000000000 +0200
+++ components/wallet/core/browser/network/wallet_request.cc
@@ -19,7 +19,7 @@ ClientInfo::ChromeClientInfo::Platform G
   return ClientInfo::ChromeClientInfo::PLATFORM_MACOS;
 #elif BUILDFLAG(IS_CHROMEOS)
   return ClientInfo::ChromeClientInfo::PLATFORM_CHROMEOS;
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   return ClientInfo::ChromeClientInfo::PLATFORM_LINUX;
 #elif BUILDFLAG(IS_ANDROID)
   return ClientInfo::ChromeClientInfo::PLATFORM_ANDROID;
