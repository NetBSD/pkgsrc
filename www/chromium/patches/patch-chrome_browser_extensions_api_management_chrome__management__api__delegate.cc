$NetBSD: patch-chrome_browser_extensions_api_management_chrome__management__api__delegate.cc,v 1.1 2025/02/06 09:57:47 wiz Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/extensions/api/management/chrome_management_api_delegate.cc.orig	2024-12-17 17:58:49.000000000 +0000
+++ chrome/browser/extensions/api/management/chrome_management_api_delegate.cc
@@ -417,7 +417,7 @@ bool ChromeManagementAPIDelegate::Launch
   apps::LaunchContainer launch_container =
       GetLaunchContainer(extensions::ExtensionPrefs::Get(context), extension);
   Profile* profile = Profile::FromBrowserContext(context);
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (extensions::IsExtensionUnsupportedDeprecatedApp(profile,
                                                       extension->id())) {
     return false;
