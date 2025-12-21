$NetBSD: patch-src_3rdparty_chromium_chrome_browser_extensions_api_management_chrome__management__api__delegate.cc,v 1.1 2025/12/21 09:38:18 markd Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- src/3rdparty/chromium/chrome/browser/extensions/api/management/chrome_management_api_delegate.cc.orig	2025-05-29 01:27:28.000000000 +0000
+++ src/3rdparty/chromium/chrome/browser/extensions/api/management/chrome_management_api_delegate.cc
@@ -417,7 +417,7 @@ bool ChromeManagementAPIDelegate::Launch
   apps::LaunchContainer launch_container =
       GetLaunchContainer(extensions::ExtensionPrefs::Get(context), extension);
   Profile* profile = Profile::FromBrowserContext(context);
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (extensions::IsExtensionUnsupportedDeprecatedApp(profile,
                                                       extension->id())) {
     return false;
