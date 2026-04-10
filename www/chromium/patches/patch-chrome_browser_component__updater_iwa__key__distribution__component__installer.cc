$NetBSD: patch-chrome_browser_component__updater_iwa__key__distribution__component__installer.cc,v 1.16 2026/04/10 17:31:48 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/component_updater/iwa_key_distribution_component_installer.cc.orig	2026-04-06 16:25:54.000000000 +0000
+++ chrome/browser/component_updater/iwa_key_distribution_component_installer.cc
@@ -73,7 +73,7 @@ bool IsComponentSupported() {
   // the main IWA feature.
 #if BUILDFLAG(IS_WIN)
   return base::FeatureList::IsEnabled(features::kIsolatedWebApps);
-#elif BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   return base::FeatureList::IsEnabled(
       component_updater::kIwaKeyDistributionComponent);
 #else
@@ -94,7 +94,7 @@ bool IsOnDemandUpdateSupported() {
 
 namespace component_updater {
 
-#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 BASE_FEATURE(kIwaKeyDistributionComponent,
 #if BUILDFLAG(IS_CHROMEOS)
              base::FEATURE_ENABLED_BY_DEFAULT
