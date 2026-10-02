$NetBSD: patch-components_autofill_core_browser_payments_payments__requests_payments__request.cc,v 1.2 2026/10/02 11:43:27 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- components/autofill/core/browser/payments/payments_requests/payments_request.cc.orig	2026-09-22 00:09:16.000000000 +0000
+++ components/autofill/core/browser/payments/payments_requests/payments_request.cc
@@ -254,7 +254,7 @@ PaymentsRequest::ClientType PaymentsRequ
   return ClientType::kWindows;
 #elif BUILDFLAG(IS_MAC)
   return ClientType::kMac;
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   return ClientType::kLinux;
 #elif BUILDFLAG(IS_CHROMEOS)
   return ClientType::kChromeOs;
