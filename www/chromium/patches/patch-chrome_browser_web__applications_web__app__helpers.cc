$NetBSD: patch-chrome_browser_web__applications_web__app__helpers.cc,v 1.14 2026/01/19 16:14:11 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/web_applications/web_app_helpers.cc.orig	2026-01-07 00:50:30.000000000 +0000
+++ chrome/browser/web_applications/web_app_helpers.cc
@@ -145,7 +145,7 @@ bool IsValidWebAppUrl(const GURL& app_ur
     return false;
 
   bool allow_extension_apps = true;
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // Stop allowing apps to be extension urls when the shortcuts are separated -
   // they can be extension urls instead.
   allow_extension_apps = false;
