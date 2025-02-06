$NetBSD: patch-chrome_browser_ui_webui_certificate__manager_client__cert__sources.h,v 1.1 2025/02/06 09:57:55 wiz Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/ui/webui/certificate_manager/client_cert_sources.h.orig	2024-12-17 17:58:49.000000000 +0000
+++ chrome/browser/ui/webui/certificate_manager/client_cert_sources.h
@@ -19,7 +19,7 @@ CreatePlatformClientCertSource(
         remote_client,
     Profile* profile);
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 std::unique_ptr<CertificateManagerPageHandler::CertSource>
 CreateProvisionedClientCertSource(Profile* profile);
 #endif
