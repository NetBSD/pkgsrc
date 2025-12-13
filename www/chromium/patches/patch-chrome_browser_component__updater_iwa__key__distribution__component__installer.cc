$NetBSD: patch-chrome_browser_component__updater_iwa__key__distribution__component__installer.cc,v 1.11 2025/12/13 14:53:48 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/component_updater/iwa_key_distribution_component_installer.cc.orig	2025-11-19 21:40:05.000000000 +0000
+++ chrome/browser/component_updater/iwa_key_distribution_component_installer.cc
@@ -77,7 +77,7 @@ bool IsOnDemandUpdateSupported() {
 
 namespace component_updater {
 
-#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 BASE_FEATURE(kIwaKeyDistributionComponent,
 #if BUILDFLAG(IS_CHROMEOS)
              base::FEATURE_ENABLED_BY_DEFAULT
@@ -101,7 +101,7 @@ bool IwaKeyDistributionComponentInstalle
   // the main IWA feature.
 #if BUILDFLAG(IS_WIN)
   return base::FeatureList::IsEnabled(features::kIsolatedWebApps);
-#elif BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   return base::FeatureList::IsEnabled(kIwaKeyDistributionComponent);
 #else
   return false;
