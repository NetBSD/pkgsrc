$NetBSD: patch-components_enterprise_net_core_proxy__policy__utils.h,v 1.1 2026/11/19 19:45:58 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- components/enterprise/net/core/proxy_policy_utils.h.orig	2026-11-11 21:01:38.000000000 +0000
+++ components/enterprise/net/core/proxy_policy_utils.h
@@ -17,7 +17,7 @@ class PolicyMap;
 namespace enterprise_net {
 
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || \
-    BUILDFLAG(IS_ANDROID)
+    BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD)
 // Returns true if the machine-scoped EnableProxyOverrideRulesForAllUsers policy
 // is enabled (set to 1).
 bool IsUnaffiliatedUserProxyPolicyAllowed(const policy::PolicyMap& policies);
