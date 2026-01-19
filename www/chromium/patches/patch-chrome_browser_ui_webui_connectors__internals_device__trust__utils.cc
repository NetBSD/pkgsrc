$NetBSD: patch-chrome_browser_ui_webui_connectors__internals_device__trust__utils.cc,v 1.14 2026/01/19 16:14:11 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/ui/webui/connectors_internals/device_trust_utils.cc.orig	2026-01-07 00:50:30.000000000 +0000
+++ chrome/browser/ui/webui/connectors_internals/device_trust_utils.cc
@@ -8,7 +8,7 @@
 #include "components/enterprise/buildflags/buildflags.h"
 
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || \
-    BUILDFLAG(IS_ANDROID)
+    BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD)
 #include "base/base64url.h"
 #include "chrome/browser/browser_process.h"
 #include "chrome/browser/policy/chrome_browser_policy_connector.h"
@@ -42,7 +42,7 @@ namespace enterprise_connectors::utils {
 namespace {
 
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || \
-    BUILDFLAG(IS_ANDROID)
+    BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD)
 
 connectors_internals::mojom::KeyTrustLevel ParseTrustLevel(
     BPKUR::KeyTrustLevel trust_level) {
@@ -181,7 +181,7 @@ connectors_internals::mojom::Certificate
 
 connectors_internals::mojom::KeyInfoPtr GetKeyInfo() {
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || \
-    BUILDFLAG(IS_ANDROID)
+    BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD)
   auto* key_manager = g_browser_process->browser_policy_connector()
                           ->chrome_browser_cloud_management_controller()
                           ->GetDeviceTrustKeyManager();
