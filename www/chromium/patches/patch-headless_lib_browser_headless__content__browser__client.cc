$NetBSD: patch-headless_lib_browser_headless__content__browser__client.cc,v 1.16 2026/03/14 12:40:35 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- headless/lib/browser/headless_content_browser_client.cc.orig	2026-03-11 22:12:25.000000000 +0000
+++ headless/lib/browser/headless_content_browser_client.cc
@@ -59,7 +59,7 @@
 #include "content/public/common/content_descriptors.h"
 #endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
 
-#if (BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX)) && defined(HEADLESS_USE_PREFS)
+#if (BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)) && defined(HEADLESS_USE_PREFS)
 #include "components/os_crypt/sync/os_crypt.h"  // nogncheck
 #include "content/public/browser/network_service_util.h"
 #endif
@@ -557,7 +557,7 @@ void HeadlessContentBrowserClient::Handl
 
 void HeadlessContentBrowserClient::SetEncryptionKey(
     ::network::mojom::NetworkService* network_service) {
-#if (BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX)) && defined(HEADLESS_USE_PREFS)
+#if (BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)) && defined(HEADLESS_USE_PREFS)
   // The OSCrypt keys are process bound, so if network service is out of
   // process, send it the required key if it is available.
   if (content::IsOutOfProcessNetworkService()
