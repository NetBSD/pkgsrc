$NetBSD: patch-chrome_browser_webauthn_chrome__authenticator__request__delegate.cc,v 1.5 2025/08/13 07:44:21 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/webauthn/chrome_authenticator_request_delegate.cc.orig	2025-07-29 22:51:44.000000000 +0000
+++ chrome/browser/webauthn/chrome_authenticator_request_delegate.cc
@@ -551,7 +551,7 @@ void ChromeAuthenticatorRequestDelegate:
     g_observer->ConfiguringCable(request_type);
   }
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // No caBLEv1 on Linux. It tends to crash bluez.
   if (base::Contains(pairings_from_extension,
                      device::CableDiscoveryData::Version::V1,
