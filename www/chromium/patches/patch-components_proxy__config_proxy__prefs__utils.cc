$NetBSD: patch-components_proxy__config_proxy__prefs__utils.cc,v 1.8 2026/07/06 13:06:49 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- components/proxy_config/proxy_prefs_utils.cc.orig	2026-06-23 23:37:18.000000000 +0000
+++ components/proxy_config/proxy_prefs_utils.cc
@@ -60,7 +60,7 @@ net::ProxyChain ProxyOverrideRuleProxyFr
 
 bool ProxyOverrideRulesAllowed(const PrefService* pref_service) {
   CHECK(pref_service);
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
   if (pref_service->GetBoolean(prefs::kProxyOverrideRulesAffiliation) ||
       pref_service->GetInteger(prefs::kEnableProxyOverrideRulesForAllUsers) ==
           1) {
