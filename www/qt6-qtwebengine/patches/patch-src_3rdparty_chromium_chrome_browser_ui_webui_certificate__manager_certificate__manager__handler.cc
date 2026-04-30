$NetBSD: patch-src_3rdparty_chromium_chrome_browser_ui_webui_certificate__manager_certificate__manager__handler.cc,v 1.2 2026/04/30 06:39:36 adam Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- src/3rdparty/chromium/chrome/browser/ui/webui/certificate_manager/certificate_manager_handler.cc.orig	2026-03-16 11:40:07.000000000 +0000
+++ src/3rdparty/chromium/chrome/browser/ui/webui/certificate_manager/certificate_manager_handler.cc
@@ -219,7 +219,7 @@ CertificateManagerPageHandler::GetCertSo
                 CERTIFICATE_TRUST_TYPE_DISTRUSTED,
             profile_, &remote_client_);
         break;
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
       case certificate_manager::mojom::CertificateSource::
           kProvisionedClientCert:
         source_ptr = CreateProvisionedClientCertSource(profile_);
