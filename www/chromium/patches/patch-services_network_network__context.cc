$NetBSD: patch-services_network_network__context.cc,v 1.14 2026/01/19 16:14:19 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- services/network/network_context.cc.orig	2026-01-07 00:50:30.000000000 +0000
+++ services/network/network_context.cc
@@ -633,7 +633,7 @@ NetworkContext::NetworkContextHttpAuthPr
 NetworkContext::NetworkContextHttpAuthPreferences::
     ~NetworkContextHttpAuthPreferences() = default;
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 bool NetworkContext::NetworkContextHttpAuthPreferences::AllowGssapiLibraryLoad()
     const {
   if (network_service_) {
@@ -2625,7 +2625,7 @@ void NetworkContext::OnHttpAuthDynamicPa
       http_auth_dynamic_network_service_params->android_negotiate_account_type);
 #endif  // BUILDFLAG(IS_ANDROID)
 
-#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   http_auth_merged_preferences_.set_allow_gssapi_library_load(
       http_auth_dynamic_network_service_params->allow_gssapi_library_load);
 #endif  // BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX)
