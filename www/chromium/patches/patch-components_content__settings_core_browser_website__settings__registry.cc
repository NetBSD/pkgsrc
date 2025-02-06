$NetBSD: patch-components_content__settings_core_browser_website__settings__registry.cc,v 1.1 2025/02/06 09:57:58 wiz Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- components/content_settings/core/browser/website_settings_registry.cc.orig	2024-12-17 17:58:49.000000000 +0000
+++ components/content_settings/core/browser/website_settings_registry.cc
@@ -67,7 +67,7 @@ const WebsiteSettingsInfo* WebsiteSettin
 #if BUILDFLAG(IS_WIN)
   if (!(platform & PLATFORM_WINDOWS))
     return nullptr;
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (!(platform & PLATFORM_LINUX))
     return nullptr;
 #elif BUILDFLAG(IS_MAC)
