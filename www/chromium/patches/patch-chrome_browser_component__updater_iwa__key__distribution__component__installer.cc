$NetBSD: patch-chrome_browser_component__updater_iwa__key__distribution__component__installer.cc,v 1.23 2026/08/09 06:31:07 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/component_updater/iwa_key_distribution_component_installer.cc.orig	2026-08-05 20:17:42.000000000 +0000
+++ chrome/browser/component_updater/iwa_key_distribution_component_installer.cc
@@ -72,7 +72,7 @@ bool IsComponentSupported() {
   // Key Distribution component is necessary for full IWAs support as it
   // involves the IWA allowlist necessary to install IWAs in prod...
   return base::FeatureList::IsEnabled(features::kIsolatedWebApps);
-#elif BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // ...however, on Mac/Linux, the component logic is not fully supported. A
   // separate flag enables developing and testing both: IWAs and the component
   // separately on these systems.
@@ -96,7 +96,7 @@ bool IsOnDemandUpdateSupported() {
 
 namespace component_updater {
 
-#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 BASE_FEATURE(kIwaKeyDistributionComponent, base::FEATURE_DISABLED_BY_DEFAULT);
 #endif  // BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
 
