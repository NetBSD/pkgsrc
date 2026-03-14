$NetBSD: patch-chrome_browser_ui_managed__ui.cc,v 1.16 2026/03/14 12:40:27 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/ui/managed_ui.cc.orig	2026-03-11 22:12:25.000000000 +0000
+++ chrome/browser/ui/managed_ui.cc
@@ -433,7 +433,7 @@ std::optional<std::string> GetDeviceMana
       g_browser_process->platform_part()->browser_policy_connector_ash();
   return connector->GetEnterpriseDomainManager();
 #else
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (base::FeatureList::IsEnabled(
           features::kEnterpriseManagementDisclaimerUsesCustomLabel)) {
     std::string custom_management_label =
@@ -463,7 +463,7 @@ std::optional<std::string> GetAccountMan
     return std::nullopt;
   }
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (base::FeatureList::IsEnabled(
           features::kEnterpriseManagementDisclaimerUsesCustomLabel)) {
     std::string custom_management_label =
