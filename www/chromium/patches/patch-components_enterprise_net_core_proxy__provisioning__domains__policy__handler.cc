$NetBSD: patch-components_enterprise_net_core_proxy__provisioning__domains__policy__handler.cc,v 1.1 2026/11/19 19:45:58 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- components/enterprise/net/core/proxy_provisioning_domains_policy_handler.cc.orig	2026-11-11 21:01:38.000000000 +0000
+++ components/enterprise/net/core/proxy_provisioning_domains_policy_handler.cc
@@ -32,7 +32,7 @@ bool ProxyProvisioningDomainsPolicyHandl
     const policy::PolicyMap& policies,
     policy::PolicyErrorMap* errors) {
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || \
-    BUILDFLAG(IS_ANDROID)
+    BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD)
   if (!CheckUserAffiliatedProxyPolicy(policies, policy_name(), errors)) {
     return false;
   }
