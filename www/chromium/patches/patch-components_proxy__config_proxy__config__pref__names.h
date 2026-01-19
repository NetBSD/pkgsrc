$NetBSD: patch-components_proxy__config_proxy__config__pref__names.h,v 1.1 2026/01/19 16:14:14 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- components/proxy_config/proxy_config_pref_names.h.orig	2026-01-07 00:50:30.000000000 +0000
+++ components/proxy_config/proxy_config_pref_names.h
@@ -28,7 +28,7 @@ inline constexpr char kProxyOverrideRule
 inline constexpr char kProxyOverrideRulesScope[] = "proxy_override_rules_scope";
 #endif  // !BUILDFLAG(IS_CHROMEOS)
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
 // Preference to store the value of the "EnableProxyOverrideRulesForAllUsers"
 // policy.
 inline constexpr char kEnableProxyOverrideRulesForAllUsers[] =
