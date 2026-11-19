$NetBSD: patch-components_proxy__config_proxy__config__pref__names.h,v 1.20 2026/11/19 19:45:59 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- components/proxy_config/proxy_config_pref_names.h.orig	2026-11-11 21:01:38.000000000 +0000
+++ components/proxy_config/proxy_config_pref_names.h
@@ -20,7 +20,7 @@ inline constexpr char kUseSharedProxies[
 inline constexpr char kProxyOverrideRules[] = "proxy_override_rules";
 
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || \
-    BUILDFLAG(IS_ANDROID)
+    BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD)
 // Preference to store the scope (user vs machine) corresponding to the value
 // set in `kProxyOverrideRules`. It is used to handle the policy differently
 // when its source is a cloud user depending on its affiliation status and the
