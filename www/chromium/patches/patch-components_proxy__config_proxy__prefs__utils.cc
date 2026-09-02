$NetBSD: patch-components_proxy__config_proxy__prefs__utils.cc,v 1.11 2026/09/02 13:13:29 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- components/proxy_config/proxy_prefs_utils.cc.orig	2026-08-31 22:47:51.000000000 +0000
+++ components/proxy_config/proxy_prefs_utils.cc
@@ -64,7 +64,7 @@ net::ProxyChain ProxyOverrideRuleProxyFr
 bool ProxyOverrideRulesAllowed(const PrefService* pref_service,
                                policy::PolicyService* policy_service) {
   CHECK(pref_service);
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
   if (pref_service->GetInteger(prefs::kEnableProxyOverrideRulesForAllUsers) ==
       1) {
     return true;
