$NetBSD: patch-components_proxy__config_proxy__override__rules__policy__handler.h,v 1.5 2026/05/10 15:29:56 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- components/proxy_config/proxy_override_rules_policy_handler.h.orig	2026-04-28 23:05:57.000000000 +0200
+++ components/proxy_config/proxy_override_rules_policy_handler.h
@@ -53,7 +53,7 @@ class PROXY_CONFIG_EXPORT ProxyOverrideR
                 policy::PolicyErrorPath error_path,
                 policy::PolicyErrorMap* errors);
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
   policy::IntRangePolicyHandler enabled_for_all_users_handler_;
 #endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
 };
