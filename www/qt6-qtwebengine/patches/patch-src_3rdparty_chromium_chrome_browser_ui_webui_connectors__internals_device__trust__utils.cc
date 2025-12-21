$NetBSD: patch-src_3rdparty_chromium_chrome_browser_ui_webui_connectors__internals_device__trust__utils.cc,v 1.1 2025/12/21 09:38:19 markd Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- src/3rdparty/chromium/chrome/browser/ui/webui/connectors_internals/device_trust_utils.cc.orig	2025-05-29 01:27:28.000000000 +0000
+++ src/3rdparty/chromium/chrome/browser/ui/webui/connectors_internals/device_trust_utils.cc
@@ -7,7 +7,7 @@
 #include "build/build_config.h"
 #include "components/enterprise/buildflags/buildflags.h"
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
 #include "base/base64url.h"
 #include "chrome/browser/browser_process.h"
 #include "chrome/browser/policy/chrome_browser_policy_connector.h"
@@ -38,7 +38,7 @@ namespace enterprise_connectors::utils {
 
 namespace {
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
 
 connectors_internals::mojom::KeyTrustLevel ParseTrustLevel(
     BPKUR::KeyTrustLevel trust_level) {
@@ -173,7 +173,7 @@ connectors_internals::mojom::Certificate
 }  // namespace
 
 connectors_internals::mojom::KeyInfoPtr GetKeyInfo() {
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
   auto* key_manager = g_browser_process->browser_policy_connector()
                           ->chrome_browser_cloud_management_controller()
                           ->GetDeviceTrustKeyManager();
