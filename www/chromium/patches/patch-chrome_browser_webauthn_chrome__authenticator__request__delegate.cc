$NetBSD: patch-chrome_browser_webauthn_chrome__authenticator__request__delegate.cc,v 1.19 2026/05/10 15:29:53 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/webauthn/chrome_authenticator_request_delegate.cc.orig	2026-04-28 23:05:57.000000000 +0200
+++ chrome/browser/webauthn/chrome_authenticator_request_delegate.cc
@@ -542,7 +542,7 @@ void ChromeAuthenticatorRequestDelegate:
     g_observer->ConfiguringCable(request_type);
   }
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // No caBLEv1 on Linux. It tends to crash bluez.
   if (std::ranges::contains(pairings_from_extension,
                             device::CableDiscoveryData::Version::V1,
