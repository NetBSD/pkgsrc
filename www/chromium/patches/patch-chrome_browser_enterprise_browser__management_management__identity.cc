$NetBSD: patch-chrome_browser_enterprise_browser__management_management__identity.cc,v 1.1 2026/04/10 17:31:48 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/enterprise/browser_management/management_identity.cc.orig	2026-04-06 16:25:54.000000000 +0000
+++ chrome/browser/enterprise/browser_management/management_identity.cc
@@ -86,7 +86,7 @@ std::optional<std::string> GetDeviceMana
       g_browser_process->platform_part()->browser_policy_connector_ash();
   return connector->GetEnterpriseDomainManager();
 #else
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (base::FeatureList::IsEnabled(
           features::kEnterpriseManagementDisclaimerUsesCustomLabel)) {
     std::string custom_management_label =
@@ -116,7 +116,7 @@ std::optional<std::string> GetAccountMan
     return std::nullopt;
   }
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (base::FeatureList::IsEnabled(
           features::kEnterpriseManagementDisclaimerUsesCustomLabel)) {
     std::string custom_management_label =
