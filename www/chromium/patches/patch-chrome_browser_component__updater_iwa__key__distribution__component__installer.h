$NetBSD: patch-chrome_browser_component__updater_iwa__key__distribution__component__installer.h,v 1.23 2026/08/09 06:31:07 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/component_updater/iwa_key_distribution_component_installer.h.orig	2026-08-05 20:17:42.000000000 +0000
+++ chrome/browser/component_updater/iwa_key_distribution_component_installer.h
@@ -26,7 +26,7 @@ class IwaKeyDistributionInfoProvider;
 
 namespace component_updater {
 
-#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 BASE_DECLARE_FEATURE(kIwaKeyDistributionComponent);
 #endif  // BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
 
