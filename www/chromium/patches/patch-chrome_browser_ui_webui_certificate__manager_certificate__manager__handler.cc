$NetBSD: patch-chrome_browser_ui_webui_certificate__manager_certificate__manager__handler.cc,v 1.11 2025/12/11 09:13:33 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/ui/webui/certificate_manager/certificate_manager_handler.cc.orig	2025-11-19 21:40:05.000000000 +0000
+++ chrome/browser/ui/webui/certificate_manager/certificate_manager_handler.cc
@@ -217,7 +217,7 @@ CertificateManagerPageHandler::GetCertSo
                 CERTIFICATE_TRUST_TYPE_DISTRUSTED,
             profile_, &remote_client_);
         break;
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
       case certificate_manager::mojom::CertificateSource::
           kProvisionedClientCert:
         source_ptr = CreateProvisionedClientCertSource(profile_);
