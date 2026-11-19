$NetBSD: patch-components_proxy__config_proxy__prefs__utils.cc,v 1.19 2026/11/19 19:45:59 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- components/proxy_config/proxy_prefs_utils.cc.orig	2026-11-11 21:01:38.000000000 +0000
+++ components/proxy_config/proxy_prefs_utils.cc
@@ -65,7 +65,7 @@ bool ProxyOverrideRulesAllowed(const Pre
                                policy::PolicyService* policy_service) {
   CHECK(pref_service);
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || \
-    BUILDFLAG(IS_ANDROID)
+    BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD)
   if (pref_service->GetInteger(prefs::kEnableProxyOverrideRulesForAllUsers) ==
       1) {
     return true;
