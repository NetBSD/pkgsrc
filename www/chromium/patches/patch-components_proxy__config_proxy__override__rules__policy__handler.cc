$NetBSD: patch-components_proxy__config_proxy__override__rules__policy__handler.cc,v 1.5 2026/05/10 15:29:56 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- components/proxy_config/proxy_override_rules_policy_handler.cc.orig	2026-04-28 23:05:57.000000000 +0200
+++ components/proxy_config/proxy_override_rules_policy_handler.cc
@@ -28,7 +28,7 @@ policy::PolicyErrorPath CreateNewPath(
   return path;
 }
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
 bool UnaffiliatedPolicyAllowed(const policy::PolicyMap& policies) {
   const base::Value* enable_for_all_users_value =
       policies.GetValue(policy::key::kEnableProxyOverrideRulesForAllUsers,
@@ -49,7 +49,7 @@ ProxyOverrideRulesPolicyHandler::ProxyOv
           policy::key::kProxyOverrideRules,
           schema.GetKnownProperty(policy::key::kProxyOverrideRules),
           policy::SchemaOnErrorStrategy::SCHEMA_ALLOW_UNKNOWN)
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
       ,
       enabled_for_all_users_handler_(
           policy::key::kEnableProxyOverrideRulesForAllUsers,
@@ -66,7 +66,7 @@ ProxyOverrideRulesPolicyHandler::~ProxyO
 bool ProxyOverrideRulesPolicyHandler::CheckPolicySettings(
     const policy::PolicyMap& policies,
     policy::PolicyErrorMap* errors) {
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
   // This code should run to set errors for
   // `kEnableProxyOverrideRulesForAllUsers`.
   enabled_for_all_users_handler_.CheckPolicySettings(policies, errors);
@@ -74,7 +74,7 @@ bool ProxyOverrideRulesPolicyHandler::Ch
 
   policy::SchemaValidatingPolicyHandler::CheckPolicySettings(policies, errors);
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
   const policy::PolicyMap::Entry* proxy_override_rules_policy =
       policies.Get(policy_name());
   if (proxy_override_rules_policy &&
@@ -109,7 +109,7 @@ bool ProxyOverrideRulesPolicyHandler::Ch
 void ProxyOverrideRulesPolicyHandler::ApplyPolicySettings(
     const policy::PolicyMap& policies,
     PrefValueMap* prefs) {
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
   // ALWAYS update affiliation, even if kProxyOverrideRules is not set.
   // This ensures the state is captured in the Managed pref store and
   // kept in sync with the latest policy bundle's affiliation status.
@@ -136,7 +136,7 @@ void ProxyOverrideRulesPolicyHandler::Ap
   prefs->SetValue(proxy_config::prefs::kProxyOverrideRules,
                   policy_value->Clone());
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
   prefs->SetInteger(proxy_config::prefs::kProxyOverrideRulesScope,
                     policy->scope);
 #endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
