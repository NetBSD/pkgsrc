$NetBSD: patch-components_proxy__config_proxy__override__rules__policy__handler.cc,v 1.19 2026/11/19 19:45:59 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- components/proxy_config/proxy_override_rules_policy_handler.cc.orig	2026-11-11 21:01:38.000000000 +0000
+++ components/proxy_config/proxy_override_rules_policy_handler.cc
@@ -45,7 +45,7 @@ bool ProxyOverrideRulesPolicyHandler::Ch
     const policy::PolicyMap& policies,
     policy::PolicyErrorMap* errors) {
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || \
-    BUILDFLAG(IS_ANDROID)
+    BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD)
   if (!enterprise_net::CheckUserAffiliatedProxyPolicy(policies, policy_name(),
                                                       errors)) {
     return false;
@@ -97,7 +97,7 @@ void ProxyOverrideRulesPolicyHandler::Ap
                   policy_value->Clone());
 
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || \
-    BUILDFLAG(IS_ANDROID)
+    BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD)
   prefs->SetInteger(proxy_config::prefs::kProxyOverrideRulesScope,
                     policy->scope);
 #endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) ||
