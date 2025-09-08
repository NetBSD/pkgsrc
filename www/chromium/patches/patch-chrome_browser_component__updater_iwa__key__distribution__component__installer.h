$NetBSD: patch-chrome_browser_component__updater_iwa__key__distribution__component__installer.h,v 1.5 2025/09/08 13:24:17 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/component_updater/iwa_key_distribution_component_installer.h.orig	2025-08-29 18:50:09.000000000 +0000
+++ chrome/browser/component_updater/iwa_key_distribution_component_installer.h
@@ -27,7 +27,7 @@ class IwaKeyDistributionInfoProvider;
 
 namespace component_updater {
 
-#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 BASE_DECLARE_FEATURE(kIwaKeyDistributionComponent);
 #endif  // BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
 
