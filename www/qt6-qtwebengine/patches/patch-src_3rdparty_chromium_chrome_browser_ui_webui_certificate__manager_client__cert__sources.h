$NetBSD: patch-src_3rdparty_chromium_chrome_browser_ui_webui_certificate__manager_client__cert__sources.h,v 1.1 2025/12/21 09:38:19 markd Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- src/3rdparty/chromium/chrome/browser/ui/webui/certificate_manager/client_cert_sources.h.orig	2025-09-25 11:10:42.000000000 +0000
+++ src/3rdparty/chromium/chrome/browser/ui/webui/certificate_manager/client_cert_sources.h
@@ -18,7 +18,7 @@ CreatePlatformClientCertSource(
         remote_client,
     Profile* profile);
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 std::unique_ptr<CertificateManagerPageHandler::CertSource>
 CreateProvisionedClientCertSource(Profile* profile);
 #endif
