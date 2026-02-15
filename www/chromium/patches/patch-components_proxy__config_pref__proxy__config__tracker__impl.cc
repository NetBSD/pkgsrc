$NetBSD: patch-components_proxy__config_pref__proxy__config__tracker__impl.cc,v 1.2 2026/02/15 09:04:03 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- components/proxy_config/pref_proxy_config_tracker_impl.cc.orig	2026-02-03 22:07:10.000000000 +0000
+++ components/proxy_config/pref_proxy_config_tracker_impl.cc
@@ -527,7 +527,7 @@ void PrefProxyConfigTrackerImpl::Registe
   registry->RegisterDictionaryPref(proxy_config::prefs::kProxy,
                                    ProxyConfigDictionary::CreateSystem());
   registry->RegisterListPref(proxy_config::prefs::kProxyOverrideRules);
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
   registry->RegisterIntegerPref(
       proxy_config::prefs::kEnableProxyOverrideRulesForAllUsers, 0);
   registry->RegisterIntegerPref(proxy_config::prefs::kProxyOverrideRulesScope,
@@ -544,7 +544,7 @@ void PrefProxyConfigTrackerImpl::Registe
                                    ProxyConfigDictionary::CreateSystem());
   registry->RegisterBooleanPref(proxy_config::prefs::kUseSharedProxies, false);
   registry->RegisterListPref(proxy_config::prefs::kProxyOverrideRules);
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
   registry->RegisterIntegerPref(
       proxy_config::prefs::kEnableProxyOverrideRulesForAllUsers, 0);
   registry->RegisterIntegerPref(proxy_config::prefs::kProxyOverrideRulesScope,
