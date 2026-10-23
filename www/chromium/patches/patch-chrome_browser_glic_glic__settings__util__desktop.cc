$NetBSD: patch-chrome_browser_glic_glic__settings__util__desktop.cc,v 1.10 2026/10/23 15:05:18 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/glic/glic_settings_util_desktop.cc.orig	2026-10-19 20:07:21.000000000 +0000
+++ chrome/browser/glic/glic_settings_util_desktop.cc
@@ -122,7 +122,7 @@ std::string_view GetPlatformHelpSuffix()
   return "_mac";
 #elif BUILDFLAG(IS_CHROMEOS)
   return "_chromeos";
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   return "_linux";
 #else
   return "";
