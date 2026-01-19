$NetBSD: patch-components_proxy__config_pref__proxy__config__tracker__impl.cc,v 1.1 2026/01/19 16:14:14 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- components/proxy_config/pref_proxy_config_tracker_impl.cc.orig	2026-01-07 00:50:30.000000000 +0000
+++ components/proxy_config/pref_proxy_config_tracker_impl.cc
@@ -552,7 +552,7 @@ void PrefProxyConfigTrackerImpl::Registe
   registry->RegisterDictionaryPref(proxy_config::prefs::kProxy,
                                    ProxyConfigDictionary::CreateSystem());
   registry->RegisterListPref(proxy_config::prefs::kProxyOverrideRules);
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
   registry->RegisterIntegerPref(
       proxy_config::prefs::kEnableProxyOverrideRulesForAllUsers, 0);
 #endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
