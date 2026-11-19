$NetBSD: patch-components_proxy__config_pref__proxy__config__tracker__impl.cc,v 1.20 2026/11/19 19:45:59 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- components/proxy_config/pref_proxy_config_tracker_impl.cc.orig	2026-11-11 21:01:38.000000000 +0000
+++ components/proxy_config/pref_proxy_config_tracker_impl.cc
@@ -588,7 +588,7 @@ void PrefProxyConfigTrackerImpl::Registe
                                    ProxyConfigDictionary::CreateSystem());
   registry->RegisterListPref(proxy_config::prefs::kProxyOverrideRules);
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || \
-    BUILDFLAG(IS_ANDROID)
+    BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD)
   registry->RegisterIntegerPref(
       proxy_config::prefs::kEnableProxyOverrideRulesForAllUsers, 0);
   registry->RegisterIntegerPref(proxy_config::prefs::kProxyOverrideRulesScope,
@@ -605,7 +605,7 @@ void PrefProxyConfigTrackerImpl::Registe
   registry->RegisterBooleanPref(proxy_config::prefs::kUseSharedProxies, false);
   registry->RegisterListPref(proxy_config::prefs::kProxyOverrideRules);
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || \
-    BUILDFLAG(IS_ANDROID)
+    BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD)
   registry->RegisterIntegerPref(
       proxy_config::prefs::kEnableProxyOverrideRulesForAllUsers, 0);
   registry->RegisterIntegerPref(proxy_config::prefs::kProxyOverrideRulesScope,
