$NetBSD: patch-components_webapps_browser_web__app__url__config.cc,v 1.1 2026/05/10 15:29:57 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- components/webapps/browser/web_app_url_config.cc.orig	2026-04-28 23:05:57.000000000 +0200
+++ components/webapps/browser/web_app_url_config.cc
@@ -35,7 +35,7 @@ bool IsUrlEligibleForWebApp(const GURL& 
   }
 
   bool allow_extension_apps = true;
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // Stop allowing apps to be extension URLs when the shortcuts are separated -
   // they can be extension URLs instead.
   allow_extension_apps = false;
