$NetBSD: patch-chrome_browser_apps_app__service_publishers_extension__apps.cc,v 1.1 2025/02/06 09:57:45 wiz Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/apps/app_service/publishers/extension_apps.cc.orig	2024-12-17 17:58:49.000000000 +0000
+++ chrome/browser/apps/app_service/publishers/extension_apps.cc
@@ -23,7 +23,7 @@ ExtensionApps::ExtensionApps(AppServiceP
 ExtensionApps::~ExtensionApps() = default;
 
 bool ExtensionApps::Accepts(const extensions::Extension* extension) {
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (extensions::IsExtensionUnsupportedDeprecatedApp(profile(),
                                                       extension->id())) {
     return false;
