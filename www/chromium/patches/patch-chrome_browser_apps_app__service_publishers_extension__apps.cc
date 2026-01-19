$NetBSD: patch-chrome_browser_apps_app__service_publishers_extension__apps.cc,v 1.14 2026/01/19 16:14:07 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/apps/app_service/publishers/extension_apps.cc.orig	2026-01-07 00:50:30.000000000 +0000
+++ chrome/browser/apps/app_service/publishers/extension_apps.cc
@@ -23,7 +23,7 @@ ExtensionApps::ExtensionApps(AppServiceP
 ExtensionApps::~ExtensionApps() = default;
 
 bool ExtensionApps::Accepts(const extensions::Extension* extension) {
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (extensions::IsExtensionUnsupportedDeprecatedApp(profile(),
                                                       extension->id())) {
     return false;
